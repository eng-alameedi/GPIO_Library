//
// File: rpi_gpio_gpclr.h
//
// this file contain the definition of the
// GPCLR functions for the GPIO pin on the
// BCM2837 board. this function clear the
// output state of the pin.
//

#ifndef _RPI_GPIO_GPCLR_H_
#define _RPI_GPIO_GPCLR_H_

#define GPCLR0_OFFSET     (0x28)                     // this is the offset for the clear function 0 address
#define GPCLR1_OFFSET     (0x2C)                     // this is the offset for the clear function 1 address

#define CLEAR_PIN          (1)                       // define the clear state of the gpio pin (1 clear, 0 no effect)

/**
 *
 * @brief: this function select the right clear offset depend on pin number
 *
 * @param1: this function take (int) pin number.
 *
 * @return: this function return (unsigned int) offset of the clear number (1,0)
 *
 */
unsigned int pin_clear_offset(int);

/**
 *
 * @brief: this function clear the state of the selected output pin.
 *
 * @param1: this function take a (volatile unsigned int*) pointer to the memory address of the gpio.
 *
 * @param2: this function take a (int) pin number.
 *
 * @return: this function return no thing (void).
 *
 */
void pin_clear_state(volatile unsigned int*, int);
#endif     // _RPI_GPIO_GPCLR_H_
