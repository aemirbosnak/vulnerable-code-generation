//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

// Function to split a string into an array of strings
char **split_string(char *str, char *delim) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg;
    int i = 0;

    arg = strtok(str, delim);
    while (arg != NULL) {
        args[i] = arg;
        i++;
        arg = strtok(NULL, delim);
    }

    args[i] = NULL;
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);
    } else {
        // Error forking
        perror("Error forking");
        return 1;
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char *line;
    char **args;
    int status;

    // Read a line from the user
    printf("> ");
    line = malloc(sizeof(char) * 1024);
    fgets(line, 1024, stdin);

    // Split the line into an array of strings
    args = split_string(line, " ");

    // Execute the command
    status = execute_command(args);

    // Free the allocated memory
    free(line);
    free(args);

    return status;
}