#include "gpio_lib.h"

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY"};
  std::cout << msg << std::endl;
  int pin_num{3};
  int* pin;
  pin = &pin_num;
  Gpio second {pin};
  int ppin{3};
  Gpio thrid{ppin};
  return 0;
}
