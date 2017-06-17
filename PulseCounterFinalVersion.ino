/*
 Name:    PulseCounterV2.ino
 Created: 6/6/2017 2:52:03 PM
 Author:  Moataz
*/
#include <LiquidCrystal.h>
#include <Wire.h>
#include <I2C_Anything.h>
#define SLAVE_ADDRESS 0x04
#define MainPeriod 100
const int buttonPin = 8;
int buttonState = 0;
long var = 0; 
byte ones = 0, tens = 0, hundreds = 0, thousands = 0, tenthousand =0, hundredthousand = 0, million = 0;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
long previousMillis = 0; // will store last time of the cycle end
volatile unsigned long duration = 0; // accumulates pulse width
volatile unsigned long pulsecount = 0;
volatile unsigned long pulsecount2 = 0;
volatile unsigned long previousMicros = 0;



// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(19200);
  Wire.begin(SLAVE_ADDRESS);
  attachInterrupt(0, myinthandler, RISING);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, LOW);
  lcd.begin(16, 2);
  Wire.onRequest(sendData);
}

// the loop function runs over and over again until power down or reset
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= MainPeriod)
  {
    previousMillis = currentMillis;
    // need to bufferize to avoid glitches
    unsigned long _duration = duration;
    unsigned long _pulsecount = pulsecount;
    duration = 0; // clear counters
    pulsecount = 0;
    float Freq = 1e6 / float(_duration);
    Freq *= _pulsecount; // calculate F
               // output time and frequency data to RS232
    Serial.print(currentMillis);
    Serial.print(" "); // separator!
    Serial.print(Freq);
    Serial.print(" ");
    Serial.print(pulsecount2/10);
    Serial.print(" ");
    Serial.println(_duration);
    lcd.setCursor(0, 0);
    lcd.print("Pulse Cnt:");
    lcd.print(pulsecount2/10);
    lcd.setCursor(0, 1);
    lcd.print("Freq:");
    lcd.print(Freq);
    lcd.print(" Hz");
    
  }
   buttonState  = digitalRead(buttonPin);
  if ( buttonState == HIGH ) //This button will reset the display of the pulse counter on both the LCD and the Serial Monitor 
  {
    pulsecount=0;
    pulsecount2=0;
    lcd.clear();
  }


}


void myinthandler() // interrupt handler .. This interupt will be called everytime the pulse is rising and the counter will be incremented
{
  unsigned long currentMicros = micros();
  duration += currentMicros - previousMicros; //the duration is measured in order to calculate the frequency
  previousMicros = currentMicros;
  pulsecount++;
  pulsecount2++;
  var = pulsecount2/10;
  ones=(var%10);
  tens=((var/10)%10);
  hundreds=((var/100)%10);
  thousands=((var/1000)%10);
  tenthousand=((var/10000)%10);
  hundredthousand=((var/100000)%10);
  million=((var/1000000)%10);
 
}

void sendData()
{
   I2C_writeAnything(million);
   I2C_writeAnything(hundredthousand);
   I2C_writeAnything(tenthousand);
   I2C_writeAnything(thousands);
   I2C_writeAnything(hundreds);
   I2C_writeAnything(tens);
   I2C_writeAnything(ones);
   
}

