//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"
#define PATH_DELIM ":"

typedef struct {
    char **arguments;
    int argument_count;
} Command;

char *builtin_str = "cd";

int execute_builtin(Command *command) {
    if (strcmp(command->arguments[0], builtin_str) == 0) {
        char *dir = command->arguments[1];
        if (chdir(dir)!= 0) {
            printf("Error: Could not change directory to %s\n", dir);
            return 1;
        }
        return 0;
    }
    return 1;
}

int execute_command(Command *command) {
    pid_t pid;
    int status;

    if (execute_builtin(command)) {
        return 0;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error: Could not fork process\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            printf("Error: Could not execute command %s\n", command->arguments[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

Command *parse_command(char *input) {
    Command *command = malloc(sizeof(Command));
    command->arguments = malloc((MAX_ARGUMENTS + 1) * sizeof(char *));
    command->argument_count = 0;

    char *token = strtok(input, DELIM);
    while (token!= NULL) {
        command->arguments[command->argument_count++] = token;
        token = strtok(NULL, DELIM);
    }
    command->arguments[command->argument_count] = NULL;

    return command;
}

void free_command(Command *command) {
    for (int i = 0; i < command->argument_count; i++) {
        free(command->arguments[i]);
    }
    free(command->arguments);
    free(command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        Command *command = parse_command(input);
        int result = execute_command(command);

        free_command(command);

        if (result) {
            break;
        }
    }

    return 0;
}