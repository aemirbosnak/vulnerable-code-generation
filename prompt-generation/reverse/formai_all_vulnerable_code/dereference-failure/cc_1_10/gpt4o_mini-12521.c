//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_TOKENS 100
#define DELIM " \n"

// Function to execute built-in commands
int execute_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
        return 1; // Built-in command executed
    }
    return 0; // Not a built-in command
}

// Function to read input from the user
char *read_input() {
    char *input = (char *)malloc(MAX_INPUT_SIZE);
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL; // Error or EOF
    }
    return input;
}

// Function to parse the input into tokens
char **parse_input(char *input) {
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = strtok(input, DELIM);
    int position = 0;
    
    while (token != NULL && position < MAX_NUM_TOKENS - 1) {
        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL; // Null-terminate the list of tokens
    return tokens;
}

// Function to execute a command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE); // Exit child process if exec fails
    } else if (pid < 0) {
        perror("shell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Main shell loop
void shell_loop() {
    char *input;
    char **args;
    
    while (1) {
        printf("myshell> ");
        input = read_input();
        
        if (input == NULL) {
            printf("\n");
            break; // Exit on EOF
        }

        args = parse_input(input);
        
        // Check for built-in commands
        if (!execute_builtin(args)) {
            execute_command(args); // Execute external command
        }

        free(input);
        free(args);
    }
}

// Entry point of the shell
int main() {
    shell_loop(); // Start the shell loop
    return 0; // This point should never be reached
}