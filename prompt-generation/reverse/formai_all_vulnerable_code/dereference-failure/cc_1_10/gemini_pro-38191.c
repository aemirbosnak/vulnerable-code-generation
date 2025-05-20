//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char *name;
    int state; // 0 = off, 1 = on
} light;

light lights[MAX_LIGHTS];

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].name = NULL;
        lights[i].state = 0;
    }
}

void add_light(int id, char *name) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    if (lights[id].name != NULL) {
        printf("Light with ID %d already exists\n", id);
        return;
    }

    lights[id].name = strdup(name);
    lights[id].state = 0;
}

void remove_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    if (lights[id].name == NULL) {
        printf("Light with ID %d does not exist\n", id);
        return;
    }

    free(lights[id].name);
    lights[id].name = NULL;
    lights[id].state = 0;
}

void toggle_light(int id) {
    if (id < 0 || id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", id);
        return;
    }

    if (lights[id].name == NULL) {
        printf("Light with ID %d does not exist\n", id);
        return;
    }

    lights[id].state = !lights[id].state;
}

void print_lights() {
    printf("Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].name != NULL) {
            printf(" - %d: %s (%s)\n", lights[i].id, lights[i].name, lights[i].state ? "on" : "off");
        }
    }
}

int main() {
    init_lights();

    add_light(0, "Living Room");
    add_light(1, "Kitchen");
    add_light(2, "Bedroom");

    print_lights();

    toggle_light(0);
    toggle_light(2);

    print_lights();

    return 0;
}