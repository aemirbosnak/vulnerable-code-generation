//Falcon-180B DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

typedef struct {
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        if (command->num_arguments > 0) {
            execvp(command->arguments[0], command->arguments);
        } else {
            fprintf(stderr, "No command specified\n");
        }

        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_input(char *input) {
    char *token;
    Command command;

    command.num_arguments = 0;
    command.arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(input, DELIM);

    while (token!= NULL) {
        if (command.num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }

        command.arguments[command.num_arguments++] = token;

        token = strtok(NULL, DELIM);
    }

    execute_command(&command);

    for (int i = 0; i < command.num_arguments; i++) {
        free(command.arguments[i]);
    }

    free(command.arguments);
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");

        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Failed to read input: %s\n", strerror(errno));
            exit(1);
        }

        handle_input(input);
    }

    return 0;
}