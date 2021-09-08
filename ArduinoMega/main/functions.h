
//ultrasonic
#define TRIG_PIN 24
#define ECHO_PIN A15

//motors
#define EN_A A0
#define EN_B A1
#define IN1_FRONT 46
#define IN1_BACK 47
#define IN2_BACK 48 
#define IN2_FRONT 49

//servo
#define SCL 21
#define SDA 20

#include <Servo.h>


void turnOffMotors()
{
  digitalWrite(IN1_FRONT, LOW);
  digitalWrite(IN1_BACK, LOW);
  digitalWrite(IN2_FRONT, LOW);
  digitalWrite(IN2_BACK, LOW);
}

void moveFront()
{
  analogWrite(EN_A, 150);
  analogWrite(EN_B, 150);
  
  digitalWrite(IN1_FRONT, HIGH);
  digitalWrite(IN1_BACK, LOW);
  digitalWrite(IN2_FRONT, HIGH);
  digitalWrite(IN2_BACK, LOW);
  delay(1000);
  turnOffMotors();
}

void moveLeft()
{
  analogWrite(EN_A, 130);
  analogWrite(EN_B, 130);


  digitalWrite(IN1_FRONT, LOW);
  digitalWrite(IN1_BACK, HIGH);
  digitalWrite(IN2_FRONT, LOW);
  digitalWrite(IN2_BACK, HIGH);

  delay(1000);
  
  digitalWrite(IN1_FRONT, HIGH);
  digitalWrite(IN1_BACK, LOW);
  digitalWrite(IN2_FRONT, LOW);
  digitalWrite(IN2_BACK, LOW);
  delay(2000);
  turnOffMotors();
}


void moveServo(Servo servo, int startInterval, int endInterval)
{
  int angle;
  for(angle = startInterval; angle < endInterval; angle += 1)
  {                                  
    servo.write(angle);
    delay(15);                       
  }
  //delay(500);
}


void releaseServo(Servo servo, int startInterval, int endInterval)
{
  int angle;
  for(angle = startInterval; angle>=endInterval; angle-=1)     
  {                                
    servo.write(angle);              
    delay(15);                       
  }
//  delay(500);
}


void setupUltrasonic()
{ 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void setupMotors()
{

  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN1_FRONT, OUTPUT);
  pinMode(IN1_BACK, OUTPUT);
  pinMode(IN2_FRONT, OUTPUT);
  pinMode(IN2_BACK, OUTPUT);

  analogWrite(EN_A, 100);
  analogWrite(EN_B, 100);
  digitalWrite(IN1_FRONT, LOW);
  digitalWrite(IN1_BACK, LOW);
  digitalWrite(IN2_BACK, LOW);
  digitalWrite(IN2_FRONT, LOW);
}



float measureDistance() //this works cool
{
  long duration;
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  Serial.println((duration / 29) / 2);
  return (duration / 29) / 2;
}


void namaste(Servo arm_left, Servo arm_right, Servo shoulder_left, Servo shoulder_right, Servo neck)
{
  //right
  releaseServo(shoulder_right, 90, 0);
  releaseServo(arm_right, 90, 0);
  
  //left
  moveServo(shoulder_left, 90, 180);
  moveServo(arm_left, 0, 90);

  //neck
  moveServo(neck, 0, 70);
  releaseServo(neck, 70, 0);

  //back right
  moveServo(shoulder_right, 0, 90);
  moveServo(arm_right, 0, 90);

  //back left
  releaseServo(shoulder_left, 180, 90);
  releaseServo(arm_left, 90, 0);
  
}


//void loop() {
//  //measure distance
////  distance = measureDistance();
////  if(distance < 50)
////    moveLeft();
////  moveFront();   
//moveLowerLeft();
//  
//  
//  delay(200);
//}
