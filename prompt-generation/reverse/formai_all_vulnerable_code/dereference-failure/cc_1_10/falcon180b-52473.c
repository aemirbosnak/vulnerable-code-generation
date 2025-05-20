//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
        case SIGTERM:
            exit(EXIT_SUCCESS);
        default:
            break;
    }
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_command(input);
    pid = execute_command(args);

    waitpid(pid, NULL, 0);

    return 0;
}