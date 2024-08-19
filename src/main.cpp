// #include "init_gpio.h"
// #include "gpio_lib.h"

/*extern "C" {
  #include "iLog.h"
}
*/
#include "rpi_gpio_mem.h"
#include "rpi_gpio_gpfsel.h"
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
      std::cout << "The GPFSEL is Started " << std::endl;
      gpsel_gpio_pin(gpio_init, 5);
      unmap_peri_mem(gpio_init);
    }
  return 0;
}
