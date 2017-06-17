#include <Wire.h>
int address=1;
String txt = "";

void setup() {
  // put your setup code here, to run once:
     Wire.begin(address);
     Serial.begin(9600);
     Wire.onReceive(receiveData);
}
void loop() {}

void receiveData()
{
    while (Wire.available()) { 
    txt+=(char)Wire.read();
    Serial.print(txt);
    txt="";
    } 
    Serial.println();
}
