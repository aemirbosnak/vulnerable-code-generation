//FormAI DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
void powerOn(int *lights, int numLights);
void powerOff(int *lights, int numLights);
void toggle(int *lights, int numLights, int lightNum);
void printState(int *lights, int numLights);

int main() {
    int numLights = 4;
    int *lights = (int*)malloc(numLights * sizeof(int));

    printf("Welcome to the Smart Home Light Control System!\n");

    /* Power on all lights */
    powerOn(lights, numLights);

    /* Toggle light #2 */
    toggle(lights, numLights, 2);

    /* Toggle light #4 */
    toggle(lights, numLights, 4);

    /* Turn off all lights */
    powerOff(lights, numLights);

    /* Print final state of lights */
    printState(lights, numLights);

    free(lights);
    return 0;
}

/* Turn on all lights */
void powerOn(int *lights, int numLights) {
    printf("Turning on all lights...\n");
    for(int i=0; i<numLights; i++) {
        lights[i] = 1;
    }
}

/* Turn off all lights */
void powerOff(int *lights, int numLights) {
    printf("Turning off all lights...\n");
    for(int i=0; i<numLights; i++) {
        lights[i] = 0;
    }
}

/* Toggle a single light */
void toggle(int *lights, int numLights, int lightNum) {
    if(lightNum > numLights) {
        printf("Invalid light number. Light number must be less than or equal to %d.\n", numLights);
        return;
    }

    printf("Toggling light #%d...\n", lightNum);
    lights[lightNum-1] = !lights[lightNum-1];
}

/* Print the state of all lights */
void printState(int *lights, int numLights) {
    printf("Current light state:\n");
    for(int i=0; i<numLights; i++) {
        printf("Light #%d: %s\n", i+1, lights[i] ? "On" : "Off");
    }
}