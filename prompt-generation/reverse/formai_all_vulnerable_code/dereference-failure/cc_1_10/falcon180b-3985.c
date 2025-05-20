//Falcon-180B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_LENGTH 1024

typedef struct command_t {
    char *command;
    char **arguments;
    char **environment;
    int num_arguments;
    int num_environment_variables;
} command_t;

void execute_command(command_t *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Error: Failed to fork()\n");
        exit(1);
    } else if (child_pid > 0) {
        // Parent process
        waitpid(child_pid, &status, 0);
    } else {
        // Child process
        if (execvp(command->command, command->arguments) == -1) {
            fprintf(stderr, "Error: Failed to execvp()\n");
            exit(1);
        }
    }
}

void parse_command(char *input, command_t *command) {
    char *token;
    int num_arguments = 0;
    int num_environment_variables = 0;

    command->command = strdup(input);
    token = strtok(input, " ");
    while (token!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments\n");
            exit(1);
        }
        command->arguments[num_arguments] = strdup(token);
        num_arguments++;
        token = strtok(NULL, " ");
    }
    command->num_arguments = num_arguments;

    token = strtok(input, " ");
    while (token!= NULL) {
        if (num_environment_variables >= MAX_ENV_LENGTH) {
            fprintf(stderr, "Error: Too many environment variables\n");
            exit(1);
        }
        command->environment[num_environment_variables] = strdup(token);
        num_environment_variables++;
        token = strtok(NULL, " ");
    }
    command->num_environment_variables = num_environment_variables;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    command_t command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}