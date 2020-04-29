/*
 * Author: Jason Hillinger
 * Title: Pulsing Lights
 * This piece of code uses Pulse-width modulation to creat a pulse effect on an LED
 * The lights will mimic xmas ligths, even more so if you use green, red and blue LEDs!
 */

int pinA = 3;   //pin to be used on Arduino
int wait = 5;   //how fast the light reappears and fades away.
int inBetweenWait = 100;  //delay in between each pulse
void setup() {
  // put your setup code here, to run once:
pinMode(pinA,OUTPUT);
}

void loop() {
  for(int i = 0; i < 255; i++){     //increases brightness of bulb from 0 to max (255 or 5v)
      analogWrite(pinA,i);
      delay(wait);
  }

  delay(inBetweenWait);

  for(int i = 255; i > 0; i--){     //decreases brightness of bulb from 255 to 0
      analogWrite(pinA,i);
            delay(wait);

  }

  delay(inBetweenWait);

}
