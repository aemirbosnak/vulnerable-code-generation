//Falcon-180B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(arguments[0], arguments);
        fprintf(stderr, "Error executing command.\n");
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process.\n");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    arguments = split_command(input);
    execute_command(arguments);

    return 0;
}