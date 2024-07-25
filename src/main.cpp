#include "init_gpio.h"

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY"};
  std::cout << msg << std::endl;
  std::cout << "-----------------------------------" << std::endl;

  init_pin(10, 'w');
  return 0;
}
