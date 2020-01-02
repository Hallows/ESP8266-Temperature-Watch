#include"THsensor.h"
#include"Arduino.h"

HDC1080::HDC1080(int SDA,int SCL)
{
  HDC1080::SDA_PIN=SDA;
  HDC1080::SCL_PIN=SCL;
}

HDC1080::~HDC1080()
{
  HDC1080::SDA_PIN=255;
  HDC1080::SCL_PIN=255;
}

void HDC1080::init()
{
  Wire.begin(HDC1080::SDA_PIN, HDC1080::SCL_PIN);
  Wire.beginTransmission(0x40);
  Wire.write(0x02);
  Wire.write(0x90);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(200);
  return;
}

int HDC1080::readSensor(double* temperature,double* humidity)
{
  //holds 2 bytes of data from I2C Line
  uint8_t Byte[4];

  //holds the total contents of the temp register
  uint16_t temp;
  
  //Point to device 0x40 (Address for HDC1080)
  Wire.beginTransmission(0x40);
  //Point to register 0x00 (Temperature Register)
  Wire.write(0x00);
  //Relinquish master control of I2C line
  //pointing to the temp register triggers a conversion
  Wire.endTransmission();
  
  //delay to allow for sufficient conversion time
  delay(20);
  
  //Request four bytes from registers
  Wire.requestFrom(0x40, 4);

  delay(1);
  
  //If the 4 bytes were returned sucessfully
  if (4 <= Wire.available())
  {
    //take reading
    //Byte[0] holds upper byte of temp reading
    Byte[0] = Wire.read();
    //Byte[1] holds lower byte of temp reading
    Byte[1] = Wire.read();
    
    //Byte[3] holds upper byte of humidity reading
    Byte[3] = Wire.read();
    //Byte[4] holds lower byte of humidity reading
    Byte[4] = Wire.read();

    //Combine the two bytes to make one 16 bit int
    temp = (((unsigned int)Byte[0] <<8 | Byte[1]));

    //Temp(C) = reading/(2^16)*165(C) - 40(C)
    *temperature = (double)(temp)/(65536)*165-40;

   //Combine the two bytes to make one 16 bit int
    *humidity = (((unsigned int)Byte[3] <<8 | Byte[4]));
    *humidity = (*humidity)/(65536)*100;
    //Humidity(%) = reading/(2^16)*100%
    return 200;
  }
}
