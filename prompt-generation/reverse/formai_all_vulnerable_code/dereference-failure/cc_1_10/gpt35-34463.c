//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function to turn on the lights
void turnOnLights(int *lights, int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i] = 1;
    }
    printf("Lights are now on.\n");
}

// function to turn off the lights
void turnOffLights(int *lights, int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i] = 0;
    }
    printf("Lights are now off.\n");
}

// function to dim the lights
void dimLights(int *lights, int numLights, int brightness) {
    for (int i = 0; i < numLights; i++) {
        lights[i] = brightness;
    }
    printf("Lights are now dimmed to %d.\n", brightness);
}

int main() {
    // initialize variables
    int numLights = 3;
    int *lights = (int*)malloc(sizeof(int) * numLights);
    int brightness = 50;

    // turn on lights at startup
    turnOnLights(lights, numLights);

    // main loop for controlling the lights
    while (1) {
        // read input from user
        printf("Enter a command: ");
        char command = getchar();
        getchar(); // to remove the newline character

        // execute the command
        switch (command) {
            case '1':
                turnOnLights(lights, numLights);
                break;
            case '2':
                turnOffLights(lights, numLights);
                break;
            case '3':
                dimLights(lights, numLights, brightness);
                break;
            case '4':
                printf("Enter a brightness level (0 - 100): ");
                scanf("%d", &brightness);
                getchar(); // to remove the newline character
                dimLights(lights, numLights, brightness);
                break;
            case '5':
                // exit the program
                free(lights);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}