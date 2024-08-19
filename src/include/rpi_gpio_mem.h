//
// File: rpi_gpio_mem.h
//
// this header file contain's the functions
// to map a block of memory that interact,
// with the gpio pin's of the board BCM2837,
// which used in raspberry pi 3 A, and B,
// and also the necessary function to unmap,
// the reserved block of memory.
//

#ifndef _RPI_GPIO_MEM_H_
#define _RPI_GPIO_MEM_H_

#define BCM2837_PERI_BASE 0x3F000000                                // Physical Base address for the peripherals.
#define GPIO_PERI_OFFSET  0x200000                                  // Physical offset address for the GPIO.
#define GPIO_BASE         (BCM2837_PERI_BASE + GPIO_PERI_OFFSET)    // Base address for the GPIO controller

#define BLOCK_SIZE        (4 * 1024)                                // Memory block (4KB), of the memory region for mmap() function

#include <fcntl.h>                                                  // for call the open() function.
#include <sys/mman.h>                                               // for call the mmap() function.
#include <unistd.h>                                                 // for call the close() function.

/**
 *
 * @brief: this function is used to map a block of memory on BCM2837
 * board that contains the gpio addresses
 *
 * @param: this function take no parameter
 *
 * @return: this function return a pointer to a memory address
 *
 **/
volatile unsigned int* map_peri_mem();

/**
 *
 * @brief: this function used to unmap the memory address.
 *
 * @param: this function take a pointer to unsigned int (memory location)
 *
 * @return: this function return nothing (void).
 *
 **/
void unmap_peri_mem(volatile unsigned int*);

#endif      // _RPI_GPIO_MEM_H_
