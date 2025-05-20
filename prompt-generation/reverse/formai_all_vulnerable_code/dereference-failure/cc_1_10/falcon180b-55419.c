//Falcon-180B DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 512
#define DELIM " \t\r\n\a"

char **split(char *line, int *num_args) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        args[argc] = strdup(token);
        argc++;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }

    if (argc == 0) {
        fprintf(stderr, "No command found.\n");
        exit(1);
    }

    *num_args = argc;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command '%s'.\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Command terminated abnormally.\n");
            return 1;
        }
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int num_args;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        args = split(input_buffer, &num_args);
        status = execute_command(args);

        free(args[0]);
        for (int i = 1; i < num_args; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}