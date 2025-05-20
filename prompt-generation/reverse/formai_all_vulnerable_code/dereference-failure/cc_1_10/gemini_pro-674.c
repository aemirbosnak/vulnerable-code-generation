//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split the input line into arguments
char **split_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg;
    int i = 0;

    // Split the line into arguments by spaces
    while ((arg = strtok(line, " ")) != NULL) {
        args[i++] = arg;
        line = NULL;
    }

    // Terminate the array with a NULL pointer
    args[i] = NULL;

    return args;
}

// Function to execute a command
int execute_command(char **args) {
    // Fork a new process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        // Execute the command using execvp()
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Fork failed
        perror("Error forking");
        return 1;
    }

    return 0;
}

// Main function
int main() {
    // Infinite loop to keep the shell running
    while (1) {
        // Print the prompt
        printf("osh> ");

        // Get the input line from the user
        char line[MAX_LINE_LENGTH];
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Remove the newline character from the end of the input line
        line[strlen(line) - 1] = '\0';

        // Split the input line into arguments
        char **args = split_args(line);

        // Check if the user entered "exit"
        if (strcmp(args[0], "exit") == 0) {
            // Exit the shell
            break;
        }

        // Execute the command
        execute_command(args);

        // Free the arguments
        free(args);
    }

    return 0;
}