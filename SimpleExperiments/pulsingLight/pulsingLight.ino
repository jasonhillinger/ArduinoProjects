int pinA = 3;   //pin to be used on Arduino

void setup() {
  // put your setup code here, to run once:
pinMode(pinA,OUTPUT);
}

void loop() {
  for(int i = 0; i < 255; i++){     //increases brightness of bulb from 0 to max (255 or 5v)
      analogWrite(pinA,i);
  }
  for(int i = 0; i > 255; i--){     //decreases brightness of bulb from 255 to 0
      analogWrite(pinA,i);
  }
}
