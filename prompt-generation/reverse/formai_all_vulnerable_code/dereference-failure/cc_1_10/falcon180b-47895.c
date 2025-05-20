//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char name[32];
} person_t;

int main() {
    int fd[2];
    pid_t child_pid;

    // Create pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed: %s\n", strerror(errno));
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);
        write(fd[1], "Hello, World!", strlen("Hello, World!"));
        close(fd[1]);
        return 0;
    } else {
        // Parent process
        close(fd[1]);
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = read(fd[0], buffer, BUFFER_SIZE);

        if (bytes_read == -1) {
            fprintf(stderr, "Read failed: %s\n", strerror(errno));
            return 1;
        }

        buffer[bytes_read] = '\0';
        printf("Received message: %s\n", buffer);

        close(fd[0]);
        return 0;
    }
}