/*
 * Author: Jason Hillinger
 * Title: xMas Lights
 * This piece of code alternates between 3 LED lights and illuminates one of them at a time.
 * The lights will mimic xmas ligths, even more so if you use green, red and blue LEDs!
 */

int lightA = 3;     //pin numbers for each light
int lightB = 5;
int lightC = 7;
int wait = 500;     //wait time for inbetween each light

//This function turns on one led and turns off two leds while incorperating a delay time.
void turnOnOffOff(int ONLED, int OFFLED, int OFFLED1, int waitTime){
  digitalWrite(ONLED,HIGH);       //turns on this LED
  digitalWrite(OFFLED,LOW);       //turns off this LED
  digitalWrite(OFFLED1,LOW);      //turns off this LED
  delay(waitTime);                //delay waitTime amount of miliseconds
}

void setup() {
  //every pinMode is set to output since we are we are illuminating the lights.
  pinMode(lightA,OUTPUT);
  pinMode(lightB,OUTPUT);
  pinMode(lightC,OUTPUT);
}

void loop() {
turnOnOffOff(lightA,lightB,lightC,wait);
turnOnOffOff(lightB,lightA,lightC,wait);
turnOnOffOff(lightC,lightB,lightA,wait);
}
