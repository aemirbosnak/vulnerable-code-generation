//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 256 // Maximum length of input string
#define MAX_ARGUMENTS 10     // Maximum number of arguments allowed

// Function to read user input
char *read_input() {
    char *input = malloc(MAX_INPUT_LENGTH * sizeof(char)); // Allocate memory for input
    printf("\n>>> ");                                      // Print prompt
    fgets(input, MAX_INPUT_LENGTH, stdin);                // Get user input
    input[strlen(input) - 1] = '\0';                       // Remove the newline character at the end
    return input;
}

// Function to parse the input string and get arguments
char **parse_input(char *input) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *)); // Allocate memory for arguments
    char *argument = strtok(input, " ");                      // Tokenize input string by space
    int i = 0;
    while (argument != NULL) {
        arguments[i++] = argument;                // Add argument to argument list
        argument = strtok(NULL, " ");             // Move to next token
        if (i >= MAX_ARGUMENTS) {                 // Limit the number of arguments
            printf("Too many arguments!\n");
            break;
        }
    }
    arguments[i] = NULL; // Mark the end of argument list
    return arguments;
}

int main() {
    printf("Welcome to the Happy Shell!\n");
    while (1) {
        char *input = read_input();                // Read user input
        char **arguments = parse_input(input);     // Parse input and get arguments
        if (arguments[0] == NULL) {                // If no arguments, continue loop
            continue;
        }
        if (strcmp(arguments[0], "exit") == 0) {   // If exit command is entered, exit program
            printf("Bye!\n");
            exit(0);
        }
        pid_t pid = fork();                         // Create a child process
        if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) { // Execute the input command
                printf("Invalid command!\n");
            }
            exit(0);
        }
        else if (pid < 0) {                         // Error occurred while forking process
            printf("Error forking process!\n");
        }
        else {
            wait(NULL);                             // Wait for child process to complete
        }
        free(input);                                // Free input memory
        free(arguments);                            // Free argument memory
    }
    return 0;
}