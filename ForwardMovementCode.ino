#include <Servo.h>


int GRIP_SERVO_PIN  = 2;
int CLAW_ROTATION_SERVO_PIN = 3;
int flexPin1 = A5;
int flexPin2 = A6;
int flexPin3 = A7;
int flexPin4 = A8;
int flexPin5 = A9;
int flexPin6 = A10;

int armPin = 4;

int steps = 200;

Servo ClawGrip;
Servo ClawRotator;
Servo ArmRotator;

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
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  pinMode(flexPin5, INPUT);
  pinMode(flexPin6, INPUT);
  ClawGrip.attach(GRIP_SERVO_PIN);
  ClawRotator.attach(CLAW_ROTATION_SERVO_PIN);
  ArmRotator.attach(armPin);
  
  //Initialize starting positions for servos
  ClawGrip.write(90);
  ClawRotator.write(90);
  
  Serial.begin(9600);

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

void armForward(float sensorData){
  angle = map(sensorData,0,1023,0,90);
  armRotator.write(angle);
}

void armBackward(float sensorData){
  angle = map(sensorData,0,1023,90,180)
  armRotator.write(angle);
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
  int thumbSensor = analogRead(flexPin1);
  int ringSensor = analog(flexPin6);
  int wristSensorF1 = analogRead(flexPin2);
  int wristSensorF2 = analogRead(flexPin3);
  int wristSensorB1 = analogRead(flexPin4);
  int wristSensorB2 = analogRead(flexPin5);
  int wristSensorForward = (wristSensorF1 + wristSensorF2) / 2;
  int wristSensorBackward = (wristSensorB1 + wristSensorB2) / 2;

  if(thumbSensor < 20){
    clawGripClose();
  } else {
    clawGripOpen();
  }

  if (ringSensor < 20){
    rotateClaw(ringSensor);
  } else {
    stop();
  }

  if(thumbSensor < 20){
    clawGripClose();
  } else {
    clawGripOpen();
  }

  if (ringSensor < 20){
    rotateClaw(ringSensor);
  }

  if (wristSensorForward > 20) {
    //arm forward logic
    armForward(wristSensorForward);

  } else if (wristSensorBackward > 20){
    //arm backward logic
    armBackward(wristSensorBackward);
  }




}
