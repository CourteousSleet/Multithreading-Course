#include "../headers/ZombieProcess.hpp"

void ZombieProcess::Execute() {
  pid_t cpid;

  if ((cpid = fork())) {
    FILE *file = fopen("pid_parent", "w");

    if (!file) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    fprintf(file, "%d", getpid());

    if (fclose(file)) perror("fclose");

    file = fopen("pid_child", "w");

    if (!file) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    fprintf(file, "%d", cpid);

    if (fclose(file)) perror("fclose");

    waitpid(cpid, NULL, 0);

  } else if (cpid == -1) perror("fork");

  pause();

  exit(EXIT_SUCCESS);
}
