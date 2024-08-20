//
// File: rpi_gpio_gpfsel.cpp
//
//

#include "rpi_gpio_gpfsel.h"
#include "iLog.h"

#include <iostream>
#include <fcntl.h>

bool offset_select(unsigned int& offset, int pin)
{
  if (pin > 1 && pin < 10)
    offset = GPFSEL0_OFFSET;
  else if (pin > 9 && pin < 19)
    offset = GPFSEL1_OFFSET;
  else if (pin > 18 && pin < 28)
    offset = GPFSEL2_OFFSET;
  else if (pin > 27 && pin < 37)
    offset = GPFSEL3_OFFSET;
  else if (pin > 36 && pin < 46)
    offset = GPFSEL4_OFFSET;
  else if (pin > 45 && pin < 55)
    offset = GPFSEL5_OFFSET;
  else
    {
    LOG(WARNING, "Your PIN# out off range\n");
    return false;
    }
  return true;
}

void gpsel_gpio_pin(volatile unsigned int* gpio, int pin)
{
  unsigned int gpfsel {};
   if(offset_select(gpfsel, pin))
    {
      volatile unsigned int* gp_fsel_pin = gpio + (gpfsel/sizeof(unsigned int));
      unsigned int value;
      value = *gp_fsel_pin;
      value &= ~(7 << (pin%10)*3);
      *gp_fsel_pin = value;
      std::cout << "The GPFSEL is: " << std::hex << *gp_fsel_pin << std::endl;
      value = *gp_fsel_pin;
      value |= (1 << (pin%10)*3);
      *gp_fsel_pin = value;
      std::cout << " the GPFSEL is: " << std::hex << *gp_fsel_pin << std::endl;
      value = *gp_fsel_pin;
      value &= ~(7 << (pin%10)*3);
      *gp_fsel_pin = value;
      std::cout << "The GPFSEL is: " << std::hex << *gp_fsel_pin << std::endl;
    }
   else
     LOG(ERROR, "Something went wrong\n");
}
