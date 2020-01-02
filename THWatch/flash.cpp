#include "flash.h"

flash::flash()
{
  flash::flagAdd=1;
  flash::ssidAdd=2;
  flash::passAdd=66;
  flash::locaAdd=130;

  EEPROM.begin(256);
  flash::hasConfig=EEPROM.read(flagAdd);
} 

flash::~flash()
{
}


bool flash::saveSetting(char* ssidin,char* passwdin,char* locationin) //保存Wifi配置
{
  char Srt=ssidin;
  Str+="@"
  Str+=passwdin;
  Str+="@"
  Str+=location;
  Serial.println(Str);
  EEPROM.write(1,1);
  for(int address=2;address<200;address++)
  {
    EEPROM.write(address,Str)
  }
  
  EEPROM.commit();
  return true;
}

bool flash::getSetting(void)
{
  int temp=0;
  for (int i = flash::ssidAdd; i < 64; ++i)
  {
    flash::ssid[temp]=EEPROM.read(i);
    temp++;
  }
  temp=0;
  for (int i = flash::passAdd; i < 64; ++i)
  {
    flash::passwd[temp]=EEPROM.read(i);
    temp++;
  }
  temp=0;
  for (int i = flash::ssidAdd; i < 64; ++i)
  {
    flash::location[temp]=EEPROM.read(i);
    temp++;
  }
  temp=0;
  return true;
}
