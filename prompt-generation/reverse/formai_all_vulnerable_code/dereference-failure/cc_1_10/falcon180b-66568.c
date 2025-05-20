//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 32
#define DELIM " \t\r\n\a"

typedef struct {
    pid_t pid;
    int status;
} process_t;

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Error: Child exited abnormally.\n");
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    signal(SIGINT, SIG_IGN);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        status = execute_command(args);

        if (status == 1) {
            fprintf(stderr, "Error: Command failed.\n");
        }
    }

    return 0;
}