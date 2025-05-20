//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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
        tokens[count-1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == 0) {
        execlp("/bin/sh", "sh", "-c", "");
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if (pid < 0) {
            perror("fork");
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}