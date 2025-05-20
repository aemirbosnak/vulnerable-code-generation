//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delimiter[2] = { DELIM[0], '\0' };

    token = strtok(string, delimiter);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delimiter);
    }

    tokens = malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }

    bufsize = 0;
    words = 0;
    token = strtok(string, delimiter);
    while (token!= NULL) {
        tokens[words] = malloc((strlen(token) + 1) * sizeof(char));
        if (tokens[words] == NULL) {
            fprintf(stderr, "Error: memory allocation failed.\n");
            exit(1);
        }
        strcpy(tokens[words], token);
        bufsize += strlen(token) + 1;
        words++;
        token = strtok(NULL, delimiter);
    }
    tokens[words] = NULL;

    return tokens;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    printf("Welcome to the romantic shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL)
            continue;

        pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Error: fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            fprintf(stderr, "Error: %s not found.\n", args[0]);
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}