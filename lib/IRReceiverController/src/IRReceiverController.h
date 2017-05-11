#ifndef IRRECEIVERCONTROLLER
#define IRRECEIVERCONTROLLER

class IRReceiverController
{
  public:
    IRReceiverController();
    int Loop();
    void Initialize();

  private:
    int translateIR();
};

#endif
