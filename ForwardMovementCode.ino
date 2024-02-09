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
  ClawGrip.attach(GRIP_SERVO_PIN);
  ClawRotator.attach(CLAW_ROTATION_SERVO_PIN);

}
// Not sure if this is what we need, claw has more continuous movement based on sensor rather than just open/close
void clawGripActivate(float sensorData){
  int angle = map(sensorData,0,1000,0,180); //Change conversion, not sure if max flex sensor reading is 1023 or if max servo angle should be 180
  ClawGrip.write(angle);
}

void clawGripClose(){
  ClawGrip.write(0); //assumes '0 degrees' position for servo is closed
}

void clawGripOpen(){
  ClawGrip.write(180); //assumes maximum rotation for servo is claw fully opened
}

//assumes servo's initial state is at 90 degrees
void rotateClaw(float sensorData){
  int angle = map(sensorData,0,1023,0,180); //Change conversion, not sure if max flex sensor reading is 1023 or if max servo angle should be 180
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
