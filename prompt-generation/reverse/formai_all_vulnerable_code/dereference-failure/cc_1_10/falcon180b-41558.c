//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        if (argv == NULL) {
            fprintf(stderr, "Error: Out of memory.\n");
            exit(1);
        }
        argv[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    argv[i] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed. %s\n", strerror(errno));
        exit(1);
    }

    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed. %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return status;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        status = execute_command(argv);

        free(argv[0]);
        for (int i = 1; argv[i]!= NULL; i++) {
            free(argv[i]);
        }
        free(argv);
    }

    return 0;
}