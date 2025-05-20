//Falcon-180B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 50
#define MAX_ARGUMENT_LENGTH 50

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    char arguments[MAX_ARGUMENTS][MAX_ARGUMENT_LENGTH];
    int num_arguments;
} Command;

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *token;
    Command commands[MAX_COMMANDS];
    int num_commands = 0;

    printf("Welcome to the system administration program!\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        token = strtok(input, " ");
        strcpy(commands[num_commands].command, token);

        int i = 0;
        while (i < MAX_ARGUMENTS && (token = strtok(NULL, " "))!= NULL) {
            strcpy(commands[num_commands].arguments[i], token);
            i++;
        }
        commands[num_commands].num_arguments = i;

        num_commands++;

        if (num_commands == MAX_COMMANDS) {
            printf("Maximum number of commands reached. Exiting...\n");
            break;
        }
    }

    printf("Commands entered:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("Command %d: %s\n", i+1, commands[i].command);
        for (int j = 0; j < commands[i].num_arguments; j++) {
            printf("  Argument %d: %s\n", j+1, commands[i].arguments[j]);
        }
    }

    return 0;
}