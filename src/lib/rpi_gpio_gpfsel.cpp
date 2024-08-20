//
// File: rpi_gpio_gpfsel.cpp
//
//

#include "rpi_gpio_gpfsel.h"
#include "iLog.h"

#include <cassert>
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

void gpsel_gpio_pin(volatile unsigned int* gpio, int pin, pin_mode p_mode)
{
  unsigned int gpfsel {};
   if(pin >= 0 && pin <= 54)
    {
      reset_pin_mode(gpio, pin);
      set_pin_mode(gpio, pin, p_mode);
    }
   else
     LOG(ERROR, "Pin number out of range (0-54)\n");
}

void reset_pin_mode(volatile unsigned int* gpio, int pin)
{
  unsigned int gpfsel_offset {};
  if(offset_select(gpfsel_offset,pin))
    {
      volatile unsigned int* gp_fsel_pin = gpio + (gpfsel_offset/sizeof(unsigned int));
      unsigned int swap {};
      swap = *gp_fsel_pin;
      swap &= ~(7 << (pin%10)*3);
      *gp_fsel_pin = swap;
      assert(*gp_fsel_pin == 0);
    }
  else
    LOG(ERROR, "Can't Select the right offset\n");
}

void set_pin_mode(volatile unsigned int* gpio, int pin, pin_mode p_mode)
{
  unsigned int gpfsel_offset{};
  if (offset_select(gpfsel_offset, pin))
    {
    volatile unsigned int *gp_fsel_pin = gpio + (gpfsel_offset / sizeof(unsigned int));
    unsigned int swap{};
    swap = *gp_fsel_pin;
    swap |= (p_mode << (pin % 10) * 3);
    *gp_fsel_pin = swap;
    assert(*gp_fsel_pin == 8000);
    }
  else
    LOG(ERROR, "Can't Select the right offset\n");
}
