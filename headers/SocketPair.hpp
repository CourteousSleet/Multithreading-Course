#ifndef MULTITHREADING_COURSE_SOCKETPAIR_HPP
#define MULTITHREADING_COURSE_SOCKETPAIR_HPP

#include "IProcess.hpp"

class SocketPair : public IProcess {
    [[noreturn]] void Execute() override;
};


#endif//MULTITHREADING_COURSE_SOCKETPAIR_HPP
