//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

char *read_input() {
    char *line = malloc(MAX_LINE_LENGTH);
    if (!line) {
        perror("malloc failed");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, stdin);
    return line;
}

char **split_input(char *line) {
    char **args = calloc(MAX_ARGS, sizeof(char *));
    if (!args) {
        perror("calloc failed");
        exit(1);
    }
    char *token;
    int i = 0;
    while ((token = strtok(line, " \t\n\r")) != NULL) {
        args[i++] = token;
        line = NULL;
    }
    return args;
}

void execute(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            perror("execvp failed");
            exit(1);
        }
    } else {
        int status;
        if (waitpid(pid, &status, 0) < 0) {
            perror("waitpid failed");
            exit(1);
        }
    }
}

int main() {
    printf("Unix-like Shell\n");
    char *line;
    char **args;
    int status;
    do {
        printf("> ");
        line = read_input();
        args = split_input(line);
        if (args[0] == NULL) {
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else {
            execute(args);
        }
        free(line);
        free(args);
    } while (status);

    return 0;
}