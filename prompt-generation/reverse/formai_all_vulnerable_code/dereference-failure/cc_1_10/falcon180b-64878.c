//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

// Function prototypes
char **split_command(char *command);
int execute_command(char **arguments);
void print_prompt(char *prompt);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    int status;

    while (1) {
        print_prompt("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input);
        pid = fork();

        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

// Split a command string into an array of arguments
char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;

    token = strtok(command, " ");
    while (token!= NULL) {
        arguments[argc++] = token;
        token = strtok(NULL, " ");
    }
    arguments[argc] = NULL;

    return arguments;
}

// Execute a command and its arguments
int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking process.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

// Print a prompt to the console
void print_prompt(char *prompt) {
    printf("%s", prompt);
}