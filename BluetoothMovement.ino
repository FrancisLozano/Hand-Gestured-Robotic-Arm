const int PINKY_PIN = A1;
const int THUMB_PIN = A2;
const int WRIST_UP_PIN = A3;
const int WRIST_DOWN_PIN = A4

// Possible information that could be utilized in understanding how these things work
// const float VCC = 4.98; // Measured voltage of Ardunio 5V line
// const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor
// const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
// const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(11, 10); // 11 is the RX (Receive) pin and 10 is the TX (transmit) pin

void setup(){

    pinMode(PINKY_PIN, INPUT);
    pinMode(THUMB_PIN, INPUT);
    pinMode(WRIST_UP_PIN, INPUT);
    pinMode(WRIST_DOWN_PIN, INPUT);

    Serial.begin(9600);
    Bluetooth.begin(9600);
}

void loop(){
    int pinkySensor = analogRead(PINKY_PIN);
    int thumbSensor = analogRead(THUMB_PIN);
    int wristUpSensor = analogRead(WRIST_UP_PIN);
    int wristDownSensor = analogRead(WRIST_DOWN_PIN);

    // 500 is an example of the threshold we're looking for to do that action
    if(pinkySensor >= 500 && wristUpSensor >= 500){
        Blutooth.print('back-left');
    }
    if(pinkySensor >= 500 && wristDownSensor >= 500){
        Blutooth.print('front-left');
    }
    if(thumbSensor >= 500 && wristUpSensor >= 500){
        Blutooth.print('back-right');
    }
    if(thumbSensor >= 500 && wristDownSensor >= 500){
        Blutooth.print('front-right');
    }
    if(pinkySensor >= 500){
        Blutooth.print('left');
    }
    if(thumbSensor >= 500){
        Blutooth.print('right');
    }
    if(wristUpSensor >= 500){
        Blutooth.print('back');
    }
    if(wristDownSensor >= 500){
        Blutooth.print('front');
    }
    if(pinkySensor < 500 && thumbSensor < 500 && wristUpSensor < 500 && wristDownSensor < 500){
        Bluetooth.print('stop')
    }

}