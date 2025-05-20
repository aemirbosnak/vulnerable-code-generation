//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings using delimiter
char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token;
    char *context = str;

    while ((token = strsep(&context, DELIM))) {
        count++;
    }

    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    context = str;
    for (int i = 0; i < count; i++) {
        tokens[i] = strdup(strsep(&context, DELIM));
    }
    tokens[count] = NULL;

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
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Command not found\n");
            exit(1);
        }
    }
}

// Function to handle input and execute commands
void handle_input(char *input) {
    char **tokens = split_string(input);
    execute_command(tokens);
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