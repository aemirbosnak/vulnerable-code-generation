//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

typedef struct command {
    char *name;
    void (*function)(char **arguments);
} Command;

void execute_command(char **arguments) {
    printf("Command not found.\n");
}

void help(char **arguments) {
    printf("Available commands:\n");
    printf("  help\n");
    printf("  exit\n");
}

void exit_shell(int status) {
    exit(status);
}

char **split_command(char *command) {
    char **arguments = malloc(sizeof(char *) * MAX_ARGUMENTS);
    int argument_count = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argument_count < MAX_ARGUMENTS) {
        arguments[argument_count++] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argument_count] = NULL;
    return arguments;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command commands[] = {{"help", help}, {"exit", exit_shell}};
    int command_count = sizeof(commands) / sizeof(Command);

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **arguments = split_command(input);
        int argument_count = 0;

        while (arguments[argument_count]!= NULL) {
            printf("%s ", arguments[argument_count]);
            argument_count++;
        }

        printf("\n");

        for (int i = 0; i < command_count; i++) {
            if (strcmp(arguments[0], commands[i].name) == 0) {
                commands[i].function(arguments);
                break;
            }
        }

        free(arguments);
    }

    return 0;
}