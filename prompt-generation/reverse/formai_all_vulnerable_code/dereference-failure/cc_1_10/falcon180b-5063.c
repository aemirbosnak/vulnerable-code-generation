//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **args;
    int num_args;
} command_t;

command_t *parse_command(char *command) {
    char *token;
    command_t *result = malloc(sizeof(command_t));
    result->num_args = 0;
    result->args = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(command, " ");
    while (token!= NULL) {
        if (result->num_args >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            exit(1);
        }
        result->args[result->num_args++] = strdup(token);
        token = strtok(NULL, " ");
    }

    return result;
}

int execute_command(command_t *cmd) {
    pid_t pid;
    int status;

    if (cmd->num_args == 0) {
        fprintf(stderr, "Error: No command specified\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(cmd->args[0], cmd->args) == -1) {
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

int main() {
    char input[MAX_COMMAND_LENGTH];
    command_t *cmd;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    cmd = parse_command(input);
    execute_command(cmd);

    return 0;
}