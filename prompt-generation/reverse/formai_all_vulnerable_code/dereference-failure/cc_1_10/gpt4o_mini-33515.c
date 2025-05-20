//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define MAX_CMD_SIZE 100
#define DELIM " \n"

// Function to execute a command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Function to parse input into commands and arguments
void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, DELIM);
    
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, DELIM);
    }
    args[i] = NULL;  // Null-terminate the arguments
}

// Function to display a welcome message
void display_welcome() {
    printf("Welcome to My Simple Shell!\n");
    printf("Type 'exit' to quit the shell.\n");
}

// Function to handle built-in commands
int handle_builtin_commands(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }
    return 0; // Not a built-in command
}

// Main shell loop
int main() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_ARG_SIZE];

    display_welcome();

    while (1) {
        printf("my_shell> ");
        getline(&input, &len, stdin);

        if (strlen(input) == 0) {
            continue; // Empty input
        }

        // Handle built-in commands
        if (handle_builtin_commands(args) != 0) {
            continue; // Skip if it's a built-in command
        }

        // Parse the input
        parse_input(input, args);

        // Execute the command
        execute_command(args);
    }

    free(input);
    return 0;
}