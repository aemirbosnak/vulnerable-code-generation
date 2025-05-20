//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 50

typedef struct Light {
    char name[MAX_NAME_LENGTH];
    int is_on; // 1 for ON, 0 for OFF
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Maximum light capacity reached!\n");
        return;
    }
    strcpy(lights[light_count].name, name);
    lights[light_count].is_on = 0; // Initialize light to OFF
    light_count++;
    printf("Added light: %s\n", name);
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            if (lights[i].is_on) {
                printf("Light '%s' is now ON.\n", lights[i].name);
            } else {
                printf("Light '%s' is now OFF.\n", lights[i].name);
            }
            return;
        }
    }
    printf("Light with name '%s' not found!\n", name);
}

void set_light(const char *name, int status) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = status;
            printf("Light '%s' is now %s.\n", lights[i].name, status ? "ON" : "OFF");
            return;
        }
    }
    printf("Light with name '%s' not found!\n", name);
}

void list_lights() {
    printf("List of Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf(" - %s: %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
}

void initialize_lights() {
    // Example light names
    add_light("Living Room");
    add_light("Bedroom");
    add_light("Kitchen");
    add_light("Bathroom");
}

int main(int argc, char *argv[]) {
    initialize_lights();

    if (argc < 2) {
        printf("Usage: %s [command] [light_name]\n", argv[0]);
        printf("Commands: toggle, on, off, list\n");
        return 1;
    }

    char *command = argv[1];

    if (strcmp(command, "list") == 0) {
        list_lights();
    } else if (argc < 3) {
        printf("Please specify a light name.\n");
        return 1;
    } else {
        char *light_name = argv[2];
        if (strcmp(command, "toggle") == 0) {
            toggle_light(light_name);
        } else if (strcmp(command, "on") == 0) {
            set_light(light_name, 1);
        } else if (strcmp(command, "off") == 0) {
            set_light(light_name, 0);
        } else {
            printf("Unknown command: %s\n", command);
            return 1;
        }
    }

    return 0;
}