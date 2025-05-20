//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int tokenize(char *input, char **tokens) {
    int token_count = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL && token_count < MAX_NUM_TOKENS) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;
    return token_count;
}

int main() {
    char *input;
    char *tokens[MAX_NUM_TOKENS];
    int token_count, status;

    while (1) {
        printf("myshell> ");
        input = calloc(MAX_INPUT_SIZE, sizeof(char));
        fgets(input, MAX_INPUT_SIZE, stdin);
        token_count = tokenize(input, tokens);

        if (token_count == 0) {
            free(input);
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            free(input);
            exit(0);
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(tokens[0], tokens);
            printf("execvp failed\n");
            exit(1);
        }
        else if (pid < 0) {
            printf("fork failed\n");
            exit(1);
        }
        else {
            waitpid(pid, &status, 0);
            free(input);
        }
    }

    return 0;
}