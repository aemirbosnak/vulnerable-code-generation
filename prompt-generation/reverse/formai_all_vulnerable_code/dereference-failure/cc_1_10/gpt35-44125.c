//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_ARGS 10
#define MAX_COMMAND_LENGTH 256

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *tokens[MAX_COMMAND_ARGS];
    int num_tokens;
    pid_t pid;
    int status;

    while (1) {
        printf("$ ");

        // Read input from user
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Tokenize input string
        num_tokens = 0;
        tokens[num_tokens] = strtok(input, " ");
        while (tokens[num_tokens] != NULL) {
            num_tokens++;
            tokens[num_tokens] = strtok(NULL, " ");
        }

        // Exit shell if user enters "exit"
        if (strcmp(tokens[0], "exit") == 0) {
            printf("Bye!\n");
            exit(0);
        }

        // Fork process to execute command
        if ((pid = fork()) == 0) {
            // Child process

            // Execute command with arguments
            execvp(tokens[0], tokens);

            // If execvp returns, command was not found
            printf("Command not found: %s\n", tokens[0]);

            exit(1);
        } else if (pid > 0) {
            // Parent process

            // Wait for child process to complete
            if (waitpid(pid, &status, 0) != -1) {
                if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                    // Child process exited with non-zero status
                    printf("Error executing command: %s\n", input);
                }
            } else {
                // waitpid encountered an error
                printf("Error waiting for process: %s\n", input);
            }
        } else {
            // Failed to fork process
            printf("Error forking process: %s\n", input);
        }
    }

    return 0;
}