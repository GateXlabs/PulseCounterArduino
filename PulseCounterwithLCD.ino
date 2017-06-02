#define MainPeriod 100  // measurement frame, milliseconds
#define f_input_pin 2   // input pin for pulseIn
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
long previousMillis = 0;
unsigned long duration=0; // receive pulse width
long pulsecount=0;
const int buttonpin = 8;
int buttonstate = 0;

void setup() 
{
  pinMode(f_input_pin, INPUT);
  pinMode(buttonpin,INPUT);
  digitalWrite(buttonpin,LOW);
  Serial.begin(19200);
  lcd.begin(16, 2);
   
}


void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= MainPeriod) 
  {
    previousMillis = currentMillis;   
    // write current time and F values to the serial port
    Serial.print(currentMillis);
    Serial.print(" "); // separator!
  // assume pulse duty cycle 0.5
    float Freq=1e6/float(duration);
     Serial.print(Freq);
    Serial.print(" "); 
    Serial.print(pulsecount/10);
    Serial.print(" ");
    Serial.println(duration);
    lcd.setCursor(0,0);
    lcd.print("Pulse Cnt:");
    lcd.print(pulsecount/10);
    lcd.setCursor(0,1);
    lcd.print("Freq:");
    lcd.print(Freq);
 lcd.print(" Hz");
    duration=0;
    //pulsecount=0;
  }
  
  // print the number of seconds since reset: 
  // instead of single measurement per cycle - accumulate and average
  duration += pulseIn(f_input_pin, HIGH, MainPeriod*1000);
  pulsecount++;
 
   buttonstate  = digitalRead(buttonpin);
  if ( buttonstate == HIGH )
  {
    pulsecount=0;
  }
}
