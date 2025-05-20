//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of lights in the smart home
#define MAX_LIGHTS 10

// Define the possible states of a light
typedef enum {
    OFF,
    ON,
    DIMMED
} light_state_t;

// Define the structure of a light
typedef struct {
    char name[32];
    light_state_t state;
    int brightness;
} light_t;

// Define the smart home
typedef struct {
    light_t lights[MAX_LIGHTS];
    int num_lights;
} smart_home_t;

// Create a new smart home
smart_home_t* create_smart_home() {
    smart_home_t* smart_home = malloc(sizeof(smart_home_t));
    smart_home->num_lights = 0;
    return smart_home;
}

// Add a new light to the smart home
void add_light(smart_home_t* smart_home, char* name) {
    if (smart_home->num_lights >= MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached\n");
        return;
    }

    strcpy(smart_home->lights[smart_home->num_lights].name, name);
    smart_home->lights[smart_home->num_lights].state = OFF;
    smart_home->lights[smart_home->num_lights].brightness = 100;
    smart_home->num_lights++;
}

// Turn on a light
void turn_on_light(smart_home_t* smart_home, char* name) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (strcmp(smart_home->lights[i].name, name) == 0) {
            smart_home->lights[i].state = ON;
            printf("Light '%s' turned on\n", name);
            return;
        }
    }

    printf("Error: Light '%s' not found\n", name);
}

// Turn off a light
void turn_off_light(smart_home_t* smart_home, char* name) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (strcmp(smart_home->lights[i].name, name) == 0) {
            smart_home->lights[i].state = OFF;
            printf("Light '%s' turned off\n", name);
            return;
        }
    }

    printf("Error: Light '%s' not found\n", name);
}

// Dim a light
void dim_light(smart_home_t* smart_home, char* name, int brightness) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (strcmp(smart_home->lights[i].name, name) == 0) {
            smart_home->lights[i].state = DIMMED;
            smart_home->lights[i].brightness = brightness;
            printf("Light '%s' dimmed to %d%% brightness\n", name, brightness);
            return;
        }
    }

    printf("Error: Light '%s' not found\n", name);
}

// Get the state of a light
light_state_t get_light_state(smart_home_t* smart_home, char* name) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (strcmp(smart_home->lights[i].name, name) == 0) {
            return smart_home->lights[i].state;
        }
    }

    printf("Error: Light '%s' not found\n", name);
    return -1;
}

// Get the brightness of a light
int get_light_brightness(smart_home_t* smart_home, char* name) {
    for (int i = 0; i < smart_home->num_lights; i++) {
        if (strcmp(smart_home->lights[i].name, name) == 0) {
            return smart_home->lights[i].brightness;
        }
    }

    printf("Error: Light '%s' not found\n", name);
    return -1;
}

// Print the status of all lights
void print_smart_home_status(smart_home_t* smart_home) {
    printf("Smart Home Status:\n");
    for (int i = 0; i < smart_home->num_lights; i++) {
        printf(" - Light '%s': ", smart_home->lights[i].name);
        switch (smart_home->lights[i].state) {
            case OFF:
                printf("OFF\n");
                break;
            case ON:
                printf("ON\n");
                break;
            case DIMMED:
                printf("DIMMED (%d%% brightness)\n", smart_home->lights[i].brightness);
                break;
        }
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t* smart_home = create_smart_home();

    // Add some lights to the smart home
    add_light(smart_home, "Living Room Light");
    add_light(smart_home, "Kitchen Light");
    add_light(smart_home, "Bedroom Light");

    // Turn on the living room light
    turn_on_light(smart_home, "Living Room Light");

    // Dim the kitchen light to 50% brightness
    dim_light(smart_home, "Kitchen Light", 50);

    // Turn off the bedroom light
    turn_off_light(smart_home, "Bedroom Light");

    // Print the status of all lights
    print_smart_home_status(smart_home);

    // Free the memory allocated for the smart home
    free(smart_home);

    return 0;
}