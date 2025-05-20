//Falcon-180B DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define MAX_ENVIRONMENT_VARIABLES 256

typedef struct {
    char **arguments;
    char **environment;
    int num_arguments;
    int num_environment_variables;
} command_t;

void execute_command(command_t *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        if (execve(command->arguments[0], command->arguments, command->environment) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (child_pid < 0) {
        // Error forking
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0);
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    command_t command;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
        command.environment = malloc(MAX_ENVIRONMENT_VARIABLES * sizeof(char *));
        command.num_arguments = 0;
        command.num_environment_variables = 0;

        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            if (command.num_arguments >= MAX_ARGUMENTS) {
                fprintf(stderr, "Error: Too many arguments\n");
                exit(1);
            }
            command.arguments[command.num_arguments++] = token;
            token = strtok(NULL, " ");
        }

        if (command.num_arguments == 0) {
            continue;
        }

        command.arguments[command.num_arguments] = NULL;

        token = strtok(input_buffer, "\n");
        while (token!= NULL) {
            if (command.num_environment_variables >= MAX_ENVIRONMENT_VARIABLES) {
                fprintf(stderr, "Error: Too many environment variables\n");
                exit(1);
            }
            command.environment[command.num_environment_variables++] = token;
            token = strtok(NULL, "\n");
        }

        command.environment[command.num_environment_variables] = NULL;

        execute_command(&command);

        for (int i = 0; i < command.num_arguments; i++) {
            free(command.arguments[i]);
        }
        free(command.arguments);

        for (int i = 0; i < command.num_environment_variables; i++) {
            free(command.environment[i]);
        }
        free(command.environment);
    }

    return 0;
}