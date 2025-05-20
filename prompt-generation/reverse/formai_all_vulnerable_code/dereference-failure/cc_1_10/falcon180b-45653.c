//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", args[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = launch_shell(args);

        if (pid!= 0) {
            waitpid(pid, &status, WUNTRACED);
        }
    }

    return 0;
}