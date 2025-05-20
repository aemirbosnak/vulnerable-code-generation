//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **command_argv = NULL;
    int status;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        command_argv = split_string(input);
        status = execute_command(command_argv);

        free(command_argv);
    }

    return 0;
}