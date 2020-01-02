#include <U8g2lib.h>
#include "THsensor.h"
#include "net.h"
#include "flash.h"

#define SDA_PIN 2
#define SCL_PIN 14

U8G2_SSD1306_128X64_NONAME_1_HW_I2C lcd(U8G2_R0,U8X8_PIN_NONE,SCL_PIN,SDA_PIN);
HDC1080 sensor(SDA_PIN,SCL_PIN);
flash flash;

char* ssid = "hys402";
char* password = "19631963";
char* location="CN101220301";

void setup(){
  Serial.begin(115200);
  //Configure HDC1080
  sensor.init();
  lcd.begin();
  netInit();
  Serial.println(WiFi.localIP());
  if(flash.hasConfig==1)
  {
    Serial.println("get Config!");
    flash.getSetting();
    Serial.println(flash.ssid);
    Serial.println(flash.passwd);
    Serial.println(flash.location);
  }
  else
  {
    Serial.println("Not find Config!");
    flash.saveSetting(ssid,password,location);
    Serial.println("config saved!");
  }
  
}

void loop() {
  char line1[16];
  char line2[16];
  char line3[20];
  double temperature;
  double humidity;
  delay(1000);
  sensor.readSensor(&temperature,&humidity);
  Serial.println();
  sprintf(line1,"Tem: %d",(int)temperature);
  sprintf(line2,"Hum: %d",(int)humidity);
  Serial.println(line1);
  Serial.println(line2);
  lcd.firstPage();
  do {
    lcd.setFont(u8g2_font_t0_11b_tf);
    lcd.drawStr(0,8,line1);
    lcd.drawStr(0,17,line2);
    lcd.setCursor(0, 26);
    lcd.print(WiFi.localIP());
  } while ( lcd.nextPage() );
}
