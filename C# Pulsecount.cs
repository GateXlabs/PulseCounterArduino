
//Library used is at https://github.com/cody82/QuadroschrauberSharp/blob/master/QuadroschrauberSharp.Linux/I2CLinux.cs
//http://blog.mshmelev.com/2013/06/connecting-raspberry-pi-and-arduino-software.html
using System;
namespace PulseCounter
{

    static void Main(string[] args)
    {
        using (var i2cBus = new I2CBus(0x01)) //address is 1
        {
            var i2cDevice = new I2CDevice(i2cBus, 0x01);
            var bytes = new byte[7];
            i2cDevice.ReadBytes(0x01, 7, bytes);
            string count = "";
            count = bytes[0].ToString + bytes[1].ToString + bytes[2].ToString + bytes[3].ToString + bytes[4].ToString + bytes[5].ToString + bytes[6].ToString;
            Console.Write("Pulse Count: ");
            Console.WriteLine(count);
            string count = "";
        }
    }

}