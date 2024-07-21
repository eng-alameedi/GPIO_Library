#include "gpio_lib.h"

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY"};
  std::cout << msg << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  int pin1{3};
  int* pin_num = &pin1;
  Gpio pin3{pin_num};
  std::cout << "Pin Number is: " << pin3.get_pin() << std::endl;
  if(pin3.get_state() == Gpio::State::READ)
    std::cout << "Pin Direction is: INPUT" << std::endl;
  else
    std::cout << "Pin Direction is: OUTPUT" << std::endl;
  return 0;
}
