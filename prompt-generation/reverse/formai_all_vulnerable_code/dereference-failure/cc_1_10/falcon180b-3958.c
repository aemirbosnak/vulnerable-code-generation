//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

// Message structure
typedef struct {
    int type;
    char message[BUFFER_SIZE];
} message_t;

int main() {
    int fd[2];
    pid_t child_pid;

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Error creating pipe: %s\n", strerror(errno));
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1) {
        printf("Error forking: %s\n", strerror(errno));
        return 1;
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe
        while (TRUE) {
            char input[BUFFER_SIZE];
            printf("Child: Enter a message (type 'exit' to quit): ");
            fgets(input, BUFFER_SIZE, stdin);

            // Send message to parent
            message_t message;
            strcpy(message.message, input);
            message.type = atoi(input);

            write(fd[1], &message, sizeof(message));

            if (strcmp(input, "exit") == 0) {
                break;
            }
        }
        close(fd[1]); // Close writing end of pipe
        exit(0);
    } else {
        // Parent process
        close(fd[1]); // Close writing end of pipe
        while (TRUE) {
            // Receive message from child
            message_t message;
            read(fd[0], &message, sizeof(message));

            if (message.type == 0) {
                printf("Parent: Child exited\n");
                break;
            } else {
                printf("Parent: Message from child: %s\n", message.message);
            }
        }
        close(fd[0]); // Close reading end of pipe
        exit(0);
    }

    return 0;
}