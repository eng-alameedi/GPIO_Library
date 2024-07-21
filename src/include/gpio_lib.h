#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

class Gpio
{
  public:
  Gpio(int&);
  Gpio(int*);
  ~Gpio();
  enum class State: int {WRITE, READ};

  State get_state()const;
  int get_pin()const;
  bool get_ownership()const;

  void set_state(State);
  void error_handle(const char*);
  void read_date();
  void write_date();

  private:
  int* pin_number{0};             // GPIO pin number to use.
  State direction {State::READ};
  bool owner{false};
  static int error_no;
};

#endif // _GPIO_LIB_H_
