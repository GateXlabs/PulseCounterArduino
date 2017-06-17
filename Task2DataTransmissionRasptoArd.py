import smbus
import time
bus = smbus.SMBus(1)
address = 1
count = 0
string = "RSP123"

def StringToBytes(val):
    retVal = []
    for c in val:
            retVal.append(ord(c))
    return retVal

def writeString(value):
    bus.write_i2c_block_data(1,0,value)
    
while True:
    writeString(StringToBytes(string))
        


