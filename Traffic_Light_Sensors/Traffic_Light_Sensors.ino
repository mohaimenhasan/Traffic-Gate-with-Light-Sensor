#include <Servo.h>

//sensors
int sensor_one = 0;
int sensor_two = 1;

//Lights

int yellow = 9;
int green = 10;
int red = 8;

//Servo pins

int servo_pin = 3;
int angle = 0;
Servo servo;
int red_angle = 90;
int yellow_angle = 45;
int green_angle = 0;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  servo.attach(servo_pin);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   int val_one = analogRead(sensor_one);
   int val_two = analogRead(sensor_two);
  if (val_one <= 150 or val_two <= 150) 
  {
    digitalWrite(red,LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    servo.write(red_angle);
  }
  else if ((val_one > 150 and val_one <= 300) or (val_two > 150 and val_two <= 300))
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    servo.write(yellow_angle);
  }
  else 
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    servo.write(green_angle);
  }
}
