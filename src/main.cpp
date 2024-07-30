#include "init_gpio.h"
extern "C" {
  #include "/home/alameedi/Github/iLog/src/include/iLog.h"
}

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY"};
  std::cout << msg << std::endl;
  std::cout << "-----------------------------------" << std::endl;

  init_pin(10, 'w');
  LOG(INFO,"This is a test\n");
  return 0;
}
