//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TOKEN_DELIM " \t\r\n\a"
#define MAX_COMMANDS 100
#define MAX_INPUT_LENGTH 1024

char *get_input();
char **parse_command(char *input);
void exec_commands(char **commands);

int main() {
    while (1) {
        printf("> ");
        char *input = get_input();
        char **commands = parse_command(input);
        exec_commands(commands);
        free(input);
        free(commands);
    }
    return 0;
}

char *get_input() {
    char *input = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    if (!input) {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }
    fgets(input, MAX_INPUT_LENGTH, stdin);
    return input;
}

char **parse_command(char *input) {
    int buffer_size = MAX_COMMANDS;
    char **tokens = malloc(buffer_size * sizeof(char *));
    if (!tokens) {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }
    char *token = strtok(input, TOKEN_DELIM);
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        if (i >= buffer_size) {
            buffer_size += MAX_COMMANDS;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                perror("allocation error");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[i] = NULL;
    return tokens;
}

void exec_commands(char **commands) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // child process
        if (execvp(commands[0], commands) == -1) {
            perror("execution error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // fork error
        perror("fork error");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}