//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL && count < MAX_ARGUMENTS) {
        args[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }

    args[count] = NULL;
    return args;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error executing command: %s\n", args[0]);
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t shell_pid;

    printf("Welcome to the Basic Unix-like Shell!\n");
    printf("Type 'exit' to terminate the shell.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        shell_pid = launch_shell(args);

        free(args[0]);
        free(args);
    }

    return 0;
}