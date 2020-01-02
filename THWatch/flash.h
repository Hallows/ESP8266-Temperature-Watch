#ifndef _flash_H__
#define _flash_H__

#include <EEPROM.h>
#include <U8g2lib.h>

class flash
{
  private:
    int flagAdd;
    int ssidAdd;
    int passAdd;
    int locaAdd;
    
  public:
    int hasConfig;    //是否已有配置文件
    char ssid[64];       //Wifi名称
    char passwd[64];     //Wifi密码
    char location[11];    //地区代码

  public:
    flash();   //~构造函数
    ~flash();  //析构函数
    bool saveSetting(char* ssidin,char* passwdin,char* locationin); //保存配置
    bool getSetting(void);
    
};

#endif
