//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to execute a command and wait for it to finish
void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking process.\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error executing command '%s'.\n", tokens[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

// Function to handle input and execute commands
void handle_input(char *input) {
    char **tokens = split_string(input);
    execute_command(tokens);
    for (int i = 0; tokens[i]!= NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}