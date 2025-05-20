//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "Launching shell failed: command not found\n");
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
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "Quit by user\n");
            break;
        case SIGTERM:
            fprintf(stdout, "Terminated\n");
            break;
        default:
            fprintf(stdout, "Unknown signal %d\n", signum);
            break;
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    fprintf(stdout, "Unix-like Shell\n");

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_line(input);
        if (args[0] == NULL) {
            continue;
        }

        pid = launch_shell(args);

        if (pid == -1) {
            fprintf(stdout, "Error launching shell\n");
        } else {
            waitpid(pid, NULL, WUNTRACED);
        }
    }

    return EXIT_SUCCESS;
}