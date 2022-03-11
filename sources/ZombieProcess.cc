#include "../headers/ZombieProcess.hpp"

void ZombieProcess::Execute() {
  pid_t current_pid;

  if ((current_pid = fork())) {
    FILE *file = fopen("pid_parent", "w");

    if (!file) {
      perror("File creation error\n");
      exit(EXIT_FAILURE);
    }

    fprintf(file, "%d", getpid());
    if (fclose(file)) perror("File close error\n");

    file = fopen("pid_child", "w");
    if (!file) {
      perror("File creation error\n");
      exit(EXIT_FAILURE);
    }

    fprintf(file, "%d", current_pid);
    if (fclose(file)) perror("File close error\n");

    waitpid(current_pid, nullptr, 0);

  }

  pause();
  exit(EXIT_SUCCESS);
}
