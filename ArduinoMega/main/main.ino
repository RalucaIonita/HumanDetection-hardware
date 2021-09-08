#include "functions.h"

Servo shoulder_left;
Servo shoulder_right; 
Servo arm_right;
Servo arm_left;
Servo neck;

long distance = 0;

void setupServos()
{
  shoulder_left.attach(7);
  shoulder_right.attach(44);
  arm_right.attach(45); //works weird/does not work, tries to work tho'
  arm_left.attach(4);
  neck.attach(3);
}

void setup()
{ 
  setupMotors();
  setupUltrasonic();
  setupServos();
  Serial.begin(9600);
  Serial.println("Setup finished.");

  releaseServo(neck, 90, 0);
  releaseServo(arm_left, 90, 0);
  
  

} 
  
void loop() 
{ 
//measure distance
//  if(measureDistance() < 40)
//    moveLeft();
//  else
//    moveFront();   

  namaste(arm_left, arm_right, shoulder_left, shoulder_right, neck);
  delay(1000);
}
