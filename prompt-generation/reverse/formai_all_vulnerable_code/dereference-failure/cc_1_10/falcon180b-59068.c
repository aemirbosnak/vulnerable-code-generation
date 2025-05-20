//Falcon-180B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENT_LENGTH 80

// Function prototypes
void execute_command(char *command);
int parse_command(char *command, char **arguments);

int main() {
    char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
    char arguments[MAX_COMMANDS][MAX_ARGUMENT_LENGTH];
    int num_commands = 0;

    // Prompt the user for commands
    while (num_commands < MAX_COMMANDS) {
        printf("Enter a command (or type 'exit' to quit): ");
        fgets(commands[num_commands], MAX_COMMAND_LENGTH, stdin);

        // Check if the user wants to exit
        if (strcmp(commands[num_commands], "exit") == 0) {
            break;
        }

        // Parse the command and its arguments
        int num_arguments = parse_command(commands[num_commands], arguments[num_commands]);

        // Execute the command
        execute_command(commands[num_commands]);

        // Increment the number of commands
        num_commands++;
    }

    return 0;
}

// Executes a command and prints its output
void execute_command(char *command) {
    system(command);
}

// Parses a command and its arguments
int parse_command(char *command, char **arguments) {
    int num_arguments = 0;
    char *token = strtok(command, " ");

    // Count the number of arguments
    while (token!= NULL) {
        num_arguments++;
        token = strtok(NULL, " ");
    }

    // Allocate memory for the arguments
    arguments[0] = (char *) malloc(num_arguments * MAX_ARGUMENT_LENGTH);

    // Parse the arguments
    int i = 0;
    token = strtok(command, " ");
    while (token!= NULL) {
        strcpy(arguments[0] + i * MAX_ARGUMENT_LENGTH, token);
        i++;
        token = strtok(NULL, " ");
    }

    return num_arguments;
}