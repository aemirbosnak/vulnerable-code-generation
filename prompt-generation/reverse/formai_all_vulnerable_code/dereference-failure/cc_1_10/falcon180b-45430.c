//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int argc = 0, i = 0;
    char **argv = NULL;
    char *token;

    while ((token = strtok(str, DELIM))) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
    }

    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int exit_status = 0;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input_buffer);
        exit_status = execute_command(args);

        free(args);
    }

    return exit_status;
}