//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_TOKENS 64

char **tokenize(char *line) {
    char **tokens = (char **)calloc(MAX_TOKENS, sizeof(char *));
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    pid = fork();

    if (pid == 0) {
        if (tokens[1][0] == '/') {
            execvp(tokens[0], tokens);
            fprintf(stderr, "%s: command not found\n", tokens[0]);
            exit(1);
        } else {
            char path[1024];
            snprintf(path, sizeof(path), "/usr/bin/%s", tokens[0]);
            execvp(path, tokens);
            fprintf(stderr, "%s: command not found\n", tokens[0]);
            exit(1);
        }
    } else if (pid > 0) {
        wait(&status);
    } else {
        perror("Fork failed");
        exit(1);
    }
}

int main() {
    char line[MAX_INPUT];
    char **tokens;

    while (1) {
        printf("Shell> ");
        fgets(line, MAX_INPUT, stdin);
        line[strlen(line)] = '\0';
        tokens = tokenize(line);
        if (tokens[0] != NULL) {
            execute_command(tokens);
        }
        free(tokens);
    }

    return 0;
}