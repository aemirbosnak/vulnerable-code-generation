//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 100

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    if (pid == 0) {  // Child process
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);
    } else {  // Parent process
        wait(NULL);  // Wait for child process to finish
    }
}

void shell_loop() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_ARGS];

    while (1) {
        printf("myshell> ");
        getline(&input, &len, stdin); // Read user input

        // Remove trailing newline character
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        // Tokenize the input into arguments
        char *token = strtok(input, " ");
        int arg_count = 0;
        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;  // Null-terminate the argument list

        // Built-in commands
        if (arg_count == 0) {
            continue;  // No command entered
        } else if (strcmp(args[0], "exit") == 0) {
            free(input);
            exit(0);  // Exit the shell
        } else if (strcmp(args[0], "cd") == 0) {
            if (arg_count < 2) {
                fprintf(stderr, "cd: missing argument\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd failed");
                }
            }
        } else if (strcmp(args[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  cd <directory>  Change directory\n");
            printf("  exit            Exit the shell\n");
            printf("  help            Display this help message\n");
        } else {
            execute_command(args);  // Execute external command
        }
    }
}

int main() {
    shell_loop();
    return 0;
}