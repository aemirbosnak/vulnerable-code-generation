//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc == MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = split_command(input);
        int status = system(args[0]);

        if (status == -1) {
            perror("Error");
        } else if (WIFEXITED(status)) {
            printf("Exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Killed by signal %d\n", WTERMSIG(status));
        } else {
            printf("Unknown exit status\n");
        }
    }

    return 0;
}