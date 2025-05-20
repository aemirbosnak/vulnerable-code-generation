//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc++] = token;
        i++;

        if (i >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }

        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

pid_t launch_process(char **arguments) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        printf("Error: Failed to execute %s.\n", arguments[0]);
        exit(1);
    }

    return pid;
}

void wait_for_process(pid_t pid) {
    int status;
    waitpid(pid, &status, 0);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **arguments = split_command(input);
        pid_t pid = launch_process(arguments);
        wait_for_process(pid);
    }

    return 0;
}