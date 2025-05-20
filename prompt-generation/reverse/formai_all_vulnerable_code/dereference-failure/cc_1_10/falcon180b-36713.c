//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

int main() {
    int fd[2];
    pid_t child_pid;
    char buffer[MAX_SIZE];
    int bytes_read;
    int status;

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Pipe created with file descriptors %d and %d\n", fd[0], fd[1]);

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);
        printf("Child process started with PID %d\n", getpid());
        write(fd[1], "Hello from the child!", strlen("Hello from the child!"));
        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        printf("Parent process started with PID %d\n", getpid());
        bytes_read = read(fd[0], buffer, MAX_SIZE);
        buffer[bytes_read] = '\0';
        printf("Message received from the child: %s\n", buffer);
        waitpid(child_pid, &status, 0);
        exit(0);
    }

    return 0;
}