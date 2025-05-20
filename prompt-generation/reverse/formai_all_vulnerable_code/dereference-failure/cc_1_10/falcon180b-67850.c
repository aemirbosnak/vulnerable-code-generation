//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments = NULL;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input_buffer);

        if (arguments[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execvp(arguments[0], arguments);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }

        for (int i = 0; i < MAX_ARGUMENTS; i++) {
            free(arguments[i]);
        }
        free(arguments);
        arguments = NULL;
    }

    return 0;
}