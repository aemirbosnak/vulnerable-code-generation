//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold the light information */
typedef struct {
    char name[20];
    int brightness;
    int on;
} Light;

/* Function to check if the given light is on */
int is_on(Light* light) {
    return light->on == 1;
}

/* Function to turn on the given light */
void turn_on(Light* light) {
    light->on = 1;
    printf("%s has been turned on.\n", light->name);
}

/* Function to turn off the given light */
void turn_off(Light* light) {
    light->on = 0;
    printf("%s has been turned off.\n", light->name);
}

/* Function to set the brightness of the given light */
void set_brightness(Light* light, int brightness) {
    light->brightness = brightness;
    printf("%s brightness has been set to %d.\n", light->name, brightness);
}

int main() {
    int num_lights = 3;
    
    /* Allocate an array of Light structs */
    Light* lights = (Light*) malloc(num_lights * sizeof(Light));
    
    /* Initialize the light array with default values */
    for (int i = 0; i < num_lights; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i+1);
        lights[i].brightness = 100;
        lights[i].on = 0;
    }
    
    /* Example usage of light control functions */
    turn_on(&lights[0]);
    set_brightness(&lights[1], 50);
    turn_off(&lights[2]);
    
    /* Free the memory allocated for the light array */
    free(lights);
    
    return 0;
}