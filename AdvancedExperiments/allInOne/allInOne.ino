//The idea behind this experiment was to incorporate as many things that I learnt within the Arduino world into one project.
//This is made to measure a distance with the use of a HC-SR04, but one a push button is pressed (on the breadboard), the
//function of the Arduino switches to measuring the humidity and temperature. The results are shown through the LCD attached
//to the Arduino. As a bonus this also plots the information being recorded in real time through the Arduino Serial
//plotter (CTRL+SHIFT+L).


#include "LiquidCrystal.h"
#include "DHT.h"
#define Type DHT11

//Switch Variables//
int switchPin = 5;
int presentState = 1;

//HC-SR04 Variables//
int trigPin=3;
int echoPin=4;
long duration, cm;

//DHT Variables//
int dhtPin=2;
double humidity, temp;

//Object creation//
LiquidCrystal lcd(7,8,9,10,11,12);
DHT sensor(dhtPin,Type);

int dt = 1000;  //Update time measured in miliseconds

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  sensor.begin();
}

void humidTemp(){
 humidity = sensor.readHumidity();  //reads humidity from DHT11
 //NOTE put true as this functions parameter to enable fahrenheit.
 temp = sensor.readTemperature();   //reads temperature (in celcius) from DHT11.
 lcd.print("HUMIDITY: ");
 lcd.print(humidity);
 lcd.print("%");
 lcd.setCursor(0,1);
 lcd.print("TEMP:     ");
 lcd.print(temp);
 lcd.print("C");
 delay(1000);                         //This delay is to be used as a refresh rate.
 lcd.clear();

 //Plots results in the serial plotter Arduino IDE in real time.
  Serial.print(humidity);
  Serial.print(" ");
  Serial.println(temp);

}

void findDistance(){
  //This will shoot a pulse to activate the HC-SR04 through the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);    //records time it took for signal to reach echo pin

  // Convert the time into a distance
  cm = (duration/2) / 29.1;     //distance = (traveltime/2) x speed of sound

  //Prints information//
  lcd.print("DISTANCE: ");
  lcd.print(cm);
  lcd.print("cm");
  delay(1000);
  lcd.clear();

//Plots results in the serial plotter Arduino IDE in real time.
  Serial.print(" ");
  Serial.println(cm);

}

void loop() {
  humidTemp();

  presentState = digitalRead(switchPin);
  //Serial.println(digitalRead(switchPin));
  //delay(250);

//This is where the buttons value is evaluated, in order to change the function of the program.
  while(presentState){
    findDistance();
    presentState = digitalRead(switchPin);

  }

}
