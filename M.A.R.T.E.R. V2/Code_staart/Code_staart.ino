#include <Wire.h>
const int poort1= 6;
const int poort2= 7;
const int poort3= 8;
const int poort4= 9;
const int poort5= 10;


void setup(){
  pinMode(poort1, OUTPUT);
  pinMode(poort2, OUTPUT);
  pinMode(poort3, OUTPUT);
  pinMode(poort4, OUTPUT);
  pinMode(poort5, OUTPUT);
  Wire.begin();
  Serial.begin(9600);
}
void loop(){
  digitalWrite(poort1, HIGH);
  digitalWrite(poort2, HIGH);
  digitalWrite(poort3, HIGH);
  digitalWrite(poort4, HIGH);
  digitalWrite(poort5, HIGH);
}

  
