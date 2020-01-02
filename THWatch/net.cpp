#include "net.h"

void netInit()
{
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
Serial.println("WiFi connected");
}

void getWeather(void)
{
  
}
