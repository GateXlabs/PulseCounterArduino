import smbus
import time
bus = smbus.SMBus(1)
address = 1
count = 0
string=""
def readNumber():
         number2 = bus.read_i2c_block_data(1,0,6)
         return number2


while  True:
        number=readNumber()
        for i in range(len(number)):
            string += chr(number[i])

        count = number
        print(string)
        string = ""
     
