//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMANDS 100
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (isspace(*str)) {
            *str++ = '\0';
        } else {
            bufsize++;
        }
    }

    tokens = malloc(sizeof(char *) * (bufsize + 1));

    str = strtok(str, DELIM);
    while (str!= NULL) {
        tokens[i++] = strdup(str);
        str = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "Launch error: command not found\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execvp");
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

int main() {
    char input[1024];
    char **args;
    pid_t pid;

    printf("Welcome to the async shell!\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = launch_shell(args);

        if (pid == -1) {
            printf("Error launching process\n");
        }
    }

    return 0;
}