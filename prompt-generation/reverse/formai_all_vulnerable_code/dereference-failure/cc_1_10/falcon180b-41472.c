//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (isspace(*str)) {
            if (bufsize > i) {
                tokens[i] = NULL;
            }
            i++;
        } else {
            bufsize++;
        }
        str++;
    }

    if (bufsize > i) {
        tokens[i] = NULL;
    }

    tokens = realloc(tokens, sizeof(char *) * (i + 1));

    token = strtok(str, DELIM);
    i = 0;
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, DELIM);
    }

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = launch_shell(args);

        waitpid(pid, NULL, WNOHANG);
    }

    return 0;
}