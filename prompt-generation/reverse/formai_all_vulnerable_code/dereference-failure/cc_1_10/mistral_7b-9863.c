//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
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

char **tokens;
int num_tokens;

void split_input_into_tokens(char *line) {
    char *token = strtok(line, " ");
    num_tokens = 0;

    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    tokens[num_tokens] = NULL;
}

void execute_command() {
    pid_t pid;
    int status;
    int i;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("Error changing directory");
        }
        return;
    }

    if (strcmp(tokens[0], "echo") == 0) {
        for (i = 1; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
        return;
    }

    pid = fork();

    if (pid == 0) { // Child process
        if (execvp(tokens[0], tokens) < 0) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) { // Parent process
        waitpid(pid, &status, 0);
    } else {
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    int i;

    tokens = (char **) malloc(MAX_NUM_TOKENS * sizeof(char *));

    while (1) {
        printf("Shell> ");
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line)] = '\0';
        split_input_into_tokens(line);

        for (i = 0; tokens[i] != NULL; i++) {
            printf("Token %d: %s\n", i, tokens[i]);
        }

        execute_command();
    }

    free(tokens);
    return 0;
}