#include "init_gpio.h"
extern "C" {
  #include "/home/alameedi/Github/iLog/src/include/iLog.h"
}

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY\n"};
  LOG(INFO,msg);
  std::cout << "---------------------------------------------" << std::endl;
  init_pin(10, 'w');
  return 0;
}
