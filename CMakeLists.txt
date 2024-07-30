cmake_minimum_required(VERSION 3.30)

project(GPIO_LIBRARY
        VERSION 1.0.0
        LANGUAGES CXX
       )

set(file_name GpioLib)
set(file_path src/lib/gpio_lib.cpp src/lib/init_gpio.cpp src/main.cpp)

include_directories(src/include)
include_directories(/home/alameedi/Github/iLog/build)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(${file_name} ${file_path})

target_link_libraries(${file_name} /home/alameedi/Github/iLog/build/liblog.a)
