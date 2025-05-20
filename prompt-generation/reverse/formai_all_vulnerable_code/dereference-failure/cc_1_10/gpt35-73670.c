//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// Function to print the shell prompt
void printPrompt() {
    printf("$$$ ");
}

// Function to read user input
char *readInput() {
    char *input = malloc(sizeof(char) * MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);
    return input;
}

// Function to tokenize the input
char **tokenizeInput(char *input) {
    char **tokens = malloc(MAX_NUM_TOKENS * sizeof(char));
    if (tokens == NULL) {
        fprintf(stderr, "Error: Token allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(input, " \t\n\r");
    int tokenIndex = 0;
    while (token != NULL) {
        tokens[tokenIndex] = token;
        tokenIndex++;

        if (tokenIndex == MAX_NUM_TOKENS) {
            fprintf(stderr, "Error: Too many arguments\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \t\n\r");
    }
    tokens[tokenIndex] = NULL;
    return tokens;
}

// Function to execute the user command
void executeCommand(char **tokens) {
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Forking failed\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error: Execution failed\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else {
        // Parent process
        wait(NULL);
    }
}

// Main function
int main() {
    while (1) {
        printPrompt();
        char *input = readInput();
        char **tokens = tokenizeInput(input);
        executeCommand(tokens);

        free(input);
        free(tokens);
    }
    return 0;
}