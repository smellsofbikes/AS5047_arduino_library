#include "Arduino.h"
#include "AS5047.h"
#include <SPI.h>

AS5047::AS5047(uint16_t SelectPin)
         : _ss(SelectPin)
{
        SPI.begin();
        pinMode(_ss, INPUT);
}

uint32_t AS5047::sensor_read(void)
{
        uint32_t sensor_register_number = 0xFFFF;
        return(read_register(sensor_register_number));
}

uint32_t AS5047::error_read(void)
{
        uint32_t err_register_number = 0x4001;
        return(read_register(err_register_number));
}

uint32_t AS5047::align_and_agc_read(void)
{
        uint32_t align_register_number = 0xFFFC;
        return(read_register(align_register_number));
}

uint32_t AS5047::read_register(uint32_t thisRegister)
{
        byte inByte = 0;   // incoming byte from the SPI
        long result = 0;   // result to return
        byte lowbyte = thisRegister & 0b0000000011111111;
        byte highbyte = (thisRegister >> 8);
        digitalWrite(_ss, LOW);
        SPI.transfer(highbyte); // first byte in
        result = SPI.transfer(lowbyte); // first byte out
        digitalWrite(_ss, HIGH);
        delayMicroseconds(10);
        digitalWrite(_ss, LOW);
        int bytesToRead = 2;
        while (bytesToRead-- > 0) {
                // shift the first byte left, then get the second byte:
                result = result << 8;
                inByte = SPI.transfer(0x00);
                // combine the byte with the previous one:
                result = result | inByte;
        }
        // take the chip select high to de-select:
        digitalWrite(_ss, HIGH);
        result = result & 0b0011111111111111;
        return(result);
}
