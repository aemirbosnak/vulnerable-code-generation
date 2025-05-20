//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the structure for a light
typedef struct {
    char* name;
    int brightness;
    int status;
} Light;

// Define the global array of lights
Light lights[MAX_LIGHTS];

// Define the function prototypes
void initLights();
void printLights();
void setLight(char* name, int brightness);
void toggleLight(char* name);
void turnOffAllLights();

int main() {
    // Initialize the lights
    initLights();

    // Print the initial state of the lights
    printf("Initial state of lights:\n");
    printLights();

    // Set the brightness of a light
    setLight("Living Room", 50);

    // Toggle the status of a light
    toggleLight("Bedroom");

    // Turn off all lights
    turnOffAllLights();

    // Print the final state of the lights
    printf("\nFinal state of lights:\n");
    printLights();

    return 0;
}

// Initialize the lights with default values
void initLights() {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        lights[i].name = malloc(20 * sizeof(char));
        strcpy(lights[i].name, "Light ");
        lights[i].brightness = 0;
        lights[i].status = 0;
    }
}

// Print the state of the lights
void printLights() {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        printf("%s - Brightness: %d, Status: %s\n", lights[i].name, lights[i].brightness, lights[i].status? "On" : "Off");
    }
}

// Set the brightness of a light
void setLight(char* name, int brightness) {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = brightness;
            break;
        }
    }
}

// Toggle the status of a light
void toggleLight(char* name) {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status =!lights[i].status;
            break;
        }
    }
}

// Turn off all lights
void turnOffAllLights() {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        lights[i].status = 0;
    }
}