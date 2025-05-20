//Falcon-180B DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 50
#define MAX_ENV_VARS 50

typedef struct {
    char **args;
    char **envp;
    int argc;
    int envc;
} Command;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [args]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);
    char *args[MAX_ARGS];
    int argc_ = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[argc_++] = token;
        token = strtok(NULL, " ");
    }

    Command cmd = {args, NULL, argc_, 0};
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}