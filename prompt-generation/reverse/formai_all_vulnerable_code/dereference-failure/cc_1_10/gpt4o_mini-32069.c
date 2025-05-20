//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define DELIMITER " \t\r\n\a"

void prompt() {
    printf("mysh> ");
}

char *read_input() {
    char *input = malloc(MAX_INPUT_SIZE);
    if (!input) {
        perror("Unable to allocate memory for input");
        exit(EXIT_FAILURE);
    }
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    return input;
}

char **parse_input(char *input) {
    int bufsize = MAX_ARG_SIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        perror("Unable to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, DELIMITER);
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= bufsize) {
            bufsize += MAX_ARG_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                perror("Unable to allocate memory for tokens");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIMITER);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return -1;
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

void free_resources(char **tokens) {
    free(tokens);
}

int main() {
    char *input;
    char **args;
    int status = 1;

    while (status) {
        prompt();
        input = read_input();
        if (strlen(input) == 0) {
            free(input);
            continue;  // If input is empty, restart the loop
        }
        args = parse_input(input);
        if (args[0] != NULL) {
            status = execute_command(args);
        }
        free(input);
        free_resources(args);
    }

    return EXIT_SUCCESS;
}