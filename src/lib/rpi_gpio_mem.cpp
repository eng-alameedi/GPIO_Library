//
// File: rpi_gpio_mem.cpp
//
// this file is contain the implementation,
// of the function map_peri_mem, and the ,
// function unmap_peri_mem.
//

#include "rpi_gpio_mem.h"
#include "iLog.h"

#include <fcntl.h>
#include <sys/mman.h>

volatile unsigned int* map_peri_mem()
{
  const char* mem_file {"/dev/mem"};
  int mem_fd {};
  mem_fd = open(mem_file, O_RDWR | O_SYNC);
  if(mem_fd < 0)
    {
      LOG(ERROR, "Error: Can't Open /dev/mem, Try Check Permissions\n");
      return nullptr;
    }

  void* gpio_mapped_mem;
  gpio_mapped_mem = mmap(nullptr,
                         BLOCK_SIZE,
                         PROT_READ|PROT_WRITE,
                         MAP_SHARED,
                         mem_fd,
                         GPIO_BASE);

  if(gpio_mapped_mem == MAP_FAILED)
    {
      LOG(ERROR, "Error Mapping Memory\n");
      close(mem_fd);
      return nullptr;
    }
  close(mem_fd);
  return (static_cast<volatile unsigned int*>(gpio_mapped_mem));
}

void unmap_peri_mem(volatile unsigned int* gpio)
{
  if(gpio != nullptr)
    {
      if( munmap((void*)gpio, BLOCK_SIZE) < 0)
        LOG(ERROR, "Error un-mapping Memory\n");
    }
}
