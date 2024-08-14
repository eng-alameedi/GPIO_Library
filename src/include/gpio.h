//
// File: gpio.h
//
// This file contain the base definition of raspberry pi
// GPIO control throw memory, and registry manipulate in
// the system file "/dev/mem". this project will be test
// on a board ("BCM2837").
//

#ifndef _GPIO_H_
#define _GPIO_H_

#define BCM_BASE_PERI 0x3F000000                         // memory base address for the peripheral of the board BCM2837 (Raspberry PI Model 3 B+ ver 1.3)
#define GPIO_BASE_OFFSET (BCM_BASE_PERI + 0x200000)      // Base address of the GPIO (offset from the Peripheral address)
#define BLOCK_SIZE (4*1024)                              // Set the memory map length to 4KB

#include <fcntl.h>            // for using of open() function
#include <sys/mman.h>         // for using mmap() function
#include <unistd.h>           // for using of close() function

/**
 *
 * @brief: this function map a size of memory (4Kb) on virtual memory by using the file (/dev/mem)
 *
 * @param: this function take no parameter.
 *
 * @return: this function return (true) if mapping success, and false if not
 *
 */
bool gpio_setup();

#endif    // _GPIO_H_
