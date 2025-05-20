//Falcon-180B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        arguments = realloc(arguments, sizeof(char *) * argc);
        arguments[argc - 1] = strdup(token);
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
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
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

int main() {
    FILE *fp;
    char line[MAX_COMMAND_LENGTH];
    char **arguments;

    fp = fopen("/dev/tty", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open terminal device: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        arguments = split_command(line);
        if (arguments == NULL) {
            fprintf(stderr, "Invalid command\n");
        } else {
            execute_command(arguments);
            free(arguments[0]);
            for (int i = 1; arguments[i]!= NULL; i++) {
                free(arguments[i]);
            }
            free(arguments);
        }
    }

    fclose(fp);
    return 0;
}