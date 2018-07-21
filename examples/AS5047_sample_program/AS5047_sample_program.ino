#include "AS5047.h"
#include <SPI.h>

AS5047 myAS5047(5); // SS pin

void setup()
{
  SPI.begin;
  Serial.begin(9600);
}

void loop()
{
  long value;
  value=myAS5047.sensor_read();
  Serial.print("measured value: ");
  Serial.println(value);
  value = myAS5047.error_read();
  Serial.print("error value: ");
  Serial.println(value);
  value=myAS5047.align_and_agc_read();
  Serial.print("alignment info: ");
  Serial.println(value);
  delay(2000);
}
