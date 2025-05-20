//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int status, i;

    printf("Welcome to my simple shell!\n");

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        // Split the command into arguments
        arguments[0] = strtok(command, " ");
        for (i = 1; i < MAX_ARGUMENTS; i++) {
            arguments[i] = strtok(NULL, " ");
            if (arguments[i] == NULL) {
                break;
            }
        }

        // Check for exit command
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // Fork a child process to execute the command
        pid_t pid = fork();

        // Child process
        if (pid == 0) {
            // Execute the command
            if (execvp(arguments[0], arguments) < 0) {
                printf("Error executing command.\n");
                exit(1);
            }
        }
        // Parent process
        else if (pid > 0) {
            // Wait for the child to complete
            waitpid(pid, &status, 0);
        }
        // Error forking
        else {
            printf("Error forking process.\n");
            exit(1);
        }
    }

    return 0;
}