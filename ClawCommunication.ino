#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(11,10); //coding logic error and included println to parse commands on the recieving end to have each command on a separate line.

const int clawFlexPin = A5;
const int flexPin2 = A6;
const int flexPin3 = A7;
const int flexPin4 = A8;
const int flexPin5 = A9;
const int flexPin6 = A10;


void setup(){
    pinMode(clawFlexPin, INPUT);
    pinMode(flexPin2, INPUT);
    pinMode(flexPin3, INPUT);
    pinMode(flexPin4, INPUT);
    pinMode(flexPin5, INPUT);
    pinMode(flexPin6, INPUT);

    Bluetooth.begin(9600);
    Serial.begin(9600);
}

void sendClawCommands(){
    int clawFlexValue = analogRead(clawFlexPin);
    if(clawFlexValue > 200){
        Bluetooth.println('open');
    }
    else {
        Bluetooth.println('close');
    }
    delay(3000); // inserted delays after each function to prevent rapid transmission
}

void sendArmMovement(){
    int forwardFlexValue = analogRead(flexPin2);
    int backwardFlexValue = analogRead(flexPin3);

    if(500 >= backwardFlexValue && backwardFlexValue < 700){
        Bluetooth.println('armFullyBack');
    }
    else if(300 >= backwardFlexValue && backwardFlexValue < 500){
        Bluetooth.println('armHalfwayBack');
    }
    else if(100 >= backwardFlexValue && backwardFlexValue < 300){
        Bluetooth.println('armSlightlyBack');
    }
    if(500 >= forwardFlexValue && forwardFlexValue < 700){
        Bluetooth.println('armFullyForward');
    }
    else if(300 >= forwardFlexValue && forwardFlexValue < 500){
        Bluetooth.println('armHalfwayForward');
    }
    else if(100 >= forwardFlexValue && forwardFlexValue < 300){
        Bluetooth.println('armSlightlyForward');
    }
    delay(3000);
}

void sendClawRotation(){
    int rotationFlexValue = analogRead(flexPin4);
    if (rotationFlexValue < 20){
        Bluetooth.println('rotateClaw');
    } else{
        Bluetooth.println('resetRotation');
    }
    delay(3000); 
}




void loop(){
    sendClawCommands();
    sendArmMovement();
    sendClawCommands();
}

