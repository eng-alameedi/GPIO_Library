//
// File: rpi_gpio_gpset.cpp
//
// this file contain the implementation of the GPSET,
// function to set the selected gpio pin to HIGH or,
// LOW when the pin mode is OUTPUT, and this state,
// ignored if the pin mode is INPUT.
//

#include "rpi_gpio_gpset.h"
#include "iLog.h"

#include <cstdlib>

unsigned int pin_select_offset(int pin_number)
{
  unsigned int pin_offset {};
  if(pin_number >=0 && pin_number <=31)
    pin_offset = GPSET0_OFFSET;
  else if(pin_number >=32 && pin_number <= 53)
    pin_offset = GPSET1_OFFSET;
  else
    {
      LOG(ERROR, "The Selected PIN number out of range (0-53)\n");
      exit(EXIT_FAILURE);
    }
     return pin_offset;
}


bool pin_set_state(volatile unsigned int* gpio, int pin_number, State pin_state)
{
  if(pin_number >= 0 && pin_number <= 53)
    {
      unsigned int gset_offset {};
      gset_offset = pin_select_offset(pin_number);
      volatile unsigned int* pin_gpset_mem = gpio + (gset_offset/sizeof(unsigned int));

      unsigned int swap{};
      swap = *pin_gpset_mem;
      if(pin_number >= 0 && pin_number <= 31)
        swap |= (pin_state << pin_number);
      else if(pin_number >= 32 && pin_number <= 53)
        swap |= (pin_state << (pin_number-32));
      else
        return false;

      *pin_gpset_mem = swap;
    }
  else
    {
      LOG(ERROR,"Selected PIN number out off range (0-53)\n");
      return false;
    }
  return true;
}
