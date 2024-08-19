//
// File: rpi_gpio_gpfsel.h
//
// this file contain the main definition of,
// the GPFSEL0: gpio pin (1,2,3,4,5,6,7,8,9)
// the GPFSEL1: gpio pin (10,11,12,13,14,15,16,17,18)
// the GPFSEL2: gpio pin (19,20,21,22,23,24,25,26,27)
// the GPFSEL3: gpio pin (28,29,30,31,32,33,34,35,36)
// the GPFSEL4: gpio pin (37,38,39,40,41,42,43,44,45)
// the GPFSEL5: gpio pin (46,47,48,49,50,51,52,53,54)
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

#define OUTPUT           (1)                       // GPIO pin set direction for output voltage (3.3v)
#define INPUT            (0)                       // GPIO pin set direction for input (read voltage)

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
void gpsel_gpio_pin(volatile unsigned int*, int);

#endif     // _RPI_GPIO_GPFSEL_H_
