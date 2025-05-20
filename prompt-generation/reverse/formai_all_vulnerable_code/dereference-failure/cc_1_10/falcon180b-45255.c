//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *line) {
    int count = 0, i = 0;
    char **tokens = malloc(sizeof(char *));

    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin))!= -1) {
        char **tokens = split(line);

        if (tokens[0] == NULL || strcmp(tokens[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("Execvp");
                exit(1);
            }
        } else {
            waitpid(pid, NULL, 0);
        }

        free(line);
        line = NULL;
        len = 0;
    }

    return 0;
}