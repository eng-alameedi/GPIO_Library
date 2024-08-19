// #include "init_gpio.h"
// #include "gpio_lib.h"

/*extern "C" {
  #include "iLog.h"
}
*/
#include "rpi_gpio_mem.h"
#include "iLog.h"

#include <iostream>

int main() {
  const char* msg{"Welcome in our GPIO LIBRARY\n"};
  LOG(INFO,msg);
  std::cout << "---------------------------------------------" << std::endl;

  // pin_init(10);

  // std::cout << "The GPIO PIN #" << gpin10.get_pin() << std::endl;

  volatile unsigned int* gpio_init = map_peri_mem();

  if(gpio_init != nullptr)
    {
      std::cout << "The Var in Pointer: " << *gpio_init << std::endl;
      unmap_peri_mem(gpio_init);
    }
  return 0;
}
