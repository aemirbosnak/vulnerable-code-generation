//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\n\r\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

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
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Command not found.\n");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    arguments = split_command(input);
    execute_command(arguments);
}

int main() {
    loop();

    return 0;
}