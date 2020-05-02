/*
 * Author: Jason Hillinger
 * Title: Ask Me To Blink
 * This program is the first program written within the SimpleExperiments, that will do communications with the Arduino
 * through the Serial Monitor. It will simply ask the user to how may times to blink an LED, then the LED will blink
 * that many times.
 */


int myPin = 3;            //pin that we will be working with
int amountOfBlinks = 0;
int delTime = 500;        //delay time inbetween blinks
int delTimeAfterBlink = 1000;
String msg = "How many times would you like the LED to blink?";   //prompt message.
void setup() {
pinMode(myPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println(msg);

  while(Serial.available() == 0){
    //waiting for input
  }

amountOfBlinks = Serial.parseInt();     //amountOfBlinks takes the first integer off the stream as its value.

//this loop causes the blinks to occur amountOfBlinks times.
for(int i = 0; i<amountOfBlinks;i++){
  digitalWrite(myPin,HIGH);
  delay(delTime);
  digitalWrite(myPin,LOW);
  delay(delTime);
}
delay(delTimeAfterBlink);     //a brief pause before loop restarts
}
