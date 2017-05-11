#include "../../Constantes.h"
#include "IRReceiverController.h"
#include <IRRemote.h>


IRrecv irrecv(IRRECEIVERPIN);
decode_results results;

IRReceiverController::IRReceiverController()
{

}

void IRReceiverController::Initialize()
{
  Serial.println("IR Receiver Initialization");
  irrecv.enableIRIn();
}

int IRReceiverController::Loop()
{
  if (irrecv.decode(&results))
  {

    int result = translateIR();
    irrecv.resume();

    return result;
  }

  return IRCMDERROR;
}

int IRReceiverController::translateIR()
{
  Serial.println("Debug IR :");
  Serial.println(results.value);
  switch(results.value)
  {
    // POWER
    case 0xFFA25D: return IRCMDPOWER;
    // FUNC/STOP
    case 0xFFE21D:
    //VOL+
    case 0xFF629D:
    // FAST BACK
    case 0xFF22DD:
    // PAUSE
    case 0xFF02FD:
    // FAST FORWARD
    case 0xFFC23D:
    // DOWN
    case 0xFFE01F:
    // VOL-
    case 0xFFA857:
    // UP
    case 0xFF906F:
    // EQ
    case 0xFF9867:
    // ST/REPT
    case 0xFFB04F:
    // 0
    case 0xFF6897:
    // 1
    case 0xFF30CF: return IRCMD1;
    // 2
    case 0xFF18E7: return IRCMD2;
    // 3
    case 0xFF7A85:
    // 4
    case 0xFF10EF:
    // 5
    case 0xFF38C7:
    // 6
    case 0xFF5AA5:
    // 7
    case 0xFF42BD:
    // 8
    case 0xFF4AB5:
    // 9
    case 0xFF52AD:
    // REPEAT
    case 0xFFFFFFFF:
    // UNKOWN
    default: return IRCMDUNKNWON;
  }// End Case
}
