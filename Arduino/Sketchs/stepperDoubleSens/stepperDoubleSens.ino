
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor
const int nbTours = 2;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 12 (4 to 14 rpm)
  myStepper.setSpeed(12);
  // initialize the serial port:
  Serial.begin(115200);

  pinMode(13, OUTPUT);
}

void loop() {

  
  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*nbTours);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution*nbTours);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

