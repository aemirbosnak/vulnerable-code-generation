//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split(char *str, int *count) {
    char **tokens = malloc(sizeof(char *));
    int i = 0;
    char *token;

    // Split the string into tokens
    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }

    // Null terminate the array of tokens
    *(tokens + i) = NULL;

    // Return the array of tokens and the count of tokens
    *count = i;
    return tokens;
}

// Function to execute a command and return its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    // Fork a new process to execute the command
    pid = fork();

    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return status;
    }
}

// Function to handle input and execute commands
void handle_input(char *input) {
    int count;
    char **args;

    // Split the input into an array of strings
    args = split(input, &count);

    // Execute the command and print its exit status
    int status = execute_command(args);
    printf("Exit status: %d\n", status);

    // Free the array of strings
    for (int i = 0; i < count; i++) {
        free(args[i]);
    }
    free(args);
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    // Prompt the user for input
    printf("Enter a command: ");

    // Read a line of input from the user
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Handle the input and execute the command
    handle_input(input);

    return 0;
}