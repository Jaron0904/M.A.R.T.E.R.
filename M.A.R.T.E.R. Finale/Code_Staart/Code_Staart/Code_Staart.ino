#include <Wire.h>
#include <SeeedGrayOLED.h>

const int poort1= 4;
const int poort2= 6;
const int poort3= 8;


int aantalkabels=0;
int statuspoort1=0;
int statuspoort2=0;
int statuspoort3=0;


int controleplaats=1;
int prevStatus=6;


void setup(){
  pinMode(poort1, INPUT);
  pinMode(poort2, INPUT);
  pinMode(poort3, INPUT);

  Wire.begin();
  Serial.begin(9600);

  SeeedGrayOled.init(SH1107G);
  SeeedGrayOled.setInverseDisplay();
  SeeedGrayOled.clearDisplay();
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
      SeeedGrayOled.clearDisplay();     
    if (aantalkabels==0) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("0");
      SeeedGrayOled.setTextXY(10,14);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("gevonden kabels");
    }
    if (aantalkabels==1) {
      SeeedGrayOled.setTextXY(6.5,3.5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er is");
      SeeedGrayOled.setTextXY(8,5.5);
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
      SeeedGrayOled.setTextXY(10,14);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("gevonden kabels");
    }
    if (aantalkabels==3) {
      SeeedGrayOled.setTextXY(6.5,2);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("Er zijn");
      SeeedGrayOled.setTextXY(8,5);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("3");
      SeeedGrayOled.setTextXY(10,14);
      SeeedGrayOled.setGrayLevel(15);
      SeeedGrayOled.putString("gevonden kabels");
    }
    }
    delay(500);
  }


