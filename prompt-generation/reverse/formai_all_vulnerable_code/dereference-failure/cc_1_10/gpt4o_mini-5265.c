//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024  // Maximum length of command
#define MAX_ARGS 100   // Maximum number of arguments

// Function to execute a command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // Error forking
        perror("shell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Function to parse the input command line
char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int index = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL; // Null-terminate the array of arguments
    return args;
}

// Function to handle built-in commands
int handle_builtin_commands(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        free(args);
        exit(0);
    }
    return 0; // Indicates no built-in command was executed
}

// Main shell loop
void shell_loop() {
    char *input = NULL;
    size_t len = 0;

    while (1) {
        printf("myshell> ");
        getline(&input, &len, stdin);

        if (strlen(input) == 0) {
            continue; // Empty input
        }

        char **args = parse_input(input);

        // Check for built-in commands
        if (handle_builtin_commands(args) == 0) {
            execute_command(args);
        }

        free(args);
    }
    
    free(input); // Free allocated input buffer
}

// Main function
int main() {
    printf("Welcome to My Shell! Type 'exit' to quit.\n");
    shell_loop();
    return 0;
}