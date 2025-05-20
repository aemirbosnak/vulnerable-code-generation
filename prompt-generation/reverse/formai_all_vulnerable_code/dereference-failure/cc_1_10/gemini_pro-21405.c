//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of lights in a smart home
#define MAX_LIGHTS 10

// Define the states of a light
typedef enum {
    LIGHT_OFF,
    LIGHT_ON
} light_state_t;

// Define the smart home data structure
typedef struct {
    light_state_t lights[MAX_LIGHTS];
} smart_home_t;

// Create a new smart home
smart_home_t* smart_home_new() {
    smart_home_t* smart_home = malloc(sizeof(smart_home_t));
    if (smart_home == NULL) {
        return NULL;
    }

    // Initialize all lights to off
    for (int i = 0; i < MAX_LIGHTS; i++) {
        smart_home->lights[i] = LIGHT_OFF;
    }

    return smart_home;
}

// Delete a smart home
void smart_home_delete(smart_home_t* smart_home) {
    free(smart_home);
}

// Turn on a light
void smart_home_light_on(smart_home_t* smart_home, int light_number) {
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number %d\n", light_number);
        return;
    }

    smart_home->lights[light_number] = LIGHT_ON;
}

// Turn off a light
void smart_home_light_off(smart_home_t* smart_home, int light_number) {
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number %d\n", light_number);
        return;
    }

    smart_home->lights[light_number] = LIGHT_OFF;
}

// Print the state of all lights
void smart_home_print_lights(smart_home_t* smart_home) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %s\n", i, smart_home->lights[i] == LIGHT_ON ? "ON" : "OFF");
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t* smart_home = smart_home_new();

    // Turn on light 1
    smart_home_light_on(smart_home, 1);

    // Turn off light 3
    smart_home_light_off(smart_home, 3);

    // Print the state of all lights
    smart_home_print_lights(smart_home);

    // Delete the smart home
    smart_home_delete(smart_home);

    return 0;
}