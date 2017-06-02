#define MainPeriod 100  // measurement frame, milliseconds
#define f_input_pin 2   // input pin for pulseIn

long previousMillis = 0;
unsigned long duration=0; // receive pulse width
long pulsecount=0;

void setup() 
{
  pinMode(f_input_pin, INPUT);
  Serial.begin(19200);
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
    float Freq=0.5e6/float(duration); // assume pulse duty cycle 0.5
    Freq*=pulsecount;
    Serial.print(Freq);
    Serial.print(" "); 
    Serial.print(pulsecount/10);
    Serial.print(" ");
    Serial.println(duration);
    duration=0;
    //pulsecount=0;
  }
  // instead of single measurement per cycle - accumulate and average
  duration += pulseIn(f_input_pin, HIGH, MainPeriod*1000);
  pulsecount++;
}
