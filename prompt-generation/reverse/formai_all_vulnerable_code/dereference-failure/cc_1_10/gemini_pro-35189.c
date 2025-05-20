//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split the command line into arguments
char **split_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg;
    int i = 0;

    while ((arg = strtok(line, " ")) != NULL) {
        args[i++] = arg;
        line = NULL;
    }

    args[i] = NULL;

    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;

        // Wait for the child process to complete
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }

    return 0;
}

// Main function
int main(int argc, char **argv) {
    char *line;
    char **args;
    int status;

    // Get the command line from the user
    while (1) {
        printf("> ");
        fflush(stdout);

        line = malloc(sizeof(char) * MAX_LINE_LENGTH);

        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        // Split the command line into arguments
        args = split_args(line);

        // Execute the command
        status = execute_command(args);

        // Free the memory allocated for the arguments
        free(args);

        // Check if the user entered the exit command
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
    }

    // Free the memory allocated for the command line
    free(line);

    return 0;
}