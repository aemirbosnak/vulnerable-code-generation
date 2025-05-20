//Falcon-180B DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int launch_shell(char **argv) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error executing: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Child terminated abnormally\n");
            return 1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = build_argv(input);

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified\n");
        return 1;
    }

    launch_shell(argv);

    return 0;
}