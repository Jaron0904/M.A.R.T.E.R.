#include <Wire.h>
#include <SeeedGrayOLED.h>

const int poort1= 4;
const int poort2= 6;
const int poort3= 8;
const int poort4= 10;
const int poort5= 12;
const int knopherstarten= 3;

int aantalkabels=0;
int statuspoort1=0;
int statuspoort2=0;
int statuspoort3=0;
int statuspoort4=0;
int statuspoort5=0;
int statusherstarten=0;

int controleplaats=1;





void setup(){
  pinMode(poort1, INPUT);
  pinMode(poort2, INPUT);
  pinMode(poort3, INPUT);
  pinMode(poort4, INPUT);
  pinMode(poort5, INPUT);
  pinMode(knopherstarten, INPUT);
  Wire.begin();
  Serial.begin(9600);

  SeeedGrayOled.init(SH1107G);
  SeeedGrayOled.setInverseDisplay();
  SeeedGrayOled.clearDisplay();
  SeeedGrayOled.setVerticalMode();
  SeeedGrayOled.setTextXY(7, 0);
  SeeedGrayOled.setGrayLevel(15);
  SeeedGrayOled.putString("M.A.R.T.E.R.");
  delay(500);
  SeeedGrayOled.clearDisplay();
}
void loop(){
  statuspoort1=digitalRead(poort1);
  statuspoort2=digitalRead(poort2);
  statuspoort3=digitalRead(poort3);
  statuspoort4=digitalRead(poort4);
  statuspoort5=digitalRead(poort5);
  SeeedGrayOled.clearDisplay();

  statusherstarten=LOW;
  while ((controleplaats<=5)&&(statusherstarten==LOW)) {
    statuspoort1=digitalRead(poort1);
    statuspoort2=digitalRead(poort2);
    statuspoort3=digitalRead(poort3);
    statuspoort4=digitalRead(poort4);
    statuspoort5=digitalRead(poort5);
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
    controleplaats=controleplaats+1;
  }
  while (statusherstarten==LOW) {
    statusherstarten=digitalRead(knopherstarten);  
    Serial.print("controleplaats is " );
    Serial.print(controleplaats);
    Serial.print('\n');
    Serial.print("aantal kabels gevonden is ");
    Serial.print(aantalkabels);
    Serial.print('\n');
    if (aantalkabels==0) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("0");
      SeeedGrayOled.setTextXY(10,-15);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabels gevonden");
    }
    if (aantalkabels==1) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er is");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("1");
      SeeedGrayOled.setTextXY(10,0);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabel gevonden");
    }
    if (aantalkabels==2) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("2");
      SeeedGrayOled.setTextXY(10,-1);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabels gevonden");
    }
    if (aantalkabels==3) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("3");
      SeeedGrayOled.setTextXY(10,-1);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabels gevonden");
    }
    if (aantalkabels==4) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("4");
      SeeedGrayOled.setTextXY(10,-1);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabels gevonden");
    }
    if (aantalkabels==5) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("5");
      SeeedGrayOled.setTextXY(10,-1);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("kabels gevonden");
    }
    if (statusherstarten==HIGH) {
      controleplaats=1;
      aantalkabels=0;
      statusherstarten=HIGH;      
    }
  }
}

