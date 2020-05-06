/*
 * Author: Jason Hillinger
 * Title: Stepper Motor Controller
 * This experiment was made in attempt to create a circuit that works in the same fashion as a garage door opener. Press
 * button A and the motor rotates to one direction, press button B and the motor rotates in the opposite direction.
 */
#include <Stepper.h>
//Stepper Motor Variables//
int dt = 500;           //Delay between direction change of the rotation
int motorSpeed = 10;
int const sPr = 2048;   //Steps per revolution (Specific for the 28BYJ-48)
Stepper myStepper(sPr,8,10,9,11); //Wiring scheme that is related to this found in instructions.

//Push Switch Variables//
int switch0 = 2;
int switch0Value;
int switch1 = 3;
int switch1Value;


void setup() {
myStepper.setSpeed(motorSpeed);
pinMode(switch1,OUTPUT);
digitalWrite(switch1,HIGH);
pinMode(switch0,OUTPUT);
digitalWrite(switch0,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch0Value = digitalRead(switch0);
  switch1Value = digitalRead(switch1);
  //delay(dt);
  while(!switch0Value){
      myStepper.step(sPr);
      switch0Value = digitalRead(switch0);
  }
   while(!switch1Value){
      myStepper.step(-sPr);
      switch1Value = digitalRead(switch1);
   }
}
