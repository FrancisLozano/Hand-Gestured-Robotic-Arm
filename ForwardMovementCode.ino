const int left_wheel = 6;
const int right_wheel = 5;

void setup() {
  // put your setup code here, to run once:

  pinMode(left_wheel, OUTPUT);
  pinMode(right_wheel, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // initializing motor pins 
  // only the back wheels will be motored 
  // when moving we'll only have one wheel move forward and the other going the opposite direction given if we want to move right or left
  // intiializing sensors 

}

void forward(){
  digitalWrite(5, LOW)
  digitalWrite(7, LOW)
  digitalWrite(9, LOW)
  digitalWrite(11, LOW)
  digitalWrite(4, LOW)
  digitalWrite(6, LOW)
  digitalWrite(8, LOW)
  digitalWrite(10, LOW)
}

void forward(int speed){
  // makes the robot go forward based on the speed specified 
  set_motor_speed(speed, speed);
}

void left(int speed){
  // makes the robot go left based on the speed specified
  set_motor_speed(speed, 0);
}

void right(int speed){
  // makes the robot go right based on the speed specified
  set_motor_speed(0, speed);
}

void stop(){
  // stops all movements of the robot
  set_motor_speed(0, 0);
}

void set_motor_speed(int left_speed, int right_speed){
  // analog write does only work on 3, 5, 6, 9, 10, 11
  // takes in a parameter of left and right speed
  analog.write(left_wheel, left_speed);
  analog.write(right_wheel, right_speed);
}

void loop() {
  // put your main code here, to run repeatedly:

}
