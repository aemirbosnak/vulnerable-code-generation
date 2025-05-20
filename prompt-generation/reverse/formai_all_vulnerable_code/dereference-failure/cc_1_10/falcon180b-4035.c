//Falcon-180B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_VARIABLES 10

typedef struct {
    char **args;
    char **env;
    int num_args;
    int num_env;
} command_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);
    char *args[MAX_ARGUMENTS];
    int num_args = 0;
    char *env[MAX_ENV_VARIABLES];
    int num_env = 0;

    // Parse arguments
    char *token = strtok(command, " ");
    while (token!= NULL) {
        if (num_args >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    // Parse environment variables
    token = strtok(command, " ");
    while (token!= NULL) {
        if (num_env >= MAX_ENV_VARIABLES) {
            fprintf(stderr, "Too many environment variables\n");
            exit(1);
        }
        env[num_env++] = token;
        token = strtok(NULL, " ");
    }
    env[num_env] = NULL;

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        exit(status);
    }

    return 0;
}