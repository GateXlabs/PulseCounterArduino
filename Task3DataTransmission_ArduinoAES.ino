#include <AESLib.h>
#include <Wire.h>
int address=1;
char data[] = "ARD123"; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
Wire.begin(address);
Wire.onRequest(sendMessage);
Serial.begin(57600);
uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//16 chars == 16 bytes
aes128_enc_single(key, data);
Serial.print("encrypted:");
Serial.println(data);
aes128_dec_single(key, data);
Serial.print("decrypted:");
Serial.println(data);

}

void loop() {}

void sendMessage(){
  Wire.write(data);
 
}