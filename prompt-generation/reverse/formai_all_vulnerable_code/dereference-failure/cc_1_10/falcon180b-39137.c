//Falcon-180B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define MAX_ENV 100

int main(int argc, char **argv) {
    pid_t pid;
    int status;
    char *command;
    char **args;
    char **env;
    int i, j;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
        return 1;
    }

    command = argv[1];
    args = &argv[2];
    env = &argv[2 + argc - 1];

    for (i = 0; i < argc - 1; i++) {
        if (strlen(args[i]) >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: argument %s is too long\n", args[i]);
            return 1;
        }
    }

    for (i = 0; i < MAX_ENV; i++) {
        if (env[i] == NULL) {
            break;
        }
        if (strlen(env[i]) >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: environment variable %s is too long\n", env[i]);
            return 1;
        }
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed\n");
        return 1;
    } else if (pid == 0) {
        // child process
        if (execve(command, args, env) == -1) {
            fprintf(stderr, "Error: execve failed\n");
            return 1;
        }
    } else {
        // parent process
        waitpid(pid, &status, 0);
    }

    return 0;
}