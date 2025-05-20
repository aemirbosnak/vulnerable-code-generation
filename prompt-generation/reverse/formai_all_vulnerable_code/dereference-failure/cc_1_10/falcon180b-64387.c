//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 512
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

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    fprintf(stdout, "Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    arguments = split_string(input);

    if (arguments[0] == NULL) {
        fprintf(stdout, "No command specified.\n");
    } else {
        execute_command(arguments);
    }

    return 0;
}