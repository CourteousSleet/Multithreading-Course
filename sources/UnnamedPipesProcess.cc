#include "../headers/UnnamedPipesProcess.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

void UnnamedPipesProcess::Execute() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    char command[512];
    fgets(command, 512, stdin);
    command[strlen(command) - 1] = '\0';

    int fd[2];
    pipe(fd);
    int pid = fork();

    if (pid == 0) {

        close(fd[STDIN_FILENO]);
        dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
        close(fd[STDOUT_FILENO]);

        FILE *fp = popen(command, "w");
        if (fp == NULL) {
            perror("popen failed");
            exit(1);
        }

        char buffer[512];
        while (fgets(buffer, 512, fp) != NULL) {
            printf("%s", buffer);
        }

        pclose(fp);

        exit(0);

    } else {

        close(fd[STDOUT_FILENO]);
        dup2(fd[STDIN_FILENO], STDIN_FILENO);
        close(fd[STDIN_FILENO]);

        int file_descriptor = open("./result.out", O_RDWR | O_CREAT | O_TRUNC, 0666);
        if (file_descriptor == -1) {
            perror("open failed");
            exit(1);
        }

        char buffer[512];
        int readBytes;
        while ((readBytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
            write(file_descriptor, buffer, readBytes);
        }

        close(file_descriptor);
        wait(NULL);
    }
}
