//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Maximum command line length
#define MAX_LINE_LENGTH 1024

// Maximum number of arguments in a command line
#define MAX_ARGUMENTS 10

// Type definition for a command line
struct command_line {
    char *arguments[MAX_ARGUMENTS];
    int num_arguments;
};

// Function to parse a command line
void parse_command_line(struct command_line *command_line, char *line) {
    // Tokenize the command line into arguments
    char *token = strtok(line, " ");
    while (token != NULL) {
        // Add the token to the command line arguments
        command_line->arguments[command_line->num_arguments] = token;
        command_line->num_arguments++;

        // Get the next token
        token = strtok(NULL, " ");
    }
}

// Function to execute a command line
void execute_command_line(struct command_line *command_line) {
    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process

        // Execute the command
        execvp(command_line->arguments[0], command_line->arguments);

        // If execvp() returns, there was an error
        perror("execvp");
        exit(1);
    } else if (child_pid > 0) {
        // Parent process

        // Wait for the child process to finish
        int status;
        waitpid(child_pid, &status, 0);
    } else {
        // Error forking
        perror("fork");
    }
}

// Main function
int main() {
    // Loop until the user enters "exit"
    while (1) {
        // Prompt the user for input
        printf("$ ");

        // Get the user's input
        char line[MAX_LINE_LENGTH];
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Parse the command line
        struct command_line command_line;
        parse_command_line(&command_line, line);

        // Execute the command line
        execute_command_line(&command_line);

        // Check if the user entered "exit"
        if (strcmp(command_line.arguments[0], "exit") == 0) {
            break;
        }
    }

    return 0;
}