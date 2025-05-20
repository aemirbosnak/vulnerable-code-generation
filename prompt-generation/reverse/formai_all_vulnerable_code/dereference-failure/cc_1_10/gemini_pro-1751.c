//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

// Function to parse the command line into arguments
char **parse_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg = strtok(line, " ");
    int i = 0;
    while (arg != NULL && i < MAX_ARGS) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        fprintf(stderr, "Error: execvp failed\n");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Fork failed
        fprintf(stderr, "Error: fork failed\n");
        return 1;
    }
    return 0;
}

// Main function
int main() {
    char line[MAX_LINE_LENGTH];
    while (1) {
        // Print the prompt
        printf("my_shell> ");

        // Read the command line
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Parse the command line into arguments
        char **args = parse_args(line);

        // Execute the command
        execute_command(args);

        // Free the arguments
        free(args);
    }

    return 0;
}