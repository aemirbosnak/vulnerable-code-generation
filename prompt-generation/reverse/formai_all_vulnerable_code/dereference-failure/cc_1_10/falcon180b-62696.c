//Falcon-180B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Exec failed: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Command terminated abnormally\n");
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Enter commands to execute:\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        arguments = split_command(input);
        execute_command(arguments);
    }

    return 0;
}