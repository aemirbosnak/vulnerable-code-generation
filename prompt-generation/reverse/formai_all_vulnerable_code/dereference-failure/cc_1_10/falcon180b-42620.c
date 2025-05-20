//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_LINE_LENGTH];
    char **args;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        args = split_line(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();
        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_line(char *line) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
            return 1;
        }
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGQUIT || signum == SIGTERM) {
        printf("\nExiting...\n");
        exit(0);
    }
}