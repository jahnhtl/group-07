/*========================================================================== 
//  Author      : Handson Technology 
//  Project     : Arduino Uno 
//  Description : L298N Motor Driver 
//  Source-Code : L298N_Motor.ino 
//  Program: Control 2 DC motors using L298N H Bridge Driver 
//==========================================================================*/ 
// Definitions Arduino pins connected to input H Bridge

int switch_red = 2;
int switch_black = 3;
int ena = 6;
int IN1 = 7;
int IN2 = 8;
int IN3 = 9;
int IN4 = 10;
int enb = 11;
int sensor_pin = A5;
int sensor_value = 0;
bool program_state = false;

void setup(){
  // Set the output pins
  pinMode(ena, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(switch_red, INPUT_PULLUP);
  pinMode(switch_black, INPUT_PULLUP);
}
void loop(){
  for(;;) {
    if(digitalRead(switch_black) == LOW) {
      program_state = true;
    } 
    if(digitalRead(switch_red) == LOW) {
      program_state = false;
      digitalWrite(ena, LOW);
      digitalWrite(enb, LOW);
    }
    if(!program_state) {
      continue;
    }
    sensor_value = analogRead(sensor_pin) / 4;
    // Rotate the Motor A clockwise
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ena, sensor_value);
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(enb, sensor_value);
    
    /*delay(500);
    // Motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(500);
    // Rotate the Motor B clockwise 
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);
    // Motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);
    // Rotates the Motor A counter-clockwise
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(500);
    // Motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(500);
    // Rotates the Motor B counter-clockwise
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    // Motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);*/
  }
}
