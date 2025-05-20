//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

// Function to split a string into an array of strings
char** split_string(char* str, char* delim) {
    char** tokens = malloc(sizeof(char*) * MAX_ARGS);
    int i = 0;
    char* token = strtok(str, delim);
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return tokens;
}

// Function to execute a command
int execute_command(char** args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // Error
        return -1;
    }
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the lively C Basic Unix-like Shell!\n");

    // Main loop
    while (1) {
        // Get the command from the user
        printf("> ");
        char* line = NULL;
        size_t len = 0;
        getline(&line, &len, stdin);

        // Split the command into an array of strings
        char** args = split_string(line, " ");

        // Execute the command
        int status = execute_command(args);

        // Check the status of the command
        if (status == -1) {
            printf("Error executing command.\n");
        } else if (status == 1) {
            printf("Command not found.\n");
        }
    }

    // Exit the shell
    return 0;
}