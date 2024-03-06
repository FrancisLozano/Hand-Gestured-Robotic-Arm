// possibility up to change for pins 
const int left_wheel_back_f = 6;
const int right_wheel_back_f = 5;
const int left_wheel_front_f = 9;
const int right_wheel_front_f = 10;

const int left_wheel_back_b = 7;
const int right_wheel_back_b = 8;
const int left_wheel_front_b = 11;
const int right_wheel_front_b = 12;

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(4, 2);  // 4 is the RX (Receive) pin and 2 is the TX (transmit) pin
char pinkySensor = 0
char thumbSensor = 0
char wristUpSensor = 0
char wristDownSensor = 0

void setup() {
  // initialization of the wheels for forward and backward
  pinMode(left_wheel_back_f, OUTPUT);
  pinMode(right_wheel_back_f, OUTPUT);
  pinMode(left_wheel_front_f, OUTPUT);
  pinMode(right_wheel_front_f, OUTPUT);

  pinMode(left_wheel_back_b, OUTPUT);
  pinMode(right_wheel_back_b, OUTPUT);
  pinMode(left_wheel_front_b, OUTPUT);
  pinMode(right_wheel_front_b, OUTPUT);

  pinmode(A0, INPUT); // initialization of flex sensor, subject to change 
  pinmode(A1, INPUT);
  pinmode(A2, INPUT);
  pinmode(A3, INPUT);
  pinmode(A4, INPUT);
  pinmode(A5, INPUT);
  
  // init for bluetooth
  Bluetooth.begin(9600);
  Serial.begin(9600);
}

// positional movements 

void forward(){
  // makes the robot go forward 
  setLeftBackWheel(true, true);
  setRightBackWheel(true, true);
  setLeftFrontWheel(true, true);
  setRightFrontWheel(true, true);
}

void backward(){
  // stops all movements of the robot
  setLeftBackWheel(true, false);
  setRightBackWheel(true, false);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(true, false);
}

void forwardLeft(){
  // makes the robot go forward left
  setLeftBackWheel(false, false);
  setRightBackWheel(true, true);
  setLeftFrontWheel(true, true);
  setRightFrontWheel(false, false);
}

void forwardRight(){
  // makes the robot go forward right
  setLeftBackWheel(true, true);
  setRightBackWheel(false, false);
  setLeftFrontWheel(false, false);
  setRightFrontWheel(true, true);
}

void backwardLeft(){
  // makes the robot go backward left
  setLeftBackWheel(true, false);
  setRightBackWheel(false, false);
  setLeftFrontWheel(false, false);
  setRightFrontWheel(true, false);
}

void backwardRight(){
  // makes the robot go backward right
  setLeftBackWheel(false, false);
  setRightBackWheel(true, false);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(false, false);
}

void left(){
  // makes the robot move left 
  setLeftBackWheel(true, false);
  setRightBackWheel(true, true);
  setLeftFrontWheel(true, true);
  setRightFrontWheel(true, false);
}

void right(){
  // makes the robot move right 
  setLeftBackWheel(true, true);
  setRightBackWheel(true, false);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(true, true);
}

void stop(){
  // stops all movements of the robot
  setLeftBackWheel(false, false);
  setRightBackWheel(false, false);
  setLeftFrontWheel(false, false);
  setRightFrontWheel(false, false);
}

// angeled movements 

void turnRight(){
  setLeftBackWheel(true, true);
  setRightBackWheel(true, false);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(true, true);
}

void turnLeft(){
  setLeftBackWheel(true, false);
  setRightBackWheel(true, true);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(true, true);
}

void curvedRight(){
  // will need speed changes
  setLeftBackWheel(true, true); // less speed
  setRightBackWheel(true, true);
  setLeftFrontWheel(true, true); // less speed
  setRightFrontWheel(true, true);
}

void curvedLeft(){
  // will need speed changes
  setLeftBackWheel(true, true);
  setRightBackWheel(true, true); // less speed 
  setLeftFrontWheel(true, true);
  setRightFrontWheel(true, true); // less speed
}

void lateralArcRight(){
  setLeftBackWheel(false, false);
  setRightBackWheel(false, false);
  setLeftFrontWheel(true, false);
  setRightFrontWheel(true, true);
}

void lateralArcLeft(){
  setLeftBackWheel(false, false);
  setRightBackWheel(false, false);
  setLeftFrontWheel(true, true);
  setRightFrontWheel(true, false);
}

void setLeftBackWheel(bool move, bool direction){
  if(move == true) {
    if(direction == true) {
      digitalWrite(left_wheel_back_b, HIGH);
    }
    else {
      digitalWrite(left_wheel_back_f, HIGH);
    }
  }
  else{
    digitalWrite(left_wheel_back_f, LOW);
    digitalWrite(left_wheel_back_b, LOW);
  }
}

void setRightBackWheel(bool move, bool direction){
  if(move == true) {
    if(direction == true) {
      digitalWrite(left_wheel_back_b, HIGH);
    }
    else {
      digitalWrite(left_wheel_back_f, HIGH);
    }
  }
  else{
    digitalWrite(left_wheel_back_f, LOW);
    digitalWrite(left_wheel_back_b, LOW);
  }
}

void setLeftFrontWheel(bool move, bool direction){
  if(move == true) {
    if(direction == true) {
      digitalWrite(left_wheel_back_b, HIGH);
    }
    else {
      digitalWrite(left_wheel_back_f, HIGH);
    }
  }
  else{
    digitalWrite(left_wheel_back_f, LOW);
    digitalWrite(left_wheel_back_b, LOW);
  }
}

void setLeftFrontWheel(bool move, bool direction){
  if(move == true) {
    if(direction == true) {
      digitalWrite(left_wheel_back_b, HIGH);
    }
    else {
      digitalWrite(left_wheel_back_f, HIGH);
    }
  }
  else{
    digitalWrite(left_wheel_back_f, LOW);
    digitalWrite(left_wheel_back_b, LOW);
  }
}

void loop() {
  if(Bluetooth.available() > 0){
    // it seems Bluetooth.read() will be the same thing regardless
    result = Bluetooth.read();
  }

  if(result == 'back-left'){
    backwardLeft();
  }
  else if(result == 'front-left'){
    forwardLeft();
  }
  else if(result == 'back-right'){
    backwardRight();
  }
  else if(result == 'front-right'){
    forwardRight();
  }
  else if(result == 'left'){
    left();
  }
  else if(result == 'right'){
    right();
  }
  else if(result == 'front'){
    forward();
  }
  else if(result == 'back'){
    backward();
  }
  else if(result == 'stop'){
    stop();
  }


}

