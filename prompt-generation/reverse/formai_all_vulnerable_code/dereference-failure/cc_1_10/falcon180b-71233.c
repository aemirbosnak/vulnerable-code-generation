//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

// Struct to hold command and function pointer
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

// Global array of commands
command_t commands[MAX_COMMANDS];

// Function prototypes
void turn_on_lights(void);
void turn_off_lights(void);
void set_light_color(char *color);

// Initialize commands array
void init_commands(void) {
    strcpy(commands[0].command, "turn on lights");
    commands[0].function = turn_on_lights;

    strcpy(commands[1].command, "turn off lights");
    commands[1].function = turn_off_lights;

    strcpy(commands[2].command, "set light color");
    commands[2].function = set_light_color;
}

// Main function to process user input
int main(int argc, char **argv) {
    init_commands();

    while (1) {
        printf("Enter command: ");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        int i;
        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                (*commands[i].function)();
                break;
            }
        }

        if (i == MAX_COMMANDS) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

// Function to turn on lights
void turn_on_lights(void) {
    printf("Turning on lights...\n");
}

// Function to turn off lights
void turn_off_lights(void) {
    printf("Turning off lights...\n");
}

// Function to set light color
void set_light_color(char *color) {
    printf("Setting light color to %s...\n", color);
}