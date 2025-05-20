//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the light states
typedef enum {
    LIGHT_OFF,
    LIGHT_ON
} light_state_t;

// Define the light structure
typedef struct {
    int id;
    char *name;
    light_state_t state;
} light_t;

// Define the smart home structure
typedef struct {
    light_t lights[MAX_LIGHTS];
    int num_lights;
} smart_home_t;

// Create a new smart home
smart_home_t *smart_home_new() {
    smart_home_t *smart_home = malloc(sizeof(smart_home_t));
    if (smart_home == NULL) {
        return NULL;
    }

    smart_home->num_lights = 0;

    return smart_home;
}

// Destroy a smart home
void smart_home_destroy(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        free(smart_home->lights[i].name);
    }

    free(smart_home);
}

// Add a light to a smart home
int smart_home_add_light(smart_home_t *smart_home, int id, char *name) {
    if (smart_home->num_lights >= MAX_LIGHTS) {
        return -1;
    }

    light_t *light = &smart_home->lights[smart_home->num_lights];
    light->id = id;
    light->name = strdup(name);
    light->state = LIGHT_OFF;

    smart_home->num_lights++;

    return 0;
}

// Turn on a light
int smart_home_turn_on_light(smart_home_t *smart_home, int id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (smart_home->lights[i].id == id) {
            smart_home->lights[i].state = LIGHT_ON;
            return 0;
        }
    }

    return -1;
}

// Turn off a light
int smart_home_turn_off_light(smart_home_t *smart_home, int id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (smart_home->lights[i].id == id) {
            smart_home->lights[i].state = LIGHT_OFF;
            return 0;
        }
    }

    return -1;
}

// Get the state of a light
light_state_t smart_home_get_light_state(smart_home_t *smart_home, int id) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (smart_home->lights[i].id == id) {
            return smart_home->lights[i].state;
        }
    }

    return LIGHT_OFF;
}

// Print the status of a smart home
void smart_home_print_status(smart_home_t *smart_home) {
    printf("Smart Home Status:\n");
    for (int i = 0; i < smart_home->num_lights; i++) {
        printf("Light %d: %s (%s)\n", smart_home->lights[i].id, smart_home->lights[i].name, smart_home->lights[i].state == LIGHT_ON ? "On" : "Off");
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t *smart_home = smart_home_new();

    // Add some lights to the smart home
    smart_home_add_light(smart_home, 1, "Living Room Light");
    smart_home_add_light(smart_home, 2, "Kitchen Light");
    smart_home_add_light(smart_home, 3, "Bedroom Light");

    // Turn on the living room light
    smart_home_turn_on_light(smart_home, 1);

    // Turn off the kitchen light
    smart_home_turn_off_light(smart_home, 2);

    // Print the status of the smart home
    smart_home_print_status(smart_home);

    // Destroy the smart home
    smart_home_destroy(smart_home);

    return 0;
}