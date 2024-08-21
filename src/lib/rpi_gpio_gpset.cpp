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

unsigned int pin_select_offset(int pin_number)
{
  unsigned int pin_offset {};
  if(pin_number >=0 && pin_number <=31)
    pin_offset = GPSET0_OFFSET;
  else if(pin_number >=32 && pin_number <= 53)
    pin_offset = GPSET1_OFFSET;
  else
    LOG(WARNING, "The Selected PIN number out of range (0-53)\n");
  return pin_offset;
}
