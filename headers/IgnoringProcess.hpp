#ifndef MULTITHREADING_COURSE__IGNORINGPROCESS_HPP_
#define MULTITHREADING_COURSE_IGNORINGPROCESS_HPP_

#include "IProcess.hpp"

class IgnoringProcess : public IProcess {
 public:
  [[noreturn]] void Execute() override;

 protected:

 private:


};

#endif //MULTITHREADING_COURSE__IGNORINGPROCESS_HPP_
