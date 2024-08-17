#include "gpio_lib.h"
#include "gpio.h"

extern "C" {
  #include "iLog.h"
}

Gpio::Gpio(int pin): pin_number(new int(pin)), direction(Gpio::State::READ), owner(true)
{
  if(gpio_setup())
    LOG(INFO, "GPIO Setup Done...!\n");
  else
    LOG(INFO, "GPIO Setup Not Work...!\n");
}

Gpio::~Gpio()
{
  if(owner)
    {
      delete pin_number;
      pin_number = nullptr;
      LOG(INFO, "A pointer class was deleted");
    }
  else
    {
      LOG(INFO, "A normal class was deleted");
    }
}


int Gpio::get_pin()const {return *pin_number;}
Gpio::State Gpio::get_state()const { return direction;}
bool Gpio::get_ownership()const {return owner;}

void Gpio::set_state(State st) {direction = st;}

void Gpio::read_data()
{
  set_state(State::READ);
}

void Gpio::write_data()
{
  set_state(State::WRITE);
}
