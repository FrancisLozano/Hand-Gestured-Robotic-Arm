#include <Servo.h>


int GRIP_SERVO_PIN  = 2;
int CLAW_ROTATION_SERVO_PIN = 3;
int flexPin = A5;


Servo ClawGrip;
Servo ClawRotator;
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(flexPin, INPUT)
  ClawGrip.attach(GRIP_SERVO_PIN);
  ClawRotator.attach(CLAW_ROTATION_SERVO_PIN);

  //Initialize starting positions for servos
  ClawGrip.write(90);
  ClawRotator.write(90);

}
void clawGripActivate(float sensorData){
  int angle = map(sensorData,0,1023,0,180); //Adjust flex sensor readings
  ClawGrip.write(angle);
}

void clawGripClose(){
  ClawGrip.write(0); //assumes '0 degrees' position for servo is closed
}

void clawGripOpen(){
  ClawGrip.write(180); //assumes maximum rotation for servo is claw fully opened
}

void rotateClaw(float sensorData){
  int angle = map(sensorData,0,1023,0,180); //Adjust flex sensor readings
  ClawRotator.write(angle);
}


void forward(){
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
