#include "gpio_lib.h"

#include <iostream>

using Gpio::State::READ;
using Gpio::State::WRITE;

Gpio::Gpio(int& pin): pin_number(&pin), direction(READ), owner(false) {/* check for pin state (if it's read only)*/}
Gpio::Gpio(int* pin): pin_number(new int {*pin}), direction(READ), owner(true) {/*Check for pin state and pin!=nullptr */}

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
