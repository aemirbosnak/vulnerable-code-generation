//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PATH "./pipe"

void read_from_pipe(int fd, char* buffer) {
    char read_buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = read(fd, read_buffer, BUF_SIZE)) > 0) {
        read_buffer[bytes_read] = '\0';
        strcat(buffer, read_buffer);
    }
}

void write_to_pipe(int fd, char* message) {
    int bytes_written;

    bytes_written = write(fd, message, strlen(message));
    if (bytes_written < 0) {
        printf("Error writing to pipe: %s\n", strerror(errno));
    }
}

int main() {
    int fd[2];
    char read_buffer[BUF_SIZE];
    char write_buffer[BUF_SIZE];

    if (pipe(fd) < 0) {
        printf("Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }

    printf("Pipe created with file descriptors %d and %d\n", fd[0], fd[1]);

    if (fork() == 0) { // Child process
        close(fd[0]);
        write_to_pipe(fd[1], "The world as we knew it is gone...\n");
        close(fd[1]);
        exit(0);
    } else { // Parent process
        close(fd[1]);
        read_from_pipe(fd[0], read_buffer);
        printf("Received message: %s\n", read_buffer);
        close(fd[0]);
        exit(0);
    }

    return 0;
}