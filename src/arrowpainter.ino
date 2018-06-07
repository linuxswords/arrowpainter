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
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  rotation(3.5*360);
  paint(1500, 0); 
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  rotation(3.5*360);
  paint(1500, 0);
}

void paint(duration, width){
  delay(1000);
  motor1.write(180);
  delay(duration);
  motor1.write(0);
  delay(1000); // One second delay
}

void rotation(degree){
  rotation = 200/360*degree;
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < rotation; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(800); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(800);
  }
}

