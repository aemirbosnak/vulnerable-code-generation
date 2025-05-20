//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **args = NULL;

    for (int i = 0; str[i]!= '\0'; i++) {
        if (strchr(DELIM, str[i])!= NULL) {
            count++;
        }
    }

    args = malloc(sizeof(char *) * (count + 1));

    int j = 0;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        args[j] = token;
        j++;
        token = strtok(NULL, DELIM);
    }

    args[j] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}