//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        if (tokens == NULL) {
            fprintf(stderr, "Error: memory allocation failed.\n");
            exit(1);
        }
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error: input too long.\n");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0';

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