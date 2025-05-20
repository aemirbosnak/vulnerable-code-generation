//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    int num_tokens;
    int status;
    pid_t child_pid;
    int i;

    while (1) {
        printf("FantasyShell> ");
        fgets(input, sizeof(input), stdin);
        num_tokens = tokenize(input, tokens);

        if (num_tokens == 0) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        if (strcmp(tokens[0], "cd") == 0 && num_tokens > 1) {
            if (chdir(tokens[1]) != 0) {
                perror("Error changing directory");
            }
            continue;
        }

        child_pid = fork();

        if (child_pid < 0) {
            perror("Error forking process");
            continue;
        }

        if (child_pid > 0) {
            wait(&status);
            continue;
        }

        if (execvp(tokens[0], tokens) < 0) {
            perror("Error executing command");
            exit(1);
        }

        for (i = 0; i < num_tokens; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    return 0;
}

int tokenize(char *input, char **tokens) {
    char *token;
    int num_tokens = 0;
    char *line_copy = malloc(strlen(input) + 1);
    strcpy(line_copy, input);

    token = strtok(line_copy, " ");

    tokens[num_tokens] = token;
    num_tokens++;

    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            tokens[num_tokens] = token;
            num_tokens++;
        }
    }

    free(line_copy);

    return num_tokens;
}