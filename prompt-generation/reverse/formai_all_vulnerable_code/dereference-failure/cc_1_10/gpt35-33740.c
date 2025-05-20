//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

int main() {

    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    int argument_count = 0;

    while(1) {

        printf("> ");

        // Get the command from the user.
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        // Remove the newline character from the end of the command.
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command into individual arguments.
        char* token;
        token = strtok(command, " ");
        argument_count = 0;
        while (token != NULL) {
            arguments[argument_count] = token;
            argument_count++;
            token = strtok(NULL, " ");
        }
        arguments[argument_count] = NULL;

        // Exit the shell if the user enters "exit".
        if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        }

        // Fork a child process to execute the command.
        int pid = fork();
        if (pid == -1) {
            printf("Error: Failed to fork.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(arguments[0], arguments);
            printf("Error: Failed to execute command.\n");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }

    }

    return 0;
}