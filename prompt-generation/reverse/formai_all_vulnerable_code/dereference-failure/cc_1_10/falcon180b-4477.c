//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define MAX_ENVIRONMENT_VARIABLES 1024

#define WHITE "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

char **build_argv(char *command);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char **args = build_argv(command);

    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("%s exited with status %d\n", args[0], WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("%s was terminated by signal %d\n", args[0], WTERMSIG(status));
        } else {
            printf("%s exited abnormally\n", args[0]);
        }
    }

    return 0;
}

char **build_argv(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;

        if (argc >= MAX_ARGUMENTS) {
            printf(RED "Error: Too many arguments.\n" WHITE);
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}