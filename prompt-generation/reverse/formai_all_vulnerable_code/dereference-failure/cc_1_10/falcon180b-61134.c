//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, DELIM);

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

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
        case SIGTERM:
            fprintf(stdout, "Exiting...\n");
            exit(0);
        default:
            fprintf(stdout, "Unknown signal received: %d\n", signum);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_status;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        exit_status = execute_command(args);

        if (exit_status == 0 && background == 0) {
            fprintf(stdout, "> ");
        }
    }

    return 0;
}