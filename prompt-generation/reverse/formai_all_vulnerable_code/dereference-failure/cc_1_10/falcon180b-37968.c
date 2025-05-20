//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_line(char *line);
pid_t fork();
void execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_line(input_buffer);
        if (args[0] == NULL)
            continue;

        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\n");
    }
}