#ifndef MULTITHREADING_COURSE__IPROCESS_HPP_
#define MULTITHREADING_COURSE__IPROCESS_HPP_

#include <unistd.h>

#include <csignal>
#include <fstream>

class IProcess {
 public:
  virtual void Execute() = 0;

 protected:

 private:


};

#endif //MULTITHREADING_COURSE__IPROCESS_HPP_