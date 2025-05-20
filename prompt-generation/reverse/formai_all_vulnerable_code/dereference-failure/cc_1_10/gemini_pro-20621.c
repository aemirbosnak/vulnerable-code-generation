//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int id;
    char* name;
    bool state;
} Light;

Light* createLight(int id, char* name) {
    Light* light = (Light*)malloc(sizeof(Light));
    light->id = id;
    light->name = name;
    light->state = LIGHT_OFF;
    return light;
}

void destroyLight(Light* light) {
    free(light->name);
    free(light);
}

void toggleLight(Light* light) {
    light->state = !light->state;
}

void printLight(Light* light) {
    printf("Light %d (%s) is %s\n", light->id, light->name, light->state ? "ON" : "OFF");
}

int main() {
    // Create a smart home with 3 lights
    Light* lights[3] = {
        createLight(1, "Living Room Light"),
        createLight(2, "Kitchen Light"),
        createLight(3, "Bedroom Light")
    };

    // Turn on the living room light
    toggleLight(lights[0]);

    // Print the status of all the lights
    for (int i = 0; i < 3; i++) {
        printLight(lights[i]);
    }

    // Destroy the lights
    for (int i = 0; i < 3; i++) {
        destroyLight(lights[i]);
    }

    return 0;
}