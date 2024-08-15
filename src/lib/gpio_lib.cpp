#include "gpio_lib.h"
#include "gpio.h"

#include <iostream>

// using Gpio::State::READ;
/*
Gpio::Gpio(int& pin): pin_number(&pin), direction(READ), owner(false)
{
  if(gpio_setup())
    std::cout << "GPIO Setup Done...!" << std::endl;
  else
    std::cout << "GPIO Setup Not Work...!" << std::endl;
}
Gpio::Gpio(int* pin): pin_number(new int {*pin}), direction(READ), owner(true)
{
  if(gpio_setup())
    std::cout << "GPIO Setup Done...!" << std::endl;
  else
    std::cout << "GPIO Setup Not Work...!" << std::endl;
}
*/
Gpio::Gpio(int pin): pin_number(new int(pin)), direction(Gpio::State::READ), owner(true)
{
  if(gpio_setup())
    std::cout << "GPIO Setup Done...!" << std::endl;
  else
    std::cout << "GPIO Setup Not Work...!" << std::endl;
}

Gpio::~Gpio()
{
  if(owner)
    {
      delete pin_number;
      pin_number = nullptr;
      std::cout << "A pointer class was deleted" << std::endl;
    }
  else
    {
      std::cout << "A normal class was deleted" << std::endl;
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
