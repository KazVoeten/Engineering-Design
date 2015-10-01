/*This script is property of 0SAB0 Group 267.
It is conduct to the TU/e license, all rights reserved.
Strictly for personal and educational use only.*/

#include <Servo.h>
//create 2 servo instances for the motors in the camera
Servo CameraServo1;
Servo CameraServo2;

//Assign the 2 servo instances to a arduinp pin
int CameraServo1Pin = 3;
int CameraServo2Pin = 4;

//2 Integral variables for the angle the camera's motors are on.
int CameraAngle1;
int CameraAngle2;

char incomingCharacter = 0; // Setting up a character variable

//initialize the robot on startup
void setup() {
  Serial.begin(9600);
  CameraServo1.attach(CameraServo1Pin);
  CameraServo2.attach(CameraServo2Pin);
  
  //Initialize camera by setting the servo's to the default 90 degree position.
  initCamera();
}

void loop() {
  // Check if something is being received
  if (Serial.available() > 0)
  {
    // read the incoming character:
    incomingCharacter = Serial.read();
    Serial.println("OK!"); // Send OK back to laptop
    switch (incomingCharacter)
    {
      case 'w': // Case block
        //check if the angle the camera's servo's are on is safe
        if (CameraAngle1 < 165 && CameraAngle2 > 15) 
        {
        reverseServo();
        } 
        else 
        {
          initCamera();
        }
        break;
      case 's': // Case block
        //check if the angle the camera's servo's are on is safe
        if (CameraAngle1 < 165 && CameraAngle2 > 15) 
        {
        forwardServo();
        }
        else
        {
          initCamera();
        }
        break;
    }
  }
}

/*
 * Initialize the camera by setting them in the middle (90 degree) position.
 */
void initCamera()
{
  CameraAngle1 = 90;
  CameraAngle2 = 90;
  CameraServo1.write(CameraAngle1);
  CameraServo2.write(CameraAngle2);
}

/*
 * Move the camera servo backwards by subtracting 5 degrees from the angle
 * followed by a new write to make the servo move
 */
void reverseServo()
{
  CameraAngle1 = CameraAngle1 - 5;
  CameraAngle2 = CameraAngle2 - 5;
  CameraServo1.write(CameraAngle1);
  CameraServo2.write(CameraAngle2);
}

/*
 * Does the same as reverseServo() but adds to move the opposite way.
 */
void forwardServo()
{
  CameraAngle1 = CameraAngle1 + 5;
  CameraAngle2 = CameraAngle2 + 5;
  CameraServo1.write(CameraAngle1);
  CameraServo2.write(CameraAngle2);
}


