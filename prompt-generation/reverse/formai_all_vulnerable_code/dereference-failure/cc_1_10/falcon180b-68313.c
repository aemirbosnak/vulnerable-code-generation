//Falcon-180B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LEN 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, len = strlen(command);
    char **args = malloc((argc + 1) * sizeof(char *));
    if (!args) {
        fprintf(stderr, "Error: malloc failed.\n");
        exit(1);
    }
    args[argc] = NULL;
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    return args;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: execvp failed.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    fprintf(stdout, "\nInterrupted by user.\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [command]\n", argv[0]);
        exit(1);
    }

    char **args = split_command(argv[1]);
    launch_shell(args);

    return 0;
}