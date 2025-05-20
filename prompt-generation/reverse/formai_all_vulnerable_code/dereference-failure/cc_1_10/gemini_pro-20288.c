//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Define the states of a light
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the structure of a light
typedef struct {
    uint8_t id;
    char name[32];
    light_state_t state;
} light_t;

// Define the structure of the smart home system
typedef struct {
    light_t lights[MAX_LIGHTS];
    uint8_t num_lights;
} smart_home_t;

// Create a new smart home system
smart_home_t* smart_home_new() {
    smart_home_t* smart_home = (smart_home_t*)malloc(sizeof(smart_home_t));
    if (smart_home == NULL) {
        return NULL;
    }

    smart_home->num_lights = 0;

    return smart_home;
}

// Add a new light to the smart home system
int smart_home_add_light(smart_home_t* smart_home, uint8_t id, char* name) {
    if (smart_home->num_lights >= MAX_LIGHTS) {
        return -1;
    }

    light_t* light = &smart_home->lights[smart_home->num_lights];
    light->id = id;
    strcpy(light->name, name);
    light->state = LIGHT_OFF;

    smart_home->num_lights++;

    return 0;
}

// Turn on a light
int smart_home_turn_on_light(smart_home_t* smart_home, uint8_t id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        light_t* light = &smart_home->lights[i];
        if (light->id == id) {
            light->state = LIGHT_ON;
            return 0;
        }
    }

    return -1;
}

// Turn off a light
int smart_home_turn_off_light(smart_home_t* smart_home, uint8_t id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        light_t* light = &smart_home->lights[i];
        if (light->id == id) {
            light->state = LIGHT_OFF;
            return 0;
        }
    }

    return -1;
}

// Dim a light
int smart_home_dim_light(smart_home_t* smart_home, uint8_t id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        light_t* light = &smart_home->lights[i];
        if (light->id == id) {
            light->state = LIGHT_DIMMED;
            return 0;
        }
    }

    return -1;
}

// Get the state of a light
light_state_t smart_home_get_light_state(smart_home_t* smart_home, uint8_t id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        light_t* light = &smart_home->lights[i];
        if (light->id == id) {
            return light->state;
        }
    }

    return LIGHT_OFF;
}

// Print the state of all lights
void smart_home_print_lights(smart_home_t* smart_home) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        light_t* light = &smart_home->lights[i];
        printf("Light %d: %s, state: %d\n", light->id, light->name, light->state);
    }
}

// Main function
int main() {
    // Create a new smart home system
    smart_home_t* smart_home = smart_home_new();

    // Add some lights to the system
    smart_home_add_light(smart_home, 1, "Living Room Light");
    smart_home_add_light(smart_home, 2, "Kitchen Light");
    smart_home_add_light(smart_home, 3, "Bedroom Light");

    // Turn on the living room light
    smart_home_turn_on_light(smart_home, 1);

    // Dim the kitchen light
    smart_home_dim_light(smart_home, 2);

    // Print the state of all lights
    smart_home_print_lights(smart_home);

    return 0;
}