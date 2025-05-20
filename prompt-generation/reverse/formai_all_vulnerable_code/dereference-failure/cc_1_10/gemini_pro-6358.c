//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Maximum number of arguments (including the program name)
#define MAX_ARGS 10

// Maximum length of an argument
#define MAX_ARG_LEN 100

// Type definition for a command structure
typedef struct {
    char *argv[MAX_ARGS]; // Array of arguments
    int argc;           // Number of arguments
    int background;     // Flag indicating if the command should run in the background
} Command;

// Function to read a line of input from the user
char *readline() {
    char *line = NULL;
    size_t len = 0;

    // Get a line of input from the user
    getline(&line, &len, stdin);

    // Remove the newline character at the end of the line
    line[strlen(line) - 1] = '\0';

    return line;
}

// Function to parse a line of input into a command structure
Command parse_command(char *line) {
    Command command;

    // Initialize the command structure
    command.argc = 0;
    command.background = 0;

    // Tokenize the line into arguments
    char *token = strtok(line, " ");
    while (token != NULL) {
        // Add the token to the command's argument array
        command.argv[command.argc++] = token;

        // Check for the '&' symbol, which indicates that the command should run in the background
        if (strcmp(token, "&") == 0) {
            command.background = 1;
            break;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Null-terminate the argument array
    command.argv[command.argc] = NULL;

    return command;
}

// Function to execute a command
int execute_command(Command command) {
    // Fork a new process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        // Execute the command
        execvp(command.argv[0], command.argv);

        // If execvp() returns, it means that the command was not found
        fprintf(stderr, "Error: command not found\n");

        // Exit the child process
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        if (!command.background) {
            // Wait for the child process to complete
            waitpid(pid, NULL, 0);
        }
    } else {
        // Fork failed
        fprintf(stderr, "Error: fork() failed\n");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main() {
    // Main loop
    while (1) {
        // Prompt the user for input
        printf("myshell> ");

        // Read a line of input from the user
        char *line = readline();

        // Parse the line of input into a command structure
        Command command = parse_command(line);

        // Execute the command
        execute_command(command);

        // Free the memory allocated for the line of input
        free(line);
    }

    return EXIT_SUCCESS;
}