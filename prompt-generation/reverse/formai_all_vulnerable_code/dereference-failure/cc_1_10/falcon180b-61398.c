//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    return pid;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_line(input);
        launch_shell(args);

        memset(input, 0, MAX_COMMAND_LENGTH);
    }

    return 0;
}