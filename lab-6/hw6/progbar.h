// progress bar
#ifndef PROGBAR_H
#define PROGBAR_H

#include <iostream>

class progbar {
public:
  progbar(std::ostream&);
  void operator()(double);
private:
  std::ostream& stream;  
};
#endif
