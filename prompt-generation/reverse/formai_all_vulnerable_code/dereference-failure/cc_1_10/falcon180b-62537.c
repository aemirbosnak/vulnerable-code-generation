//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGS 512

char **parse_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Failed to execute command '%s'\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LEN];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        args = parse_command(input);
        execute_command(args);
        free(args);
    }

    return 0;
}