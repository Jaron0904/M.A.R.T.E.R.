#include <Wire.h>

const int poort1= 4;
const int poort2= 6;
const int poort3= 8;
const int poort4= 10;
const int poort5= 12;

const int led1= 11;
const int led2= 9;
const int led3= 7;
const int led4= 5;
const int led5= 3;

int aantalkabels=0;
int statuspoort1=0;
int statuspoort2=0;
int statuspoort3=0;
int statuspoort4=0;
int statuspoort5=0;

int controleplaats=1;
int prevStatus=6;

void setup(){
  pinMode(poort1, INPUT);
  pinMode(poort2, INPUT);
  pinMode(poort3, INPUT);
  pinMode(poort4, INPUT);
  pinMode(poort5, INPUT);
  Wire.begin();
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void loop(){
  statuspoort1=digitalRead(poort1);
  statuspoort2=digitalRead(poort2);
  statuspoort3=digitalRead(poort3);
  statuspoort4=digitalRead(poort4);
  statuspoort5=digitalRead(poort5);
  aantalkabels=0;
  if ((statuspoort1==HIGH)&&(controleplaats==1))  {
    aantalkabels=aantalkabels+1;
  }
    controleplaats=controleplaats+1;
  if ((statuspoort2==HIGH)&&(controleplaats==2)){
      aantalkabels=aantalkabels+1; 
  }
    controleplaats=controleplaats+1;
  if ((statuspoort3==HIGH)&&(controleplaats==3)){
      aantalkabels=aantalkabels+1; 
  }
    controleplaats=controleplaats+1;
  if ((statuspoort4==HIGH)&&(controleplaats==4)){
      aantalkabels=aantalkabels+1; 
  }
    controleplaats=controleplaats+1;
  if ((statuspoort5==HIGH)&&(controleplaats==5)){
      aantalkabels=aantalkabels+1; 
  }
  controleplaats=1;
  Serial.print("controleplaats is " );
  Serial.print(controleplaats);
  Serial.print('\n');
  Serial.print("aantal kabels gevonden is ");
  Serial.print(aantalkabels);
  Serial.print('\n');
  if (prevStatus!=aantalkabels) {
      controleplaats=1;
      prevStatus=aantalkabels;   
    if (aantalkabels==0) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
    if (aantalkabels==1) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
    if (aantalkabels==2) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
    if (aantalkabels==3) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
    if (aantalkabels==4) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
    }
    if (aantalkabels==5) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);      
    } 
    }
  }


