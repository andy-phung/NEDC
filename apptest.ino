#include <SoftwareSerial.h>
#include <string> 

SoftwareSerial BLE(1,0);
int red_light_pin= 7;
int green_light_pin = 6;
int blue_light_pin = 5;

#include "functions.h"
int count = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
  setupBleConnection();
  RGB_Color(0, 255, 255);
}

void loop() {
  Serial.println(readECG());
  BLE.print(readECG());
  delay(50);
  count++;
  if (count == 40){
    BLE.print("i"); 
    BLE.print(analogRead(1));
    count = 0;
  }
}
