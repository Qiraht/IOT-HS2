#include <Blynk.h>

#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
float Vo, Vi, R1, R2, adc;

// initialize the library with the numbers of the interfacepins

float value = 0;
float rev = 0;

float arus, kec, teg ;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
// constants won't change:
const long interval = 1000;

char ssid[] = "Wifi gratis";
char pass[] = "masihyangdulu";
char auth[] = "yMmVfhjtrHLnq8RfUleAlddPXv89HwIb";

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  
  Serial.begin(9600);
  R1 = 100000.0;
  R2 = 4700.0;

}


void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();
 
    //unsigned long currentMillis = millis();
    if (currentMillis - previousMillis1 >= interval) {
      // save the last time you blinked the LED
      previousMillis1 = currentMillis;
      adc = analogRead(A0);
      Vo = (adc * 4.8) / 1024.0;
      Vi = Vo / (R2 / (R1 + R2));
      if (Vi < 0.09) {
        Vi = 0.0;
      }
      //Vi =adc*0.06-14;
      //if(adc<=0){Vi=0;}
      
      Blynk.virtualWrite(V3, Vi);
 
      Serial.print("Vi=");
      Serial.print(Vi);
      Serial.println("V");
      //delay(500);
    }
  
 
    //sensor arus DC
    if (currentMillis - previousMillis2 >= interval) {
      // save the last time you blinked the LED
      previousMillis2 = currentMillis;
      float byts = analogRead(A0);
      float volts = (byts / 1023) * 5;
      float arus = (2.50 - volts) / 0.100;
  
      Blynk.virtualWrite(V1, arus);
      //delay(1);
     
      Serial.print("Arus =");
      Serial.print(arus);
      Serial.println(" mA");
      //delay(500);
    }
 
  
}