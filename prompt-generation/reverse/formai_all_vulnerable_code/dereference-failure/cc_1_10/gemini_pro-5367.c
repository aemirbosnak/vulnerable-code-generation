//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the light structure
typedef struct {
    char *name;
    bool state;  // True if the light is on, false if it is off
} light;

// Define the smart home structure
typedef struct {
    light lights[MAX_LIGHTS];
    int num_lights;
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
    smart_home *home = malloc(sizeof(smart_home));
    home->num_lights = 0;
    return home;
}

// Add a light to the smart home
void add_light(smart_home *home, char *name) {
    if (home->num_lights == MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached\n");
        return;
    }

    home->lights[home->num_lights].name = malloc(strlen(name) + 1);
    strcpy(home->lights[home->num_lights].name, name);
    home->lights[home->num_lights].state = false;
    home->num_lights++;
}

// Turn a light on
void turn_on_light(smart_home *home, char *name) {
    for (int i = 0; i < home->num_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].state = true;
            return;
        }
    }

    printf("Error: Light not found\n");
}

// Turn a light off
void turn_off_light(smart_home *home, char *name) {
    for (int i = 0; i < home->num_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].state = false;
            return;
        }
    }

    printf("Error: Light not found\n");
}

// Print the status of all lights
void print_lights(smart_home *home) {
    for (int i = 0; i < home->num_lights; i++) {
        printf("%s: %s\n", home->lights[i].name, home->lights[i].state ? "On" : "Off");
    }
}

// Free the memory allocated for the smart home
void free_smart_home(smart_home *home) {
    for (int i = 0; i < home->num_lights; i++) {
        free(home->lights[i].name);
    }
    free(home);
}

// Main function
int main() {
    // Create a smart home
    smart_home *home = create_smart_home();

    // Add some lights to the smart home
    add_light(home, "Kitchen");
    add_light(home, "Living Room");
    add_light(home, "Bedroom");

    // Turn on the kitchen light
    turn_on_light(home, "Kitchen");

    // Turn off the bedroom light
    turn_off_light(home, "Bedroom");

    // Print the status of all lights
    print_lights(home);

    // Free the memory allocated for the smart home
    free_smart_home(home);

    return 0;
}