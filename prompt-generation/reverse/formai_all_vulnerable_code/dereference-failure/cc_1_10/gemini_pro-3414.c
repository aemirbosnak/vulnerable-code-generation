//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a smart home light control system

// Define the light states
#define OFF 0
#define ON 1
#define DIM 2

// Define the light commands
#define TURN_ON "ON"
#define TURN_OFF "OFF"
#define DIM_LIGHT "DIM"

// Create a structure to represent a light
typedef struct light {
    int state;
    char *name;
} light;

// Create an array of lights
light lights[10];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < 10; i++) {
        lights[i].state = OFF;
        lights[i].name = malloc(10);
        sprintf(lights[i].name, "Light %d", i);
    }
}

// Turn a light on
void turn_on(light *light) {
    light->state = ON;
    printf("%s is now on.\n", light->name);
}

// Turn a light off
void turn_off(light *light) {
    light->state = OFF;
    printf("%s is now off.\n", light->name);
}

// Dim a light
void dim_light(light *light) {
    light->state = DIM;
    printf("%s is now dimmed.\n", light->name);
}

// Parse a command
int parse_command(char *command) {
    if (strcmp(command, TURN_ON) == 0) {
        return 1;
    } else if (strcmp(command, TURN_OFF) == 0) {
        return 2;
    } else if (strcmp(command, DIM_LIGHT) == 0) {
        return 3;
    } else {
        return 0;
    }
}

// Execute a command
void execute_command(light *light, char *command) {
    int command_type = parse_command(command);
    switch (command_type) {
        case 1:
            turn_on(light);
            break;
        case 2:
            turn_off(light);
            break;
        case 3:
            dim_light(light);
            break;
        default:
            printf("Invalid command.\n");
    }
}

// Get a light by name
light *get_light_by_name(char *name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            return &lights[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Initialize the lights
    init_lights();

    // Get the user input
    char command[10];
    char light_name[10];
    printf("Enter a command: ");
    scanf("%s %s", command, light_name);

    // Get the light by name
    light *light = get_light_by_name(light_name);

    // Execute the command
    execute_command(light, command);

    return 0;
}