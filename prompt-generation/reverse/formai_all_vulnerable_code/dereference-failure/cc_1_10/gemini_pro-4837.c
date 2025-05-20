//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the light states
enum light_state {
    OFF,
    ON,
    DIM
};

// Define the light struct
typedef struct light {
    char *name;
    enum light_state state;
} light;

// Create a new light
light *create_light(char *name) {
    light *new_light = malloc(sizeof(light));
    new_light->name = name;
    new_light->state = OFF;
    return new_light;
}

// Turn the light on
void turn_on(light *light) {
    light->state = ON;
}

// Turn the light off
void turn_off(light *light) {
    light->state = OFF;
}

// Dim the light
void dim(light *light) {
    light->state = DIM;
}

// Print the light state
void print_light_state(light *light) {
    switch (light->state) {
        case OFF:
            printf("%s is off\n", light->name);
            break;
        case ON:
            printf("%s is on\n", light->name);
            break;
        case DIM:
            printf("%s is dimmed\n", light->name);
            break;
    }
}

// Main function
int main() {
    // Create some lights
    light *kitchen_light = create_light("Kitchen Light");
    light *living_room_light = create_light("Living Room Light");
    light *bedroom_light = create_light("Bedroom Light");

    // Turn on the kitchen light
    turn_on(kitchen_light);

    // Dim the living room light
    dim(living_room_light);

    // Turn off the bedroom light
    turn_off(bedroom_light);

    // Print the light states
    print_light_state(kitchen_light);
    print_light_state(living_room_light);
    print_light_state(bedroom_light);

    return 0;
}