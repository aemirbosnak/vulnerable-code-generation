//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char *name;
    int state; // 0=off, 1=on
} light;

light lights[MAX_LIGHTS];

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].name = malloc(10);
        sprintf(lights[i].name, "Light %d", i);
        lights[i].state = 0;
    }
}

void print_lights() {
    printf("Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("  %s: %s\n", lights[i].name, lights[i].state ? "on" : "off");
    }
}

void toggle_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    lights[id].state = !lights[id].state;
}

int main() {
    // Initialize lights
    init_lights();

    // Print initial light states
    print_lights();

    // Toggle light 2
    toggle_light(1);

    // Print updated light states
    print_lights();

    return 0;
}