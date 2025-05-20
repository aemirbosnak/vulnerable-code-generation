//Falcon-180B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 80

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    char arguments[MAX_ARGUMENTS][MAX_ARGUMENT_LENGTH];
    int num_arguments;
} Command;

void execute_command(Command* cmd) {
    if (strcmp(cmd->command, "ls") == 0) {
        printf("Listing files...\n");
    } else if (strcmp(cmd->command, "cd") == 0) {
        printf("Changing directory...\n");
    } else if (strcmp(cmd->command, "mkdir") == 0) {
        printf("Creating directory...\n");
    } else if (strcmp(cmd->command, "rmdir") == 0) {
        printf("Removing directory...\n");
    } else if (strcmp(cmd->command, "touch") == 0) {
        printf("Creating file...\n");
    } else {
        printf("Invalid command.\n");
    }
}

void parse_command(char* input, Command* cmd) {
    char* token = strtok(input, " ");
    strcpy(cmd->command, token);

    int i = 0;
    while ((token = strtok(NULL, " "))!= NULL) {
        strcpy(cmd->arguments[i], token);
        i++;
    }

    cmd->num_arguments = i;
}

int main() {
    Command commands[MAX_COMMANDS];
    int num_commands = 0;

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        parse_command(input, &commands[num_commands]);
        num_commands++;
    }

    for (int i = 0; i < num_commands; i++) {
        execute_command(&commands[i]);
    }

    return 0;
}