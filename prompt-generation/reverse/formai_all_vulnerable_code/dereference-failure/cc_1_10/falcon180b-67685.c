//Falcon-180B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
    int argc = 0;
    char **argv = NULL;
    char delimited_command[MAX_COMMAND_LENGTH];

    strcpy(delimited_command, command);
    argv = (char **) malloc(MAX_ARGS * sizeof(char *));

    char *token = strtok(delimited_command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = build_argv(input);
        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Command not found.\n");
                exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}