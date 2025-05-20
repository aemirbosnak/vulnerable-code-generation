//Falcon-180B DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argc);
        arguments[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork_and_exec(char **arguments) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(arguments[0], arguments);
        fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return pid;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input_buffer);
        pid = fork_and_exec(arguments);
        waitpid(pid, &status, 0);
        free(arguments);
    }

    return 0;
}