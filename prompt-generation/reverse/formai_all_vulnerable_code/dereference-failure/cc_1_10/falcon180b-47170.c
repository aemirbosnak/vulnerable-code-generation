//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2]; // file descriptors for the pipe
    char buffer[BUFFER_SIZE]; // buffer for holding data

    if (pipe(fd) == -1) { // create the pipe
        fprintf(stderr, "Error creating pipe: %s\n", strerror(errno));
        return 1;
    }

    printf("Pipe created, file descriptors are: %d and %d\n", fd[0], fd[1]);

    int pid = fork(); // create a child process

    if (pid == -1) { // fork failed
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) { // child process
        close(fd[0]); // close the reading end of the pipe
        printf("Child process started, writing to pipe\n");

        for (int i = 0; i < 10; i++) { // write 10 messages to the pipe
            sprintf(buffer, "Message %d\n", i);
            write(fd[1], buffer, strlen(buffer));
        }

        close(fd[1]); // close the writing end of the pipe
        return 0;
    } else { // parent process
        close(fd[1]); // close the writing end of the pipe
        printf("Parent process started, reading from pipe\n");

        char ch;
        while (read(fd[0], &ch, 1) > 0) { // read from the pipe character by character
            buffer[0] = ch;
            buffer[1] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(fd[0]); // close the reading end of the pipe
        return 0;
    }
}