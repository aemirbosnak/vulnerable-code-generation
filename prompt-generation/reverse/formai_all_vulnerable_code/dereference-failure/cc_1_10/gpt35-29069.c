//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int status;

    while (1) {
        // Print prompt
        printf("prompt> ");

        // Read command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize command and arguments
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGUMENTS - 1) {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // Handle built-in commands
        if (strcmp(arguments[0], "exit") == 0) {
            exit(0);
        }

        // Fork child process
        pid_t pid = fork();
        if (pid == -1) {
            printf("Error: Failed to fork child process\n");
            continue;
        } else if (pid == 0) {
            // Child process, execute command
            execvp(arguments[0], arguments);
            printf("Error: Failed to execute command: %s\n", command);
            exit(1);
        } else {
            // Parent process, wait for child to finish
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}