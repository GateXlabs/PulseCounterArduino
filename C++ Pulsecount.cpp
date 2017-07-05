#include <iostream>
#include <string>
#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>
int address = 0x01;
unsigned int buffer[60] = { 0 };
string pulsecount = "";
length = 64; //number of bytes to read
using namespace std;

void main() {
	read(address, buffer, length);
	printf("Pulse Count: %d\n", buffer);
}


