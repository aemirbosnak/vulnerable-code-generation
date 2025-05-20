//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char *argv[MAX_COMMAND_LENGTH];
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "No directory specified.\n");
        } else {
            if (chdir(args[1]) == -1) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "Interrupted by user.\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "Quit by user.\n");
            break;
        default:
            fprintf(stdout, "Received signal %d.\n", signum);
            break;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        execute_command(args);
    }

    return 0;
}