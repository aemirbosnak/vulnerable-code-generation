//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
// A Unix-like Shell Program in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to read user input
char *read_input(void) {
    char *input = NULL;
    ssize_t buffer_size = 0;
    getline(&input, &buffer_size, stdin);
    return input;
}

// Function to split user input into separate arguments
char **split_input(char *input) {
    char **tokens = malloc(64 * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(input, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

// Function to execute user input
int execute_input(char **args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing process");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork error
        perror("Error forking");
    } else {
        // Parent process
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

// Function to handle built-in shell commands
int handle_input(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    return execute_input(args);
}

// Main function for the Shell program
int main(void) {
    char *input_line;
    char **args;
    int status;

    printf("\nWelcome to the Unix-like Shell!\n");

    do {
        printf(">>> ");
        input_line = read_input();
        args = split_input(input_line);
        status = handle_input(args);

        free(input_line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}