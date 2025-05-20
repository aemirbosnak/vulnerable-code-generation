//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Shell commands
#define EXIT_CMD "exit"
#define CD_CMD "cd"

// Prompt for user input
#define PROMPT "SHELL> "

// Maximum input buffer size
#define MAX_INPUT_SIZE 1024

// Main shell loop
int main() {
    // User input buffer
    char input[MAX_INPUT_SIZE];

    // Print welcome message
    printf("Welcome to our amazing shell!\n");

    // Main loop
    while (1) {
        // Print prompt
        printf("%s", PROMPT);

        // Read user input
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character from input
        strtok(input, "\n");

        // Parse input
        char *args[MAX_INPUT_SIZE];
        char *arg = strtok(input, " ");
        int i = 0;
        while (arg != NULL) {
            args[i++] = arg;
            arg = strtok(NULL, " ");
        }

        // Handle built-in commands
        if (strcmp(args[0], EXIT_CMD) == 0) {
            // Exit the shell
            printf("Exiting shell...\n");
            return 0;
        } else if (strcmp(args[0], CD_CMD) == 0) {
            // Change directory
            if (chdir(args[1]) != 0) {
                printf("Error changing directory\n");
            }
        } else {
            // Execute external command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                // If execvp fails, print error and exit
                printf("Error executing command\n");
                exit(1);
            } else if (pid > 0) {
                // Parent process
                wait(NULL);
            } else {
                // Error forking
                printf("Error forking process\n");
            }
        }
    }

    return 0;
}