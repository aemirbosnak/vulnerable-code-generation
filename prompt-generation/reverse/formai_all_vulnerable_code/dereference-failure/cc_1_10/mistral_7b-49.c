//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line) {
    int i = 0, j = 0, token_count = 0;
    char **tokens = (char **)calloc(MAX_NUM_TOKENS, sizeof(char *));

    char *token = strtok(line, " ");
    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;

        token = strtok(NULL, " ");
    }

    tokens[token_count] = NULL;
    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("Error changing directory");
        }
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    char **tokens;

    while (1) {
        printf("> ");
        bzero(line, MAX_INPUT_SIZE);
        fgets(line, MAX_INPUT_SIZE, stdin);

        line[strlen(line) - 1] = '\0';
        tokens = tokenize(line);

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        execute_command(tokens);

        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    return 0;
}