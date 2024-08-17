//
// File: init_gpio.h
//
// This file contain the functions, and
// macros to initialize the class Gpio,
// with the pin number for read and,
// write with (HIGH/LOW) value of the pin.
//

#ifndef _INIT_GPIO_H_
#define _INIT_GPIO_H_

/**
 * @brief: the (pin_init) macro used for make the GPIO pin ready.
 *
 * @param: this macro take the pin number of type (int) and pass it to Gpio class.
 *
 * @return: the result of this macro is a class with name (gpin#pin_number).
 */
#define pin_init(pin) Gpio gpin##pin(pin)

#endif // _INIT_GPIO_H_
