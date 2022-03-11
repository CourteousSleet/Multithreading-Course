#ifndef MULTITHREADING_COURSE__ZOMBIEPROCESS_HPP_
#define MULTITHREADING_COURSE_ZOMBIEPROCESS_HPP_

#include "IProcess.hpp"

class ZombieProcess : public IProcess {
  void Execute() override;
};

#endif //MULTITHREADING_COURSE__ZOMBIEPROCESS_HPP_
