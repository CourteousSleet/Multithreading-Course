#include "../headers/NamedChannels.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void NamedChannels::Execute() {
    if (mkfifo("/home/user/in.fifo", 0666) == -1) {
        perror("mkfifo in.fifo failed");
        exit(1);
    }
    if (mkfifo("/home/user/out.fifo", 0666) == -1) {
        perror("mkfifo out.fifo failed");
        exit(1);
    }

    int in_fd = open("/home/user/in.fifo", O_RDONLY);
    if (in_fd == -1) {
        perror("open in.fifo failed");
        exit(1);
    }

    int out_fd = open("/home/user/out.fifo", O_WRONLY);
    if (out_fd == -1) {
        perror("open out.fifo failed");
        exit(1);
    }

    char buffer[512];
    ssize_t readBytes;
    while ((readBytes = read(in_fd, buffer, sizeof(buffer))) > 0) {
        write(out_fd, buffer, readBytes);
    }

    close(in_fd);
    close(out_fd);
}
