//
// File: gpio.cpp
//
// This file is the implementation of the
// gpio pin mapping of memory with the use
// of the file /dev/mem and gpio address
// of the BCM2837 board.
//

#include "gpio.h"

extern "C" {
  #include "iLog.h"
}

#include <cstddef>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

bool gpio_setup()
{
  volatile unsigned* gpio;                  // gpio mapped pin port (may be moved to the header file gpio.h)
  int mem_file {0};                         // file used to map the gpio address to memory
  void* gpio_map;                           // pointer of type unknown to map the gpio pin address
  const char* system_file{"/dev/mem"};      // unix based system memory mapping file.
  if((mem_file = open(system_file, O_RDWR|O_SYNC)) < 0)
    {
      LOG(ERROR, "Can't Access the file /dev/mem, try check permission\n");
      return false;
    }

  gpio_map = mmap( NULL,
                   BLOCK_SIZE,
                   PROT_READ|PROT_WRITE,
                   MAP_SHARED,
                   mem_file,
                   GPIO_BASE_OFFSET
                   );
  close(mem_file);
  if(gpio_map == MAP_FAILED)
    {
      LOG(ERROR, "Error Mapping File\n");
      return false;
    }
  gpio = (volatile unsigned*)gpio_map;
  return true;
}
