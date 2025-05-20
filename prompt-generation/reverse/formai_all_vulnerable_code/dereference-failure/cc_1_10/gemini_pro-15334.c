//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS 10

// Function to split a string into an array of strings
char **split_string(char *str, char *delim) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *token = strtok(str, delim);
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, delim);
    }
    args[i] = NULL;
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    int pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // If execvp returns, there was an error
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        // Error
        perror("fork");
        return 1;
    }
    return 0;
}

// Main function
int main() {
    char line[MAX_LINE];
    char **args;
    int status;

    while (1) {
        // Print the prompt
        printf("myShell> ");

        // Get the input line
        fgets(line, MAX_LINE, stdin);

        // Split the input line into arguments
        args = split_string(line, " ");

        // Check for empty line
        if (args[0] == NULL) {
            continue;
        }

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("cd: no arguments\n");
            } else {
                chdir(args[1]);
            }
        } else {
            // Execute the command
            status = execute_command(args);
        }

        // Free the arguments
        free(args);
    }

    return 0;
}