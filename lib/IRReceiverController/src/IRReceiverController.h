#ifndef IRRECEIVERCONTROLLER
#define IRRECEIVERCONTROLLER

class IRReceiverController
{
  public:
    IRReceiverController();
    void Loop();
    void Initialize();

  private:
    void translateIR();
};


void test();

#endif
