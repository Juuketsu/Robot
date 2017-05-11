#include "../../Constantes.h"
#include "ServoController.h"
#include <Servo.h>
#include <Arduino.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

ServoController::ServoController()
{

}

void ServoController::Initialize()
{

}

void ServoController::Switch()
{
  if(ServoController::IsOn)
  {
    Serial.println("Servo off");
    ServoController::IsOn = false;
    Off();
  }
  else
  {
    Serial.println("Servo on");
    ServoController::IsOn = true;
    On();
  }
}

void ServoController::On()
{
  myservo.attach(SERVOPIN);  // attaches the servo on pin 9 to the servo object
}

void ServoController::Off()
{
  myservo.detach();
}

void ServoController::Loop()
{
  if(IsOn)
  {

  }
}

void ServoController::SetPos(int newPos)
{
  if(IsOn)
  {
    Position = newPos;
    myservo.write(Position);
  }
}
