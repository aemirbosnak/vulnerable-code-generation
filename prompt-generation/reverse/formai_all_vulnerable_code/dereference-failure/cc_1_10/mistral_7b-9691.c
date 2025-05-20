//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd_parent_to_child, fd_child_to_parent[2], status;
    pid_t pid;

    // Create parent-to-child FIFO
    if (mkfifo(FIFO_NAME, 0666) < 0 && errno != EEXIST) {
        perror("Error creating FIFO");
        exit(EXIT_FAILURE);
    }

    // Create child-to-parent FIFO
    if (pipe(fd_child_to_parent) < 0) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(fd_parent_to_child); // Close parent-to-child FIFO
        close(fd_child_to_parent[0]); // Close read end of child-to-parent pipe

        char message[100];
        memset(message, 0, sizeof(message));
        strcpy(message, "Hello from Parent!");

        write(fd_child_to_parent[1], message, strlen(message) + 1);
        close(fd_child_to_parent[1]); // Close write end of child-to-parent pipe

        wait(&status); // Wait for child process to terminate
    } else { // Child process
        close(fd_parent_to_child); // Close child-to-parent FIFO
        close(STDOUT_FILENO); // Close standard output

        char received_message[100];
        ssize_t bytes_received;

        fd_parent_to_child = open(FIFO_NAME, O_RDONLY);
        bytes_received = read(fd_parent_to_child, received_message, sizeof(received_message) - 1);
        if (bytes_received > 0) {
            received_message[bytes_received] = '\0';
            printf("Received message: %s\n", received_message);
        }

        close(fd_parent_to_child);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}