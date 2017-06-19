#include <Servo.h>

// A system that controls a gate using traffic lights 

// Light pins

int yellow = 9;
int green = 10;
int red = 8;
//Servo pins and declaration

Servo servo;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  servo.attach(11);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly;
    for(angle = 0; angle< 90; angle++)
    {
      servo.write(angle);
      if(angle == 0)
      {
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);
        delay(2000);
      }
      if (angle > 0 and angle < 88)
      {
        digitalWrite(red, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(green, LOW);
        delay(20);
      }
      if (angle == 89)
      {
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, HIGH);
        delay(2000);
      }
        
    }  
    
}
