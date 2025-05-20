//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        // Print shell prompt
        printf(">> ");

        // Read input from user
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Replace newline character with null terminator
        input[strcspn(input, "\n")] = '\0';

        // Parse input into arguments array
        char *token = strtok(input, " ");
        int arg_index = 0;
        while (token != NULL && arg_index < MAX_ARGS - 1) {
            args[arg_index] = token;
            arg_index++;
            token = strtok(NULL, " ");
        }
        args[arg_index] = NULL;

        // Exit shell if user inputs "exit"
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // Fork child process to execute command
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(1);
        } else if (child_pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror(args[0]);
                exit(1);
            }
        } else {
            // Parent process
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}