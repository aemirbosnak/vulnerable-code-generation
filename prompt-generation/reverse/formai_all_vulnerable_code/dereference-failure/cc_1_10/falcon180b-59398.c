//Falcon-180B DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

// Function prototypes
void execute_command(char *command);
int get_argument_count(char *command);
char **get_arguments(char *command);
int is_valid_command(char *command);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *command;

    printf("Welcome to the System Administration Console!\n");
    printf("Please enter a command:\n");

    fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
    command = strtok(input_buffer, "\n");

    if (is_valid_command(command)) {
        execute_command(command);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}

void execute_command(char *command) {
    int argument_count;
    char **arguments;

    argument_count = get_argument_count(command);
    arguments = get_arguments(command);

    printf("Executing command: %s\n", command);
    for (int i = 0; i < argument_count; i++) {
        printf("Argument %d: %s\n", i+1, arguments[i]);
    }
}

int get_argument_count(char *command) {
    int count = 0;
    char *current_argument = strtok(command, " ");

    while (current_argument!= NULL) {
        count++;
        current_argument = strtok(NULL, " ");
    }

    return count;
}

char **get_arguments(char *command) {
    int argument_count = get_argument_count(command);
    char **arguments = malloc(argument_count * sizeof(char*));
    int current_argument_index = 0;
    char *current_argument = strtok(command, " ");

    while (current_argument!= NULL) {
        arguments[current_argument_index] = current_argument;
        current_argument_index++;
        current_argument = strtok(NULL, " ");
    }

    return arguments;
}

int is_valid_command(char *command) {
    char *valid_commands[] = {"ls", "cd", "mkdir", "rm", "cp", "mv"};
    int command_count = sizeof(valid_commands) / sizeof(valid_commands[0]);

    for (int i = 0; i < command_count; i++) {
        if (strcmp(command, valid_commands[i]) == 0) {
            return 1;
        }
    }

    return 0;
}