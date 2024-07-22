#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

class Gpio
{
  public:
  Gpio(int&);
  Gpio(int*);
  ~Gpio();
  enum class State: char {READ, WRITE};

  State get_state()const;
  int get_pin()const;
  bool get_ownership()const;

  void read_date();
  void write_data();
  void error_handle(const char*);

  private:
  int* pin_number{0};             // GPIO pin number to use.
  State direction {State::READ};
  bool owner{false};
  static int error_no;

  bool open_pin();
  bool close_pin();

  void set_state(State);

  int get_value()const;
  void set_value(int);
};

#endif // _GPIO_LIB_H_
