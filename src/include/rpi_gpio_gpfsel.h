//
// File: rpi_gpio_gpfsel.h
//
// this file contain the main definition of,
// the GPFSEL0: gpio pin (0,1,2,3,4,5,6,7,8,9)
// the GPFSEL1: gpio pin (10,11,12,13,14,15,16,17,18,19)
// the GPFSEL2: gpio pin (20,21,22,23,24,25,26,27,28,29)
// the GPFSEL3: gpio pin (30,31,32,33,34,35,36,37,38,39)
// the GPFSEL4: gpio pin (40,41,42,43,44,45,46,47,48,49)
// the GPFSEL5: gpio pin (50,51,52,53)
// of the total gpio banks the raspberry pi pins.
//

#ifndef _RPI_GPIO_GPFSEL_H_
#define _RPI_GPIO_GPFSEL_H_

#define GPFSEL0_OFFSET   (0x00)                    // GPIO function select 0 address offset
#define GPFSEL1_OFFSET   (0x04)                    // GPIO function select 1 address offset
#define GPFSEL2_OFFSET   (0x08)                    // GPIO function select 2 address offset
#define GPFSEL3_OFFSET   (0x0c)                    // GPIO function select 3 address offset
#define GPFSEL4_OFFSET   (0x10)                    // GPIO function select 4 address offset
#define GPFSEL5_OFFSET   (0x14)                    // GPIO function select 5 address offset

enum pin_mode {INPUT=0, OUTPUT=1, ALTERNET=4};     // enumeration for gpio mode selection (out, int, alternate) for chosen pin.

/**
 *
 * @brief: this function used to activate the pin for (input, output, or alternate)
 *
 * @param1: this function take a pointer to memory address for the GPFSEL number.
 *
 * @param2: this function take a integer pint number.
 *
 * @return: this function will return nothing (void).
 *
 **/
void gpsel_gpio_pin(volatile unsigned int*, int, pin_mode);

/**
 *
 * @brief: this function is used to select the right offset depend on pin number.
 *
 * @param1: this function take (unsigned int&) take a offset address by reference.
 *
 * @param2: this function take pin number of type (int)
 *
 * @return: this function return a bool type true or false.
 *
 **/
bool offset_select(unsigned int&, int);

/**
 *
 * @brief: this function reset the mode of the chosen gpio pin (by shifting number 7 in binary (111)) to the start of selected bit.
 *
 * @param1: this function take (unsigned int&) offset of the selected FSEL bank depend on pin number.
 *
 * @param2: this function take (int) pin number.
 *
 * @return: this function return nothing (void)
 *
 **/
void reset_pin_mode(volatile unsigned int*, int);

/**
 *
 * @brief: this function set the mode of the chosen gpio pin (000) for input, (001) for output, (100) for alternate
 *
 * @param1: this function take (volatile unsigned int*) represent the mapped memory block.
 *
 * @param2: this function take (int) for the pin number.
 *
 * @param3: this function take (pin_mode) enum (output,input,alternate)
 *
 * @return: this function return nothing (void)
 *
 **/
void set_pin_mode(volatile unsigned int*, int, pin_mode);

#endif     // _RPI_GPIO_GPFSEL_H_
