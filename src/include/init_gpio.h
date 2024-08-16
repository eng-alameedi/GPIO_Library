#ifndef _INIT_GPIO_H_
#define _INII_GPIO_H_

void init_pin(int,char);

#define pin_init(pin) Gpio gpin##pin(pin)

#endif // _INIT_GPIO_H_
