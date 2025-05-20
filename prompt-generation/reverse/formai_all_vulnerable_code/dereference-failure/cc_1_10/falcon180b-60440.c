//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_string(char *str);
pid_t launch_shell(char **args);
void execute_command(char **args);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Curious Shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Split input into arguments
        args = split_string(input_buffer);

        // Launch shell if command is "shell"
        if (strcmp(args[0], "shell") == 0) {
            launch_shell(args);
        } else {
            execute_command(args);
        }
    }

    return 0;
}

// Split a string into an array of strings using delimiter
char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Launch a new shell
pid_t launch_shell(char **args) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }

    return pid;
}

// Execute a command
void execute_command(char **args) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}