//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int parent_pipefd[2], child_pipefd[2];
    int status;

    if (pipe(parent_pipefd) == -1 ||
        pipe(child_pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t childpid = fork();

    if (childpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Close unused file descriptors
    close(parent_pipefd[0]);
    close(parent_pipefd[1]);

    if (childpid == 0) {
        // Child process
        close(child_pipefd[0]);
        close(child_pipefd[1]);

        // Read from the parent's pipe
        if (read(parent_pipefd[1], argv[1], strlen(argv[1])) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Print the message
        printf("Child process received: %s\n", argv[1]);

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(child_pipefd[0]);
        close(child_pipefd[1]);

        // Write a message to the child's pipe
        if (write(child_pipefd[1], argv[1], strlen(argv[1])) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Wait for the child process to finish
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        // Close the parent's pipe
        close(parent_pipefd[0]);
        close(parent_pipefd[1]);

        exit(EXIT_SUCCESS);
    }
}