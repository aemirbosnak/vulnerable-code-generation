//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    for (token = strtok(string, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        count++;
    }

    tokens = (char **)malloc(sizeof(char *) * (count + 1));

    for (token = strtok(string, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        tokens[count - 1] = strdup(token);
        count--;
    }

    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Error: Command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments = NULL;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);

        if (arguments[0] == NULL) {
            continue;
        }

        execute_command(arguments);

        for (int i = 0; arguments[i]!= NULL; i++) {
            free(arguments[i]);
        }

        free(arguments);
        arguments = NULL;
    }

    return 0;
}