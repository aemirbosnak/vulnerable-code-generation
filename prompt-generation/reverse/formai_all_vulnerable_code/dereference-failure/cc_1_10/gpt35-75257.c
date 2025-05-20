//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int main() {
    char* line = malloc(MAX_INPUT_SIZE);
    char* tokens[MAX_NUM_TOKENS];
    char* token;
    int num_tokens;

    while (1) {
        /* Print prompt */
        printf("multivariable-shell$ ");

        /* Read input */
        if (!fgets(line, MAX_INPUT_SIZE, stdin))
            break;

        /* Tokenize input */
        token = strtok(line, " \t\n\r");
        num_tokens = 0;
        while (token && num_tokens < MAX_NUM_TOKENS) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, " \t\n\r");
        }
        tokens[num_tokens] = NULL;

        /* Exit if no tokens */
        if (num_tokens == 0)
            continue;

        /* Handle built-in commands */
        if (strcmp(tokens[0], "exit") == 0)
            return 0;

        /* Fork and exec command */
        int child_pid = fork();
        if (child_pid == 0) {
            /* Child process */
            execvp(tokens[0], tokens);
            printf("Command not found: %s\n", tokens[0]);
            exit(1);
        } else if (child_pid > 0) {
            /* Parent process */
            wait(NULL);
        } else {
            printf("Fork failed\n");
            exit(1);
        }
    }

    free(line);
    return 0;
}