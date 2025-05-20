//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char *command;
    void (*function)(char *argument);
} command_t;

void turn_on_light(char *argument) {
    printf("Turning on the light...\n");
}

void turn_off_light(char *argument) {
    printf("Turning off the light...\n");
}

void set_temperature(char *argument) {
    printf("Setting temperature to %s...\n", argument);
}

void play_music(char *argument) {
    printf("Playing music: %s...\n", argument);
}

command_t commands[] = {
    {"turn_on_light", turn_on_light},
    {"turn_off_light", turn_off_light},
    {"set_temperature", set_temperature},
    {"play_music", play_music}
};

int num_commands = sizeof(commands) / sizeof(command_t);

void execute_command(char *command, char *argument) {
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].function(argument);
            return;
        }
    }
    printf("Invalid command: %s\n", command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char argument[MAX_COMMAND_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *token = strtok(input, " ");
        strcpy(argument, token);

        execute_command(token, argument);
    }

    return 0;
}