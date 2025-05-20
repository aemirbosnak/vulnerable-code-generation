//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int count = 0;
    char *token;

    token = strtok(command, " ");
    while (token!= NULL && count < MAX_ARGUMENTS) {
        arguments[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }
    arguments[count] = NULL;

    return arguments;
}

int launch_shell(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Failed to execute '%s': %s\n", arguments[0], strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Child terminated abnormally\n");
            return 1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);
        if (arguments[0] == NULL) {
            continue;
        }

        launch_shell(arguments);
    }

    return 0;
}