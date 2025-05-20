//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t fork_and_exec(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input_buffer);
        pid = fork_and_exec(args);

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    int count = 0;
    char **tokens;
    char *token;

    tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));

    if (tokens == NULL) {
        perror("malloc");
        exit(1);
    }

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork_and_exec(char **args) {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid == -1) {
        perror("fork");
    }

    return pid;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user\n");
    }
}