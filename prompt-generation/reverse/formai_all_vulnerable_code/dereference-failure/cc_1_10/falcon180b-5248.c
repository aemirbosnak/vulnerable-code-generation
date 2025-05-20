//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *line) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;

    char *copy = strdup(line);
    token = strtok(copy, DELIM);

    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, DELIM);
    }

    tokens = (char **) malloc((words + 1) * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    token = strtok(copy, DELIM);
    int i = 0;
    while (token!= NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        return 0;
    }

    return pid;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Command not found\n");
            exit(1);
        }
    } else if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    waitpid(pid, &status, 0);
}

int main() {
    char line[MAX_LINE];
    char **args;

    printf("Welcome to the post-apocalyptic shell\n");

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);

        args = split(line);
        execute_command(args);
    }

    return 0;
}