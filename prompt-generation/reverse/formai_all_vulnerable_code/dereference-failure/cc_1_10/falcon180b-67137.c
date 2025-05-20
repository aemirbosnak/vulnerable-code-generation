//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    int bytes_read = 0;
    int fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);

        // Read from stdin and write to pipe
        while ((bytes_read = read(0, buffer, MAX_BUFFER_SIZE)) > 0) {
            write(fd[1], buffer, bytes_read);
        }

        // Close the pipe and exit
        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);

        // Read from pipe and write to stdout
        while ((bytes_read = read(fd[0], buffer, MAX_BUFFER_SIZE)) > 0) {
            buffer_size += bytes_read;
            buffer[buffer_size] = '\0';
            printf("%s", buffer);
            memset(buffer, 0, MAX_BUFFER_SIZE);
        }

        // Close the pipe and exit
        close(fd[0]);
        exit(0);
    }

    return 0;
}