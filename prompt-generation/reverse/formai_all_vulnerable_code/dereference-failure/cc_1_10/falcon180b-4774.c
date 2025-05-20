//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 50
#define MAX_PARAMS 10

// Define a structure to hold commands and parameters
typedef struct {
    char command[50];
    char params[MAX_PARAMS][50];
    int num_params;
} Command;

// Function to parse a command and its parameters
void parse_command(char *input, Command *command) {
    char *token = strtok(input, " ");
    strcpy(command->command, token);

    int i = 0;
    while (token!= NULL) {
        strcpy(command->params[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    command->num_params = i;
}

// Function to execute a command based on its name
void execute_command(char *command_name, Command *command) {
    if (strcmp(command_name, "turn_on_lights") == 0) {
        printf("Turning on lights...\n");
    } else if (strcmp(command_name, "turn_off_lights") == 0) {
        printf("Turning off lights...\n");
    } else if (strcmp(command_name, "lock_doors") == 0) {
        printf("Locking doors...\n");
    } else if (strcmp(command_name, "unlock_doors") == 0) {
        printf("Unlocking doors...\n");
    } else {
        printf("Invalid command...\n");
    }
}

// Function to send a command to the smart home system
void send_command(Command *command) {
    printf("Sending command: %s ", command->command);
    for (int i = 0; i < command->num_params; i++) {
        printf("%s ", command->params[i]);
    }
    printf("\n");
}

// Main function to read commands from user and execute them
int main() {
    Command commands[MAX_COMMANDS];
    int num_commands = 0;

    while (num_commands < MAX_COMMANDS) {
        printf("Enter a command (or type 'exit' to quit):\n");
        char input[100];
        fgets(input, 100, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        parse_command(input, &commands[num_commands]);
        num_commands++;
    }

    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i].command, &commands[i]);
        send_command(&commands[i]);
    }

    return 0;
}