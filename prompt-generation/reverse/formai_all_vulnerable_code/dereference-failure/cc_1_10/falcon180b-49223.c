//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PATH "/tmp/pipe"

int main() {
    int fd[2];
    char buffer[BUFFER_SIZE];

    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }

    printf("Pipe created\n");

    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed\n");
        exit(1);
    }

    if (child_pid == 0) {
        close(fd[0]);
        write(fd[1], "Hello from child", strlen("Hello from child"));
        close(fd[1]);
        exit(0);
    }

    close(fd[1]);
    char* message = (char*) malloc(BUFFER_SIZE);
    int bytes_read = read(fd[0], message, BUFFER_SIZE);

    if (bytes_read == -1) {
        printf("Read failed\n");
        exit(1);
    }

    printf("Message from child: %s\n", message);

    free(message);
    close(fd[0]);
    return 0;
}