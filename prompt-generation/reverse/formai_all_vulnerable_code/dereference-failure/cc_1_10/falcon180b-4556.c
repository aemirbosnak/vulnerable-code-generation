//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
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

int execute_builtin_command(char **arguments) {
    if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arguments[0], "cd") == 0) {
        if (arguments[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\" command.\n");
        } else {
            if (chdir(arguments[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        fprintf(stderr, "Unknown builtin command: %s\n", arguments[0]);
        return 1;
    }

    return 0;
}

int execute_external_command(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);

        if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else if (strcmp(arguments[0], "cd") == 0) {
            execute_builtin_command(arguments);
        } else if (arguments[0][0] == '/') {
            execute_external_command(arguments);
        } else {
            fprintf(stderr, "Command not found: %s\n", arguments[0]);
        }
    }

    return 0;
}