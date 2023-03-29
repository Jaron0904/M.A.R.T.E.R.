#include <Wire.h>
#include <SeeedGrayOLED.h>
//schakeling knoppen
const int OK = 5;
const int Return=6;
const int LEFT=7;
const int RIGHT=8;

//knoppen declareren
int OKstate = 0;
int prevOKstate = 0;
int OKstateint=0;
int Returnstate=0;
int prevReturnstate=0;
int Returnstateint=0;
int Leftstate=0;
int prevLeftstate=0;
int Leftstateint=0;
int Rightstate=0;
int prevRightstate=0;
int Rightstateint=0;

//controleLEDs
const int LEDblauw=4;
const int LED = 3;

//aantal kabels
int aantalkabels=3;

void setup() {
pinMode(LED, OUTPUT);
pinMode(LEDblauw, OUTPUT);
pinMode(OK, INPUT);
Wire.begin();
Serial.begin(9600);

SeeedGrayOled.init(SH1107G);
SeeedGrayOled.setInverseDisplay();
SeeedGrayOled.clearDisplay();
SeeedGrayOled.setVerticalMode();
SeeedGrayOled.setTextXY(7.5, 0);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("M.A.R.T.E.R.");
delay(100);
SeeedGrayOled.clearDisplay();

}

void loop() {
SeeedGrayOled.clearDisplay();

OKstate = digitalRead(OK);
if ((OKstate == HIGH) || (OKstateint == 1)) {
SeeedGrayOled.clearDisplay();
OKstateint=1;
while (OKstateint==1) {
Returnstate=digitalRead(Return);
if (Returnstate==HIGH) {
OKstateint=0;
}
else{
Leftstate=digitalRead(LEFT);
Rightstate=digitalRead(RIGHT);

if (aantalkabels==2) {
SeeedGrayOled.clearDisplay();
while ((aantalkabels==2)&& (OKstateint==1)){
Leftstate=digitalRead(LEFT);
Rightstate=digitalRead(RIGHT);
Returnstate=digitalRead(Return);
SeeedGrayOled.setTextXY(1, 0);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("Aantal kabels");
SeeedGrayOled.setTextXY(7, 5);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("2");
if ((Leftstate==HIGH) && (aantalkabels>2)) {
aantalkabels= aantalkabels-1;
delay(100);
}
else if ((Rightstate==HIGH) && (aantalkabels<5)) {
aantalkabels= aantalkabels+1;
delay(100);
}
else if (Returnstate== HIGH){
OKstateint=0;
}
}
}
else if (aantalkabels==4) {
SeeedGrayOled.clearDisplay();
while ((aantalkabels==4)&& (OKstateint==1)) {
Leftstate=digitalRead(LEFT);
Rightstate=digitalRead(RIGHT);
Returnstate=digitalRead(Return);
SeeedGrayOled.setTextXY(1, 0);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("Aantal kabels");
SeeedGrayOled.setTextXY(7,5);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("4");
if ((Leftstate==HIGH) && (aantalkabels>2)) {
aantalkabels= aantalkabels-1;
delay(100);
}
else if ((Rightstate==HIGH) && (aantalkabels<5)) {
aantalkabels= aantalkabels+1;
delay(100);
}
else if (Returnstate== HIGH){
OKstateint=0;
}
}
}
else if (aantalkabels==5) {
SeeedGrayOled.clearDisplay();
while ((aantalkabels==5)&&(OKstateint==1)) {
Leftstate=digitalRead(LEFT);
Rightstate=digitalRead(RIGHT);
Returnstate=digitalRead(Return);
SeeedGrayOled.setTextXY(1, 0);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("Aantal kabels");
SeeedGrayOled.setTextXY(7,5);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("5");
if ((Leftstate==HIGH) && (aantalkabels>2)) {
aantalkabels= aantalkabels-1;
delay(100);
}
else if ((Rightstate==HIGH) && (aantalkabels<5)) {
aantalkabels= aantalkabels+1;
delay(100);
}
else if (Returnstate== HIGH){
OKstateint=0;
}
}
}
else {
SeeedGrayOled.clearDisplay();
while ((aantalkabels ==3)&&(OKstateint==1)) {
Leftstate=digitalRead(LEFT);
Rightstate=digitalRead(RIGHT);
Returnstate=digitalRead(Return);
SeeedGrayOled.setTextXY(1, 0);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("Aantal kabels");
SeeedGrayOled.setTextXY(7,5);
SeeedGrayOled.setGrayLevel(15);
SeeedGrayOled.putString("3");
if ((Leftstate==HIGH) && (aantalkabels>2)) {
aantalkabels= aantalkabels-1;
delay(100);
}
else if ((Rightstate==HIGH) && (aantalkabels<5)) {
aantalkabels= aantalkabels+1;
delay(100);
}
else if (Returnstate== HIGH){
OKstateint=0;
}
}
}
digitalWrite(LED, HIGH);
digitalWrite(LEDblauw, LOW);
}
}
}
else {
SeeedGrayOled.clearDisplay();
while (OKstateint==0) {
OKstate = digitalRead(OK);
if (OKstate==HIGH) {
OKstateint=1;
}
SeeedGrayOled.setTextXY(3, 0);
SeeedGrayOled.putString("Kabeltester");
digitalWrite(LED, LOW);
digitalWrite(LEDblauw, HIGH);
 }
}
}