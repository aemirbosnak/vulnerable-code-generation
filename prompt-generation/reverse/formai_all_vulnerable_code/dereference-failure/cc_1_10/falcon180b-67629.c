//Falcon-180B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 80

typedef struct {
    char *command;
    char *arguments[MAX_ARGUMENTS];
    int num_arguments;
} command_t;

command_t commands[MAX_COMMANDS];
int num_commands = 0;

void add_command(char *command, char *arguments[], int num_arguments) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Maximum number of commands reached.\n");
        return;
    }

    command_t new_command;
    strcpy(new_command.command, command);
    new_command.num_arguments = num_arguments;

    for (int i = 0; i < num_arguments; i++) {
        strcpy(new_command.arguments[i], arguments[i]);
    }

    commands[num_commands++] = new_command;
}

void execute_command(char *command) {
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            for (int j = 0; j < commands[i].num_arguments; j++) {
                printf("%s ", commands[i].arguments[j]);
            }
            printf("\n");
            return;
        }
    }

    printf("Error: Command not found.\n");
}

int main() {
    add_command("ls", (char *[]){"-l"}, 1);
    add_command("mkdir", (char *[]){"test"}, 1);
    add_command("touch", (char *[]){"test.txt"}, 1);

    int choice;
    while (1) {
        printf("\n1. List commands\n2. Execute command\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_commands; i++) {
                printf("%s\n", commands[i].command);
            }
            break;

        case 2:
            printf("Enter command: ");
            char command[MAX_COMMAND_LENGTH];
            scanf("%s", command);

            execute_command(command);
            break;

        case 3:
            exit(0);

        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}