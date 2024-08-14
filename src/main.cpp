#include "init_gpio.h"
#include "gpio_lib.h"

extern "C" {
  #include "/home/alameedi/Github/iLog/src/include/iLog.h"
}

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY\n"};
  LOG(INFO,msg);
  std::cout << "---------------------------------------------" << std::endl;

  pin_init(10);

  std::cout << "The GPIO PIN #" << g10.get_pin() << std::endl;
  return 0;
}
