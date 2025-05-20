//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

// Function to split a string into an array of strings
void split(char *str, char **tokens, int max_tokens) {
    int i = 0;
    char *token = strtok(str, " ");
    while (token!= NULL && i < max_tokens) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Function to execute a command and return its exit status
int execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

// Function to handle a single command
void handle_command(char **tokens) {
    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else {
        int status = execute_command(tokens[0]);
        if (status == -1) {
            printf("Error: %s not found\n", tokens[0]);
        }
    }
}

// Function to handle multiple commands
void handle_commands(char *input) {
    char *command = strtok(input, ";");
    while (command!= NULL) {
        char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
        int num_tokens = 0;

        split(command, tokens, MAX_ARGUMENTS);
        handle_command(tokens);

        free(tokens);
        command = strtok(NULL, ";");
    }
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_commands(input);
    }

    return 0;
}