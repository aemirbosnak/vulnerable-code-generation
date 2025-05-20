//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1000
#define DELIM " \t\r\n\a"

char **split(char *line) {
    char **tokens = NULL;
    int count = 0;
    int len = strlen(line);
    char *token;

    if (len == 0) {
        tokens = malloc(sizeof(char *));
        tokens[0] = NULL;
        return tokens;
    }

    token = strtok(line, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

int main() {
    char line[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);

        args = split(line);
        if (args[0] == NULL) {
            free(args);
            continue;
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        }

        waitpid(pid, &status, 0);
        free(args);
    }

    return 0;
}