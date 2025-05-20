//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2];
    pid_t child_pid;
    char buffer[BUFFER_SIZE];

    // Create a pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed: %s\n", strerror(errno));
        return 1;
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe

        // Write to pipe
        snprintf(buffer, BUFFER_SIZE, "Hello from child process! ");
        write(fd[1], buffer, strlen(buffer));

        // Close writing end of pipe
        close(fd[1]);

        return 0;
    } else {
        // Parent process
        close(fd[1]); // Close writing end of pipe

        // Read from pipe
        char c;
        while (read(fd[0], &c, 1) > 0) {
            printf("%c", c);
        }

        // Close reading end of pipe
        close(fd[0]);

        return 0;
    }
}