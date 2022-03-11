#include "../headers/IgnoringProcess.hpp"

[[noreturn]] void IgnoringProcess::Execute() {
  FILE* f = fopen("/home/box/pid", "w+");
  fprintf(f, "%d", (int) getpid());
  fclose(f);

  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGTERM);
  sigprocmask(SIG_BLOCK, &mask, nullptr);

  pause();
  exit(EXIT_SUCCESS);
}