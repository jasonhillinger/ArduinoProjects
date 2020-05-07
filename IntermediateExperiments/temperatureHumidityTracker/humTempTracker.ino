/*
 * Author: Jason Hillinger
 * Title: Humidity/Temperature tracker
 * This code makes use of the LCD screen and DHT11 to measure the humidity and temperature in the room.
 */
 #include "LiquidCrystal.h"
 #include "DHT.h"
 #define Type DHT11

 //DHT Variables//
 int dhtPin=2;
 double humidity, temp;

 //Object creation//
 LiquidCrystal lcd(7,8,9,10,11,12);
 DHT sensor(dhtPin,Type);

 int dt = 1000;  //Update time measured in miliseconds

 void setup() {
 lcd.begin(16,2);
 sensor.begin();
 }

 void loop() {
  //lcd.setCursor(0,0);
  humidity = sensor.readHumidity();  //reads humidity from DHT11
  temp = sensor.readTemperature();   //reads temperature (in celcius) from DHT11. NOTE put true as this functions parameter to enable fahrenheit.
  lcd.print("HUMIDITY: ");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("TEMP:     ");
  lcd.print(temp);
  lcd.print("C");
  delay(dt);                         //This delay is to be used as a refresh rate.
  lcd.clear();
 }
