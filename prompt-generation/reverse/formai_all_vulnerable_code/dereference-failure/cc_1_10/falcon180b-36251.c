//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define DELIMITER " "

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

void execute_command(Command *command) {
    if (strcmp(command->command, "ls") == 0) {
        printf("Executing 'ls' command...\n");
    } else if (strcmp(command->command, "mkdir") == 0) {
        printf("Executing'mkdir' command...\n");
    } else if (strcmp(command->command, "rm") == 0) {
        printf("Executing 'rm' command...\n");
    } else {
        printf("Invalid command: %s\n", command->command);
    }
}

void free_command(Command *command) {
    free(command->command);
    for (int i = 0; i < command->num_arguments; i++) {
        free(command->arguments[i]);
    }
    free(command->arguments);
}

void parse_command(char *input, Command *command) {
    char *token = strtok(input, DELIMITER);
    command->command = strdup(token);

    int num_arguments = 0;
    while ((token = strtok(NULL, DELIMITER))!= NULL) {
        if (num_arguments >= MAX_ARGUMENTS) {
            break;
        }
        command->arguments[num_arguments] = strdup(token);
        num_arguments++;
    }
    command->num_arguments = num_arguments;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    Command command;

    while (true) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        parse_command(input, &command);
        execute_command(&command);

        free_command(&command);
    }

    return 0;
}