//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights in the smart home
#define MAX_LIGHTS 10

// Define the possible states of a light
typedef enum {
    OFF,
    ON,
    DIMMED
} light_state;

// Define the structure of a light
typedef struct {
    int id;
    char *name;
    light_state state;
} light;

// Create an array of lights
light lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].name = NULL;
        lights[i].state = OFF;
    }
}

// Set the name of a light
void set_light_name(int id, char *name) {
    if (id < 0 || id >= MAX_LIGHTS) {
        return;
    }

    if (lights[id].name != NULL) {
        free(lights[id].name);
    }

    lights[id].name = strdup(name);
}

// Turn a light on
void turn_on_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        return;
    }

    lights[id].state = ON;
}

// Turn a light off
void turn_off_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        return;
    }

    lights[id].state = OFF;
}

// Dim a light
void dim_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        return;
    }

    lights[id].state = DIMMED;
}

// Get the state of a light
light_state get_light_state(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        return OFF;
    }

    return lights[id].state;
}

// Print the status of all lights
void print_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %s, ", lights[i].id, lights[i].name);
        switch (lights[i].state) {
            case OFF:
                printf("OFF\n");
                break;
            case ON:
                printf("ON\n");
                break;
            case DIMMED:
                printf("DIMMED\n");
                break;
        }
    }
}

// Main function
int main() {
    // Initialize the lights
    init_lights();

    // Set the names of some lights
    set_light_name(0, "Living Room Light");
    set_light_name(1, "Bedroom Light");
    set_light_name(2, "Kitchen Light");

    // Turn on the living room light
    turn_on_light(0);

    // Dim the bedroom light
    dim_light(1);

    // Turn off the kitchen light
    turn_off_light(2);

    // Print the status of all lights
    print_lights();

    return 0;
}