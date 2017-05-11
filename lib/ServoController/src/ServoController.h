#ifndef SERVOCONTROLLER
#define SERVOCONTROLLER

class ServoController
{
  public:
    ServoController();
    void Loop();
    void Initialize();
    void Switch();
    void SetPos(int newPos);

  private:
    void On();
    void Off();

    bool IsOn = false;
    int Position = 0;
};

#endif
