#include "../headers/SocketPair.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>


[[noreturn]] void SocketPair::Execute() {
    int fd[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fd) == -1) {
        perror("socketpair failed");
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        // Child process
        close(fd[0]);
        while(true) {
            char message[256];
            printf("Enter a message to send: ");
            fgets(message, 256, stdin);
            write(fd[1], message, sizeof(message));
        }
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        while(true) {
            char buffer[256];
            ssize_t readBytes = read(fd[0], buffer, sizeof(buffer));
            if(readBytes == 0)
                break;
            buffer[readBytes] = '\0';
            printf("Received message: %s\n", buffer);
        }
        close(fd[0]);
    }
}
