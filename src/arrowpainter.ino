#include <Servo.h>

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
Servo motor1;
 
void setup() {
  
  // Sets the two pins as Outputs
  motor1.attach(11);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  movealong(50);
  startPaint(8);
  stopPaint();
  movealong(15);
  startPaint(8);
  exit 1;
}

void startPaint(width){
  delay(1000);
  motor1.write(180);
  movealong(width);
}

void stopPaint(){
  delay(1000);
  motor1.write(0);
}

void movealong(width_millimeter){
  digitalWrite(dirPin,LOW); //Changes the rotations direction, away from the motor
  //digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction, towards the motor


  // Makes 200 pulses for making one full cycle rotation
  // with current motor: 200 pulses == 4cm
  // 200/40*width_millimeter
  rotation = 5*width_millimeter;
  for(int x = 0; x < rotation; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(800); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(800);
  }
}

