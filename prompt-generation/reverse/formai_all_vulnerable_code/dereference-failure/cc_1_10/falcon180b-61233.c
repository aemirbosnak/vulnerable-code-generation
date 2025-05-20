//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argc);
        arguments[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

pid_t launch_shell(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "launch_shell: command not found\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "fork: error\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "execvp: error\n");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    arguments = split_command(input);
    pid = launch_shell(arguments);

    free(arguments);
}

int main(void) {
    loop();

    return EXIT_SUCCESS;
}