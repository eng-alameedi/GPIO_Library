//
// File: rpi_gpio_gpset.h
//
// this file contains the main functions that,
// set the gpio pin to high (1) or low (0),
// for output of (3.3v) voltage.
//

#ifndef _RPI_GPIO_GPSET_H_
#define _RPI_GPIO_GPSET_H_

#define GPSET0_OFFSET          (0x1C)                    // define the offset for the set0 (32 bit) (0 - 31) for gpio pin (0-31).
#define GPSET1_OFFSET          (0x20)                    // define the offset for the set1 (32 bit) (0 - 21) for gpio pin (32-53).

enum State {LOW=0, HIGH=1};                              // define a enumeration for set the state of pin (high) or (low).

/**
 *
 * @brief: this function select the offset of the GPSET depend on pin number.
 *
 * @param1: this function take (int) pin number.
 *
 * @return: this function return (unsigned int) offset that used to active the pin state.
 *
 **/
unsigned int pin_select_offset(int);

/**
 *
 * @brief: this function set the chosen pin number to (HIGH) active, or (LOW).
 *
 * @param1: this function take (volatile unsigned int*) pointer to a mapped memory that of the GPIO peripherals.
 *
 * @param2: this function take (int) pin number that want to activate.
 *
 * @param3: this function take a (State) which HIGH/LOW to set for the pin.
 *
 * @return: this function return a bool (true/false) to evaluate the pin set state.
 *
 **/
bool pin_set_state(volatile unsigned int*, int, State);

#endif     // RPI_GPIO_GPSET_H_
