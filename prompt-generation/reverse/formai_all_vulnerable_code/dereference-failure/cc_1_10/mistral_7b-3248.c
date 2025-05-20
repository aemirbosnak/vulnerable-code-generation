//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char **tokens;
int num_tokens;

void parse_input(char *line) {
    char *token;
    int i = 0;

    num_tokens = 0;
    tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    tokens[num_tokens] = NULL;
}

void execute_command() {
    pid_t pid;
    int status;

    if (num_tokens < 1) {
        printf("Error: No command provided\n");
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork Failed");
        return;
    } else if (pid == 0) {
        if (num_tokens > 1) {
            int i;
            for (i = 1; i < num_tokens; i++) {
                char *arg = tokens[i];
                if (i == 1) {
                    execvp(tokens[0], tokens);
                }
                execvp(arg, tokens + i);
                if (i == num_tokens - 1) {
                    perror("Execution Failed");
                    exit(1);
                }
            }
        } else {
            execvp(tokens[0], tokens);
            perror("Execution Failed");
            exit(1);
        }
    } else {
        wait(&status);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];

    while (1) {
        printf("Shell> ");
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "exit") == 0) {
            break;
        }

        parse_input(line);
        execute_command();
    }

    return 0;
}