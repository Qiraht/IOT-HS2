#include <Blynk.h>

#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal.h>
#include <string.h>
#define BLYNK_PRINT Serial

const int currentpin = A0;
int sensitivity = 66;
int adcvalue = 0;
int offsetvoltage = 2500;
double adcvoltage = 0;
double currentvalue = 0;
char ssid[] = "Alba Jogja";
char pass[] = "albasyariyah";
char auth[] = "yMmVfhjtrHLnq8RfUleAlddPXv89HwIb";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
adcvalue= analogRead(currentpin);
adcvoltage = (adcvalue / 1024.0) *5000;
currentvalue = ((adcvoltage - offsetvoltage) / sensitivity);

 Blynk.virtualWrite(V1, currentvalue);
 Serial.print("Arus =");
 Serial.print(currentvalue);
 Serial.println(" mA");

  Serial.print("raw senseor = ");
 Serial.println(adcvalue);

 
}
