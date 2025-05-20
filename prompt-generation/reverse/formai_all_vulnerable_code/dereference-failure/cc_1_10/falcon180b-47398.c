//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 20

// Function prototypes
char **split_command(char *command);
int execute_command(char **args);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        args = split_command(input);
        execute_command(args);
    }

    return 0;
}

// Splits a command into an array of arguments
char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(command, " ");
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    return args;
}

// Executes a command and prints the result
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

// Prints the prompt
void print_prompt() {
    printf("unix-shell> ");
}