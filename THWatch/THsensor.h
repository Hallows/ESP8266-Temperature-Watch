#ifndef _HDC1080_H__
#define _HDC1080_H__

//导入Arduino核心头文件
#include "Arduino.h"
#include <Wire.h>

class HDC1080
{
     private:
          int SDA_PIN;//SDA 引脚
          int SCL_PIN;//SCL 引脚
     
     
     public:
          
          HDC1080(int SDA,int SCL);   //构造函数
          
          ~HDC1080();          //析构函数

          void init();   //初始化
          
          int readSensor(double* temperature,double* humidity);      //获取传感器数据
};

#endif
