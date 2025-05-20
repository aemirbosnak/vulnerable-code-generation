//Falcon-180B DATASET v1.0 Category: System administration ; Style: interoperable
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
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc == MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input_buffer);

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execvp(arguments[0], arguments);
            perror("execvp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}