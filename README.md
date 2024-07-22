# GPIO_Library
Raspberry Pi GPIO Library in C++, this library will be used on raspberry pi for simple controll of the GPIO pins.

## Brief
In raspberry pi system there is about 40 pins var from 3.5v to 5v digital (can operate on 0 & 1) can be used for read and write signal to the specified pin, below is the simple explanation:

```/sys/class/gpio```
the files tree of the above path is: 

```
/sys/class/gpio/
  |
  |___export
  |
  |___unexport
```

so, when you need to use a pin like (17) just exported it like

```sh echo "17" > export```

so the pin (17) will be ready to use, and new directory will be created

```
/sys/class/gpio/
  |
  |___export
  |
  |___unexport
  |
  |___/gpio17
          |
          |___ many files and directory but the importan is:
              |
              |___direction
              |
              |___value
```

the **direction*** used for set the pin state (out,in) which mean (write,read), while the **value** used for set (0,1) for output or input.
