//Falcon-180B DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
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

        char *command = strtok(input, "\n");
        char **args = split_command(command);

        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
        } else if (pid == 0) {
            execvp(args[0], args);
        } else {
            wait(NULL);
        }
    }

    return 0;
}