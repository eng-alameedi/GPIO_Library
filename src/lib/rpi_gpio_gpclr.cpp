//
// File: rpi_gpio_gpclr.cpp
//
// this file contain the implementation of the
// pin output clear state function.
//

#include "rpi_gpio_gpclr.h"

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
