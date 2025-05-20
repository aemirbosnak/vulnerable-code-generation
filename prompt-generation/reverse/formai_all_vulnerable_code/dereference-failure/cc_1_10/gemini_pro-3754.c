//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <time.h>

// Define the maximum number of lights in the smart home
#define MAX_LIGHTS 10

// Define the different states of a light
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the structure of a light
typedef struct {
    bool is_on;
    light_state_t state;
    uint32_t brightness;
} light_t;

// Define the structure of the smart home
typedef struct {
    light_t lights[MAX_LIGHTS];
    uint32_t num_lights;
} smart_home_t;

// Create a new smart home
smart_home_t *create_smart_home() {
    smart_home_t *smart_home = malloc(sizeof(smart_home_t));
    if (smart_home == NULL) {
        return NULL;
    }

    smart_home->num_lights = 0;

    return smart_home;
}

// Add a new light to the smart home
bool add_light(smart_home_t *smart_home, light_t *light) {
    if (smart_home->num_lights >= MAX_LIGHTS) {
        return false;
    }

    smart_home->lights[smart_home->num_lights++] = *light;

    return true;
}

// Turn on a light
bool turn_on_light(smart_home_t *smart_home, uint32_t light_index) {
    if (light_index >= smart_home->num_lights) {
        return false;
    }

    smart_home->lights[light_index].is_on = true;

    return true;
}

// Turn off a light
bool turn_off_light(smart_home_t *smart_home, uint32_t light_index) {
    if (light_index >= smart_home->num_lights) {
        return false;
    }

    smart_home->lights[light_index].is_on = false;

    return true;
}

// Dim a light
bool dim_light(smart_home_t *smart_home, uint32_t light_index, uint32_t brightness) {
    if (light_index >= smart_home->num_lights) {
        return false;
    }

    smart_home->lights[light_index].state = LIGHT_DIMMED;
    smart_home->lights[light_index].brightness = brightness;

    return true;
}

// Get the state of a light
light_state_t get_light_state(smart_home_t *smart_home, uint32_t light_index) {
    if (light_index >= smart_home->num_lights) {
        return LIGHT_OFF;
    }

    return smart_home->lights[light_index].state;
}

// Get the brightness of a light
uint32_t get_light_brightness(smart_home_t *smart_home, uint32_t light_index) {
    if (light_index >= smart_home->num_lights) {
        return 0;
    }

    return smart_home->lights[light_index].brightness;
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t *smart_home = create_smart_home();

    // Add some lights to the smart home
    light_t light1 = { .is_on = false, .state = LIGHT_OFF, .brightness = 0 };
    add_light(smart_home, &light1);

    light_t light2 = { .is_on = true, .state = LIGHT_ON, .brightness = 100 };
    add_light(smart_home, &light2);

    light_t light3 = { .is_on = false, .state = LIGHT_DIMMED, .brightness = 50 };
    add_light(smart_home, &light3);

    // Turn on light 1
    turn_on_light(smart_home, 0);

    // Turn off light 2
    turn_off_light(smart_home, 1);

    // Dim light 3
    dim_light(smart_home, 2, 75);

    // Get the state of light 1
    light_state_t state = get_light_state(smart_home, 0);

    // Get the brightness of light 3
    uint32_t brightness = get_light_brightness(smart_home, 2);

    // Print the state and brightness of the lights
    printf("Light 1 state: %d\n", state);
    printf("Light 3 brightness: %d\n", brightness);

    // Free the smart home
    free(smart_home);

    return 0;
}