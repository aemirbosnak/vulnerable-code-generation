//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));

    str = strtok(str, DELIM);
    while (str!= NULL) {
        tokens[i] = strdup(str);
        i++;
        str = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == -1) {
        perror("vfork");
        exit(1);
    }

    if (pid == 0) {
        return 0;
    } else {
        return pid;
    }
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            execute_command(args);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}