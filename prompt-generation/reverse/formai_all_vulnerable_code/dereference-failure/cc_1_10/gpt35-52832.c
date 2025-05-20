//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

char *message = "Hello, World!";
char *buffer = NULL;

void parent_signal_handler(int signal) {
    if (signal == SIGUSR1) {
        printf("[Parent] Signal Received from Child\n");
    }
}

void child_signal_handler(int signal) {
    if (signal == SIGUSR2) {
        printf("[Child] Signal Received from Parent\n");

        // Write message to the pipe
        int fd = open("pipe", O_WRONLY);
        write(fd, message, strlen(message));
        close(fd);

        // Send signal to parent
        kill(getppid(), SIGUSR1);
    }
}

int main() {
    printf("Starting program...\n");

    // Create pipe
    mkfifo("pipe", 0666);

    // Fork process
    pid_t pid = fork();

    switch (pid) {
        case -1: {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        case 0: {
            // Child process - read from pipe and send signal to parent
            printf("[Child] Running...\n");

            // Register signal handler
            signal(SIGUSR2, child_signal_handler);

            // Wait for signal from parent
            pause();

            // Read from pipe
            int fd = open("pipe", O_RDONLY);
            buffer = (char*)malloc(strlen(message)+1);
            read(fd, buffer, strlen(message)+1);
            close(fd);

            printf("[Child] Received message: %s\n", buffer);
            free(buffer);

            // Send signal to parent
            kill(getppid(), SIGUSR2);

            printf("[Child] Exiting...\n");
            exit(EXIT_SUCCESS);
        }
        default: {
            // Parent process - send signal to child and wait for signal
            printf("[Parent] Running...\n");

            // Register signal handler
            signal(SIGUSR1, parent_signal_handler);

            // Send signal to child
            kill(pid, SIGUSR2);

            // Wait for signal from child
            pause();

            printf("[Parent] Exiting...\n");
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}