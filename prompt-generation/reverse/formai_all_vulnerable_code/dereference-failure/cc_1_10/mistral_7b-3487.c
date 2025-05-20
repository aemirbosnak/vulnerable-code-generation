//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64

char **tokens;
int num_tokens;

void split_line(char *line) {
    char *token = strtok(line, " ");
    num_tokens = 0;
    tokens = malloc(MAX_TOKENS * sizeof(char *));

    while (token != NULL) {
        tokens[num_tokens++] = strdup(token);
        token = strtok(NULL, " ");
    }

    tokens[num_tokens] = NULL;
}

int main() {
    char input[MAX_INPUT_SIZE];
    pid_t child_pid;
    int status;

    printf("Shell> ");

    while (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        split_line(strdup(input));

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            execvp(tokens[0], tokens);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }

        wait(&status);

        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);

        memset(input, 0, MAX_INPUT_SIZE);
        printf("Shell> ");
    }

    return 0;
}