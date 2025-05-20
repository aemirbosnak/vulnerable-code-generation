//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 50
#define MAX_RESPONSES 100
#define MAX_RESPONSE_LENGTH 100

typedef struct {
    char *command;
    void (*function)(char *response);
} command_t;

command_t commands[MAX_COMMANDS];
int num_commands = 0;

void add_command(char *command, void (*function)(char *response)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Maximum number of commands reached.\n");
        return;
    }
    commands[num_commands].command = strdup(command);
    commands[num_commands].function = function;
    num_commands++;
}

void execute_command(char *input) {
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, input) == 0) {
            char response[MAX_RESPONSE_LENGTH];
            commands[i].function(response);
            printf("%s\n", response);
            return;
        }
    }
    printf("Unknown command.\n");
}

void turn_on_light(char *response) {
    strcpy(response, "Light turned on.");
}

void turn_off_light(char *response) {
    strcpy(response, "Light turned off.");
}

void set_temperature(char *response, int temperature) {
    sprintf(response, "Temperature set to %d degrees.", temperature);
}

int main() {
    int choice;
    char input[MAX_COMMAND_LENGTH];

    add_command("turn on light", turn_on_light);
    add_command("turn off light", turn_off_light);
    add_command("set temperature", set_temperature);

    while (1) {
        printf("\nSmart Home Automation\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Set temperature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            turn_on_light(input);
            printf("%s\n", input);
        } else if (choice == 2) {
            turn_off_light(input);
            printf("%s\n", input);
        } else if (choice == 3) {
            printf("Enter temperature: ");
            scanf("%d", &choice);
            set_temperature(input, choice);
            printf("%s\n", input);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}