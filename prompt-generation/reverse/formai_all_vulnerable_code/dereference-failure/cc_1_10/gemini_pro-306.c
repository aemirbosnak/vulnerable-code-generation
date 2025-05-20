//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char *name;
    int state; // 0 = off, 1 = on
} light;

light lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].name = malloc(16);
        sprintf(lights[i].name, "Light %d", i);
        lights[i].state = 0;
    }
}

// Print the status of the lights
void print_lights() {
    printf("Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("  %s: %s\n", lights[i].name, lights[i].state ? "on" : "off");
    }
}

// Turn a light on or off
void set_light(int id, int state) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    lights[id].state = state;
}

// Get the state of a light
int get_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return -1;
    }

    return lights[id].state;
}

// Toggle the state of a light
void toggle_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    lights[id].state = !lights[id].state;
}

// Main function
int main() {
    // Initialize the lights
    init_lights();

    // Print the initial status of the lights
    print_lights();

    // Turn on light 0
    set_light(0, 1);

    // Toggle light 3
    toggle_light(3);

    // Print the new status of the lights
    print_lights();

    return 0;
}