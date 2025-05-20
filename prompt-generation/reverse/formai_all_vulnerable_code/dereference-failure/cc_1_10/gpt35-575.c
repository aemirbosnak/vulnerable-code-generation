//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_MESSAGE_LENGTH 20

int main()
{
    int pipefd[2];
    pid_t pid;
    char message[MAX_MESSAGE_LENGTH];

    if (pipe(pipefd) == -1) {
        fprintf(stderr, "Error creating pipe: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error creating child process: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close unused write end of the pipe

        // Read message from parent
        memset(message, 0, MAX_MESSAGE_LENGTH);
        read(pipefd[0], message, MAX_MESSAGE_LENGTH);

        printf("Child received message from parent: %s\n", message);

        close(pipefd[0]); // Close read end of pipe

        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[0]); // Close unused read end of the pipe

        // Write message to child
        char *msg = "Hello from parent!";
        write(pipefd[1], msg, strlen(msg) + 1);

        close(pipefd[1]); // Close write end of pipe

        wait(NULL); // Wait for child to finish

        exit(EXIT_SUCCESS);
    }
}