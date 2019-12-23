/******************************************************************************
development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Redboard Artemis
  AD8232 Heart Monitor Version: 1.0
******************************************************************************/
int readECG()
{
  delay(1); // Wait for a bit to keep serial data from saturating
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
    return 0;
  }
  else {
    // send the value of analog input 0:
      Serial.println(analogRead(A0));
      return analogRead(A0);
  }
  
}

void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
}

void loop() {

}
