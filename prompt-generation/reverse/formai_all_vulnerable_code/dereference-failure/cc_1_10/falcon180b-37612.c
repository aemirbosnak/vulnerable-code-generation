//Falcon-180B DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc] = strdup(token);
        argc++;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input_buffer);
        status = execute_command(arguments);

        free(arguments[0]);
        free(arguments);
    }

    return 0;
}