#include <Wire.h>
const int poort1= 6;
const int poort2= 7;
const int poort3= 8;

void setup(){
  pinMode(poort1, OUTPUT);
  pinMode(poort2, OUTPUT);
  pinMode(poort3, OUTPUT);
  Wire.begin();
  Serial.begin(9600);
}
void loop(){
  digitalWrite(poort1, HIGH);
  digitalWrite(poort2, HIGH);
  digitalWrite(poort3, HIGH);
}

  
