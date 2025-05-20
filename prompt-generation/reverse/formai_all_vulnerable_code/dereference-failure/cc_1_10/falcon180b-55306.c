//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PIPE_READ 0
#define PIPE_WRITE 1

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;

    if ((pid = fork()) == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    printf("Post-Apocalyptic Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        if (args[0] == NULL)
            continue;

        pid = launch_shell(args);
        waitpid(pid, &status, 0);
    }

    return 0;
}