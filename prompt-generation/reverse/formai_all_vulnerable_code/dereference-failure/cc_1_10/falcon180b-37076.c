//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 128
#define MAX_ENV_VARS 128

char **environ;

void print_environ(void) {
    char **envp = environ;
    while (*envp!= NULL) {
        printf("%s\n", *envp);
        envp++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *args[MAX_ARGS];
    int num_args = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_args >= MAX_ARGS) {
            fprintf(stderr, "Too many arguments\n");
            return 1;
        }
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}