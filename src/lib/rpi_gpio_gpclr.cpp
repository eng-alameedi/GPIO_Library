//
// File: rpi_gpio_gpclr.cpp
//
// this file contain the implementation of the
// pin output clear state function.
//

#include "rpi_gpio_gpclr.h"
#include "iLog.h"

unsigned int pin_clear_offset(int pin_number) {
  unsigned int pin_offset{};
  if (pin_number >= 0 && pin_number <= 31)
    pin_offset = GPCLR0_OFFSET;
  else if (pin_number >= 32 && pin_number <= 53)
    pin_offset = GPCLR1_OFFSET;
  else {
    LOG(ERROR, "The Selected PIN number out of range (0-53)\n");
    exit(EXIT_FAILURE);
  }
  return pin_offset;
}

void pin_clear_state(volatile unsigned int* gpio, int pin_number)
{
  if(pin_number >= 0 && pin_number <= 53)
  {
    unsigned int gset_offset{};
    gset_offset = pin_clear_offset(pin_number);
    volatile unsigned int *pin_gpset_mem =
        gpio + (gset_offset / sizeof(unsigned int));

    unsigned int swap{};
    swap = *pin_gpset_mem;
    if (pin_number >= 0 && pin_number <= 31)
      swap |= (CLEAR_PIN << pin_number);
    else if (pin_number >= 32 && pin_number <= 53)
      swap |= (CLEAR_PIN << (pin_number - 32));

    *pin_gpset_mem = swap;
  }
  else {
    LOG(ERROR, "Selected PIN number out off range (0-53)\n");
  }
}
