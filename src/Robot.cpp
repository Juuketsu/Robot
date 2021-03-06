#include "IRReceiverController.h"
#include "ServoController.h"
#include "MPUController.h"
#include <IRRemote.h>
#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include "../lib/Constantes.h"

IRReceiverController IRController;
ServoController Servo;
MPUController MPU;

unsigned long timer;

void setup()
{
  Serial.begin(9600);
  Serial.println("Modules initialization");
  //IRController.Initialize();
  //Servo.Initialize();
  MPU.Initialize();
  timer = millis();
}

void loop()
{
  /*unsigned long current = millis();
  if(current - timer > 50)
  {
    timer = current;
    int IRSig = IRController.Loop();
    if (IRSig == IRCMDPOWER)
      Servo.Switch();
    if(IRSig == IRCMD1)
      Servo.SetPos(90);
    if(IRSig == IRCMD2)
      Servo.SetPos(180);

    Servo.Loop();
  }*/

  MPU.Loop();
}
