//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 64
#define TOKEN_DELIMITERS " \t\r\n\a"

void print_prompt() {
    printf("$ ");
    fflush(stdout);
}

char *read_input() {
    char *input = malloc(MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    return input;
}

char **tokenize_input(char *input) {
    int token_count = 0;
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token = strtok(input, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[token_count] = NULL;
    return tokens;
}

void execute(char **args) {
    int pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Error: Failed to fork process.\n");
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void execute_commands(char **commands) {
    int command_count = 0;
    char **args = malloc(MAX_TOKENS * sizeof(char *));
    char *current_command = commands[command_count++];

    while (current_command != NULL) {
        args[0] = current_command;
        char *input = read_input();
        char **tokens = tokenize_input(input);

        int i = 1;
        while (tokens[i-1] != NULL) {
            args[i] = tokens[i-1];
            i++;
        }
        args[i] = NULL;

        if (strcmp(current_command, "exit") == 0) {
            free(args);
            free(input);
            free(tokens);
            exit(EXIT_SUCCESS);
        } else {
            execute(args);
        }

        free(input);
        free(tokens);
        current_command = commands[command_count++];
    }

    free(args);
}

int main() {
    while (1) {
        print_prompt();

        char *input = read_input();
        char **commands = tokenize_input(input);
        execute_commands(commands);

        free(input);
        free(commands);
    }
    return 0;
}