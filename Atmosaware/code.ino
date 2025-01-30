#define BLYNK_TEMPLATE_ID "TMPL3ppFS6u8p" 
#define BLYNK_TEMPLATE_NAME "Weather Monitoring"
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include<BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <stdlib.h> 
LiquidCrystal_I2C lcd (0x27, 16,2);
DHT dht(D3, DHT11); 
 BlynkTimer timer;
char auth[] = ""; 
Blynkchar ssid[] = ""; //Enter your WIFI Name
char pass[] = ""; //Enter your WIFI Passwordvoid weather()
{
float h,t;
 h=dht.readHumidity();
 t=dht.readTemperature(); 
int r =analogRead(A0);
 Serial.println(r);
bool l;
l=digitalRead(D4);
if (isnan(h) || isnan(t))
{
Serial.println("Failed to read from DHT sensor!");
return;
}
 
Blynk.virtualWrite(V0, t); 
Blynk.virtualWrite(V1, h);
Blynk.virtualWrite(V2, r); 
if (l == 0)
{
WidgetLED led1(V4);
 led1.on();
 lcd.setCursor(9, 1);
 lcd.print("L:");
lcd.print("High");
lcd.print(" ");
}
else if (l == 1)
{
WidgetLED led1(V4);
led1.off(); 
lcd.setCursor(9, 1); 
lcd.print("L :");
lcd.print("Low");
lcd.print(" ");
}
lcd.setCursor(0, 0);
lcd.print("T :"); 
lcd.print(t); 
lcd.setCursor(0, 1);
lcd.print("H:"); 
lcd.print(h);
 lcd.setCursor(90);
lcd.print("R:");
 lcd.print(r);
lcd.print(" ");
}
void setup()
{
Serial.begin(115200);
 lcd.init();
lcd.backlight();
 Blynk.begin(auth, ssid, pass); 
dht.begin(); 
timer.setInterval(10L, weather);
}
void loop()
{
Blynk.run(); 
 timer.run();
SimpleTimer
}