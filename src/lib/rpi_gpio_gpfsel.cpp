//
// File: rpi_gpio_gpfsel.cpp
//
//

#include "rpi_gpio_gpfsel.h"
#include "iLog.h"

#include <iostream>
#include <fcntl.h>

void gpsel_gpio_pin(volatile unsigned int* gpio, int pin)
{
  bool active {false};

  off_t gpfsel;
  if(pin >1 && pin <10 )
    gpfsel = GPFSEL0_OFFSET;
  else if(pin > 9 && pin < 19)
    gpfsel = GPFSEL1_OFFSET;
  else if(pin > 18 && pin < 28)
    gpfsel = GPFSEL2_OFFSET;
  else if(pin > 27 && pin < 37)
    gpfsel = GPFSEL3_OFFSET;
  else if (pin > 36 && pin < 46)
    gpfsel = GPFSEL4_OFFSET;
  else if (pin > 45 && pin < 55)
    gpfsel = GPFSEL5_OFFSET;
  else
    {
      LOG(WARNING, "Your PIN# out off range\n");
      active = true;
    }
  if(!active)
    {
      volatile unsigned int* gp_fsel_pin = gpio + (gpfsel/sizeof(unsigned int));
      unsigned int value;
      value = *gp_fsel_pin;
      value &= ~(7 << 6);
      *gp_fsel_pin = value;
      value = *gp_fsel_pin;
      value |= (1 << 6);
      *gp_fsel_pin = value;
      std::cout << " the GPFSEL is: " << std::hex << *gp_fsel_pin << std::endl;
    }
}
