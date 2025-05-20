//Falcon-180B DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 80

typedef struct {
    char *command;
    void (*function)(int argc, char **argv);
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void add_command(char *command, void (*function)(int argc, char **argv)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }

    commands[num_commands].command = strdup(command);
    commands[num_commands].function = function;

    num_commands++;
}

void execute_command(int argc, char **argv) {
    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[0]);

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function(argc, argv);
            return;
        }
    }

    printf("Error: Unknown command '%s'.\n", command);
}

void help_command(int argc, char **argv) {
    if (argc!= 1) {
        printf("Usage: help\n");
        return;
    }

    printf("Available commands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].command);
    }
}

int main(int argc, char **argv) {
    add_command("help", help_command);
    add_command("exit", NULL);

    execute_command(argc, argv);

    return 0;
}