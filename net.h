#ifndef _net_H__
#define _net_H__

#include <ESP8266WiFi.h>


extern char* ssid;
extern char* password;

void netInit(void);
void getWeather(void);

#endif
