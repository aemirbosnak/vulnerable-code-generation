//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokenize(char *line, char **tokens, int *num_tokens) {
    char *token = strtok(line, " \t\r\n");
    int i = 0;
    while (token != NULL) {
        if (i >= *num_tokens) {
            *num_tokens += 16;
            tokens = realloc(tokens, (*num_tokens + 16) * sizeof(char *));
        }
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n");
    }
    tokens[i] = NULL;
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
        wait(&status);
    } else {
        perror("Error forking process");
        exit(1);
    }
}

void read_line(char *line) {
    int c;
    int i = 0;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            line[i] = '\0';
            break;
        }
        line[i] = c;
        i++;
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    int num_tokens;
    while (1) {
        printf("Shell> ");
        read_line(line);
        tokenize(line, tokens, &num_tokens);
        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }
        execute_command(tokens);
        for (int i = 0; i < num_tokens; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
    return 0;
}