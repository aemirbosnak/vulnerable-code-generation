//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char input[MAX_INPUT_SIZE];
char **tokens;
int num_tokens;

void tokenize(char *line) {
    char *token = strtok(line, " \t\r\n");
    num_tokens = 0;
    tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    tokens[num_tokens] = NULL;
}

void exec_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error forking process");
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

int main() {
    char *args[MAX_NUM_TOKENS];

    while (1) {
        printf("Shell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';

        tokenize(input);
        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        for (int i = 0; i < num_tokens; i++) {
            args[i] = tokens[i];
        }

        exec_command(args);
    }

    return 0;
}