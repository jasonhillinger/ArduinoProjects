/*
 * Author: Jason Hillinger
 * Title: Stepper Motor Controller
 * This experiment was made in attempt to create a circuit that works in the same fashion as a garage door opener. Press
 * button A and the motor rotates to one direction, press button B and the motor rotates in the opposite direction.
 */
 #include <Stepper.h>
 //Stepper Motor Variables//
 int dt = 500;           //Delay between direction change of the rotation
 int motorSpeed = 10;     //Motor speed, max=10, min=0
 int const sPr = 2048;   //Steps per revolution
 Stepper myStepper(sPr,8,10,9,11); //Wiring scheme that is related to this found in instructions.

 //Push Switch Variables//
 int switch0 = 2;
 int switch0Value;
 int switch1 = 3;
 int switch1Value;


 void setup() {
 myStepper.setSpeed(motorSpeed);    //speed of motor defined here
 pinMode(switch1,OUTPUT);
 digitalWrite(switch1,HIGH);
 pinMode(switch0,OUTPUT);
 digitalWrite(switch0,HIGH);
 }

 void loop() {
   switch0Value = digitalRead(switch0);
   switch1Value = digitalRead(switch1);
   if(!switch0Value){     //if switch0 is pressed, turn motor
       myStepper.step(sPr);
   }
    if(!switch1Value){    //if switch1 is pressed, turn motor in opposite direction
       myStepper.step(-sPr);
    }
 }
