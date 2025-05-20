//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of lights in the home
#define MAX_LIGHTS 10

// Define the light states
enum light_state {
    LIGHT_OFF,
    LIGHT_ON
};

// Define the light structure
typedef struct light {
    char name[20];
    enum light_state state;
} light;

// Create an array of lights
light lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        char num[2];
        sprintf(num, "%d", i + 1);
        strcat(lights[i].name, num);
        lights[i].state = LIGHT_OFF;
    }
}

// Turn on a light
void turn_on_light(char *name) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = LIGHT_ON;
            printf("%s turned on.\n", name);
            return;
        }
    }

    printf("Light %s not found.\n", name);
}

// Turn off a light
void turn_off_light(char *name) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = LIGHT_OFF;
            printf("%s turned off.\n", name);
            return;
        }
    }

    printf("Light %s not found.\n", name);
}

// Toggle the state of a light
void toggle_light(char *name) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (lights[i].state == LIGHT_ON) {
                lights[i].state = LIGHT_OFF;
                printf("%s turned off.\n", name);
            } else {
                lights[i].state = LIGHT_ON;
                printf("%s turned on.\n", name);
            }
            return;
        }
    }

    printf("Light %s not found.\n", name);
}

// Print the status of all lights
void print_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state == LIGHT_ON ? "ON" : "OFF");
    }
}

// Main function
int main() {
    // Initialize the lights
    init_lights();

    // Print the initial status of the lights
    printf("Initial status of the lights:\n");
    print_lights();

    // Turn on light 1
    turn_on_light("Light 1");

    // Turn off light 3
    turn_off_light("Light 3");

    // Toggle light 5
    toggle_light("Light 5");

    // Print the updated status of the lights
    printf("\nUpdated status of the lights:\n");
    print_lights();

    return 0;
}