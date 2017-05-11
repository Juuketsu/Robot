#include "IRReceiverController.h"
#include "ServoController.h"
#include <IRRemote.h>
#include <Servo.h>
#include "../lib/Constantes.h"

IRReceiverController IRController;
ServoController Servo;

void setup()
{
  Serial.println("Modules initialization");
  //IRController.Initialize();
  Servo.Initialize();
}

void loop()
{
  //IRController.Loop();
  Servo.Loop();
}
