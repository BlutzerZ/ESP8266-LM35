#define BLYNK_TEMPLATE_ID "TEMPLATE_ID" //Your Template ID
#define BLYNK_DEVICE_NAME "DEVICE_NAME" //Your Device Name from Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;


char auth[] = "Auth_TOKEN"; //Your Auth Token
char ssid[] = "vivo";
char pass[] = "";

void myTimeEvent() {
  int raw = analogRead(A0);
  float millivolts = (raw/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  //Blynk.virtualWrite(V1, adc);
  Blynk.virtualWrite(V2, celsius);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimeEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}
