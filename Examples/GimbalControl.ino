#include <Servo.h>

Servo servoX;
Servo servoY;

int posY = 90;
int posX = 90;

void setup() {
  // put your setup code here, to run once:
  servoX.attach(11);
  servoY.attach(10);
  Serial.begin(9600);
  servoX.write(posX);
  servoY.write(posY);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char Command = Serial.read();
    switch(Command)
    {
      case 'w':
        posY = posY + 5;
        servoY.write(posY);
      break;
      case 's':
        posY = posY - 5;
        servoY.write(posY);
      break;
      case 'a':
        posX = posX + 5;
        servoX.write(posX);
      break;
      case 'd':
        posX = posX - 5;
        servoX.write(posX);
      break;
    }
  }
}
