//Falcon-180B DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMANDS 100
#define MAX_ARG_LENGTH 100

// Define structure for command and argument
typedef struct {
    char command[MAX_ARG_LENGTH];
    char argument[MAX_ARG_LENGTH];
} command_t;

// Function prototypes
void execute_command(command_t *cmd);
void parse_command(char *input, command_t *cmd);

int main() {
    char input[MAX_ARG_LENGTH];
    command_t cmd;

    printf("Welcome to the Knuth System Administration Tool!\n");
    printf("Please enter a command (type 'help' for a list of available commands):\n");

    while (fgets(input, MAX_ARG_LENGTH, stdin)!= NULL) {
        parse_command(input, &cmd);
        execute_command(&cmd);
    }

    return 0;
}

// Function to execute a command
void execute_command(command_t *cmd) {
    if (strcmp(cmd->command, "help") == 0) {
        printf("Available commands:\n");
        printf("- help: displays this list\n");
        printf("- exit: exits the program\n");
    } else if (strcmp(cmd->command, "exit") == 0) {
        printf("Exiting program...\n");
        exit(0);
    } else {
        printf("Invalid command: %s\n", cmd->command);
    }
}

// Function to parse a command
void parse_command(char *input, command_t *cmd) {
    char *token;
    token = strtok(input, " ");
    strcpy(cmd->command, token);

    if (strcmp(cmd->command, "help")!= 0 && strcmp(cmd->command, "exit")!= 0) {
        token = strtok(NULL, " ");
        strcpy(cmd->argument, token);
    } else {
        cmd->argument[0] = '\0';
    }
}