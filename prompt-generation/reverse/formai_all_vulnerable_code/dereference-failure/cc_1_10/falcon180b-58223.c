//Falcon-180B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 50
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user.\n");
            break;
        case SIGTERM:
            fprintf(stdout, "Terminated by user.\n");
            break;
        default:
            fprintf(stdout, "Received signal %d.\n", signum);
            break;
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input_buffer);
        status = execute_command(args);

        free(args);
    }

    return 0;
}