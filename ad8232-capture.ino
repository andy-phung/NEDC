/******************************************************************************
development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Redboard Artemis
  AD8232 Heart Monitor Version: 1.0
******************************************************************************/
#include <Chrono.h>

int timepassed = 0; //is in seconds

void readECG()
{
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else {
    // send the value of analog input 0:
      Serial.println(analogRead(A0));
  }
  
}

void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
}

void loop() {
  Chrono time;
  while (time.hasPassed(5000) == false)
  {
    readECG();
    delay(1); //apparently to prevent serial data saturation?
  }
  timepassed = timepassed + 5;
  Serial.println(" ");
  Serial.println(String(timepassed) + "seconds have passed"); //to check elapsed time
  Serial.println(" ");

}
