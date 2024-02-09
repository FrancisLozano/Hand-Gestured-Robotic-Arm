const int left_wheel_back = 6;
const int right_wheel_back = 5;
const int left_wheel_front = 9;
const int right_wheel_front = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(left_wheel_back, OUTPUT);
  pinMode(right_wheel_back, OUTPUT);
  pinMode(left_wheel_front, OUTPUT);
  pinMode(right_wheel_front, OUTPUT);

  // initializing motor pins 
  // only the back wheels will be motored 
  // when moving we'll only have one wheel move forward and the other going the opposite direction given if we want to move right or left
  // intiializing sensors 

}

void forward(int speed){
  // makes the robot go forward based on the speed specified 
  set_motor_speed(speed, speed, speed, speed);
}

void left(int speed){
  // makes the robot go left based on the speed specified
  set_motor_speed(0, speed, 0, speed);
}

void right(int speed){
  // makes the robot go right based on the speed specified
  set_motor_speed(speed, 0, speed, 0);
}

void stop(){
  // stops all movements of the robot
  set_motor_speed(0, 0, 0, 0);
}

void set_motor_speed(int lsb, int rsb, int lsf, int rsf){
  // analog write does only work on 3, 5, 6, 9, 10, 11
  // takes in a parameter of left and right speed
  analog.write(left_wheel_back, lsb);
  analog.write(right_wheel_back, rsb);
  analog.write(left_wheel_front, lsf);
  analog.write(right_wheel_front, rsf);

}

void loop() {
  // put your main code here, to run repeatedly:

}
