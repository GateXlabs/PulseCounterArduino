#include <Wire.h>
int address=1;
String txt[] = "ARD123";

void setup() {
  // put your setup code here, to run once:
     Wire.begin(address);
     Wire.onRequest(sendMessage);
}
void loop() {}

void sendMessage()
{
    Wire.write("ARD123"); 
}

