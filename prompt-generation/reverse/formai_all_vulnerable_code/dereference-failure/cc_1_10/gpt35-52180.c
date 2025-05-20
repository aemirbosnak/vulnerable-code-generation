//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int status;
  
    while (1) {
        printf("shell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Ensure command has at least one argument
        if (strlen(command) == 1) {
            printf("Please provide a command.\n");
            continue;
        }

        // Remove new line character from input
        command[strlen(command) - 1] = '\0';

        // Parse command into arguments
        int i = 0;
        char *arg = strtok(command, " ");
        while (arg != NULL) {
            arguments[i++] = arg;
            arg = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // Handle exit command
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Exiting shell...\n");
            return 0;
        }

        // Fork a new process to execute command
        int pid = fork();

        if (pid < 0) {
            printf("Error: Fork failed.\n");
            continue;
        }

        if (pid == 0) {
            // In child process
            int result = execvp(arguments[0], arguments);

            if (result < 0) {
                printf("Error: Unknown command: %s\n", arguments[0]);
                exit(1);
            }
        }
        else {
            // In parent process
            wait(&status);
        }
    }

    return 0;
}