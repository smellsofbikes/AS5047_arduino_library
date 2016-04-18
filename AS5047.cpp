#include "Arduino.h"
#include "as5047.h"

AS5047::AS5047(uint16_t SelectPin) 
         : _ss(SelectPin)
{
        pinMode(_pin, INPUT);
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

uint32_t AS5047::read_register(uint32_t register)
{
"as5047V2.cpp" 53 lines, 1350 characters written
