import smbus
import time
bus = smbus.SMBus(1)
address = 0x04
count = 0
string=""

def readNumber():
         number2 = bus.read_i2c_block_data(4,0,7)
         return number2

while  True:
        number=readNumber()
        string=str(number[0]) + str(number[1]) + str(number[2]) + str(number[3]) + str(number[4])+ str(number[5]) +str(number[6])

        print(string)
        print("")
        