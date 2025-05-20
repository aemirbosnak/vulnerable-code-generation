//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void printPrompt() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s>>> ", cwd);
    } else {
        printf(">>> ");
    }
}

int tokenize(char *line, char **tokens) {
    int tokenCount = 0;
    char *token = strtok(line, " \t\n\r");
    while (token != NULL && tokenCount < MAX_NUM_TOKENS) {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(NULL, " \t\n\r");
    }
    tokens[tokenCount] = NULL;
    return tokenCount;
}

void execute(char **tokens) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork");
        return;
    } else if (pid == 0) {
        /* Child process */
        if (execvp(tokens[0], tokens) == -1) {
            printf("Failed to execute command\n");
        }
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char *line;
    char **tokens;
    tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
    int shouldExit = 0;

    while (!shouldExit) {
        printPrompt();
        line = malloc(sizeof(char) * MAX_INPUT_SIZE);
        fgets(line, MAX_INPUT_SIZE, stdin);
        int tokenCount = tokenize(line, tokens);

        if (tokenCount > 0) {
            if (strcmp(tokens[0], "exit") == 0) {
                shouldExit = 1;
            } else {
                execute(tokens);
            }
        }
        free(line);
    }
    free(tokens);
    return 0;
}