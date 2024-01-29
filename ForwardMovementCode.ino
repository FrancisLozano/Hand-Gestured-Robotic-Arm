void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT)
  pinMode(5, OUTPUT)
  pinMode(6, OUTPUT)
  pinMode(7, OUTPUT)
  pinMode(8, OUTPUT)
  pinMode(9, OUTPUT)
  pinMode(10, OUTPUT)
  pinMode(11, OUTPUT)

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

void loop() {
  // put your main code here, to run repeatedly:

}
