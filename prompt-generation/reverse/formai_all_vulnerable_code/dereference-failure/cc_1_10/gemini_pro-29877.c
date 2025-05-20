//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights in the home
#define MAX_LIGHTS 10

// Define the different states a light can be in
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the structure of a light
typedef struct {
    char *name;
    light_state_t state;
    int brightness;
} light_t;

// Define the structure of the smart home
typedef struct {
    light_t lights[MAX_LIGHTS];
    int num_lights;
} smart_home_t;

// Create a new smart home
smart_home_t *create_smart_home() {
    smart_home_t *home = malloc(sizeof(smart_home_t));
    home->num_lights = 0;
    return home;
}

// Add a new light to the smart home
void add_light(smart_home_t *home, char *name) {
    if (home->num_lights >= MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached\n");
        return;
    }
    home->lights[home->num_lights].name = malloc(strlen(name) + 1);
    strcpy(home->lights[home->num_lights].name, name);
    home->lights[home->num_lights].state = LIGHT_OFF;
    home->lights[home->num_lights].brightness = 0;
    home->num_lights++;
}

// Turn a light on
void turn_on_light(smart_home_t *home, char *name) {
    for (int i = 0; i < home->num_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].state = LIGHT_ON;
            home->lights[i].brightness = 100;
            return;
        }
    }
    printf("Error: Light not found\n");
}

// Turn a light off
void turn_off_light(smart_home_t *home, char *name) {
    for (int i = 0; i < home->num_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].state = LIGHT_OFF;
            home->lights[i].brightness = 0;
            return;
        }
    }
    printf("Error: Light not found\n");
}

// Dim a light
void dim_light(smart_home_t *home, char *name, int brightness) {
    for (int i = 0; i < home->num_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].state = LIGHT_DIMMED;
            home->lights[i].brightness = brightness;
            return;
        }
    }
    printf("Error: Light not found\n");
}

// Print the status of all the lights in the smart home
void print_lights(smart_home_t *home) {
    for (int i = 0; i < home->num_lights; i++) {
        printf("%s: ", home->lights[i].name);
        switch (home->lights[i].state) {
            case LIGHT_OFF:
                printf("Off\n");
                break;
            case LIGHT_ON:
                printf("On\n");
                break;
            case LIGHT_DIMMED:
                printf("Dimmed (%d%%)\n", home->lights[i].brightness);
                break;
        }
    }
}

// Free the memory allocated for the smart home
void destroy_smart_home(smart_home_t *home) {
    for (int i = 0; i < home->num_lights; i++) {
        free(home->lights[i].name);
    }
    free(home);
}

int main() {
    // Create a new smart home
    smart_home_t *home = create_smart_home();

    // Add some lights to the smart home
    add_light(home, "Living Room Light");
    add_light(home, "Bedroom Light");
    add_light(home, "Kitchen Light");

    // Turn on the living room light
    turn_on_light(home, "Living Room Light");

    // Dim the bedroom light to 50% brightness
    dim_light(home, "Bedroom Light", 50);

    // Turn off the kitchen light
    turn_off_light(home, "Kitchen Light");

    // Print the status of all the lights in the smart home
    print_lights(home);

    // Free the memory allocated for the smart home
    destroy_smart_home(home);

    return 0;
}