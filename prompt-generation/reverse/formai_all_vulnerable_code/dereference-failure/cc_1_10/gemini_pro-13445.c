//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *name;
    bool is_on;
} light;

light *lights[10];
int num_lights = 0;

void add_light(char *name) {
    if (num_lights >= 10) {
        printf("Error: Too many lights.\n");
        return;
    }

    lights[num_lights] = malloc(sizeof(light));
    lights[num_lights]->name = strdup(name);
    lights[num_lights]->is_on = false;
    num_lights++;
}

void remove_light(char *name) {
    int i;

    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i]->name, name) == 0) {
            break;
        }
    }

    if (i == num_lights) {
        printf("Error: Light not found.\n");
        return;
    }

    free(lights[i]->name);
    free(lights[i]);

    for (i++; i < num_lights; i++) {
        lights[i - 1] = lights[i];
    }

    num_lights--;
}

void toggle_light(char *name) {
    int i;

    for (i = 0; i < num_lights; i++) {
        if (strcmp(lights[i]->name, name) == 0) {
            break;
        }
    }

    if (i == num_lights) {
        printf("Error: Light not found.\n");
        return;
    }

    lights[i]->is_on = !lights[i]->is_on;
}

void print_lights() {
    int i;

    for (i = 0; i < num_lights; i++) {
        printf("%s: %s\n", lights[i]->name, lights[i]->is_on ? "on" : "off");
    }
}

int main() {
    add_light("Kitchen");
    add_light("Living Room");
    add_light("Bedroom");

    toggle_light("Kitchen");
    toggle_light("Bedroom");

    print_lights();

    remove_light("Bedroom");

    print_lights();

    return 0;
}