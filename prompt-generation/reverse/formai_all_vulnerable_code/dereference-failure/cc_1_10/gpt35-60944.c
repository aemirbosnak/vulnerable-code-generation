//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LIGHTS 5
#define MAX_BRIGHTNESS 100

typedef struct {
    int brightness;
    int isOn;
} Light;

void printStatus(Light lights[]) {
    printf("---------------------------------\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %s | Brightness: %d\n", i+1, lights[i].isOn ? "On" : "Off", lights[i].brightness);
    }
    printf("---------------------------------\n");
}

void turnOnLight(Light *light) {
    light->isOn = 1;
    printf("You turn on the light\n");
}

void turnOffLight(Light *light) {
    light->isOn = 0;
    printf("You turn off the light\n");
}

void adjustBrightness(Light *light, int newBrightness) {
    if (newBrightness >= 0 && newBrightness <= MAX_BRIGHTNESS) {
        light->brightness = newBrightness;
        printf("You adjust the brightness of the light to %d\n", newBrightness);
    }
    else {
        printf("Invalid brightness value\n");
    }
}

int main() {
    srand(time(NULL));
    Light lights[NUM_LIGHTS];
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].brightness = rand() % 101;
        lights[i].isOn = rand() % 2;
    }
    printf("Welcome to the medieval era smart home light control system!\n");
    while (1) {
        printStatus(lights);
        printf("What would you like to do?\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Adjust the brightness of a light\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the index of the light you want to turn on (1-%d): ", NUM_LIGHTS);
                int lightIndex;
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= NUM_LIGHTS) {
                    turnOnLight(&lights[lightIndex-1]);
                }
                else {
                    printf("Invalid light index\n");
                }
                break;

            case 2:
                printf("Enter the index of the light you want to turn off (1-%d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= NUM_LIGHTS) {
                    turnOffLight(&lights[lightIndex-1]);
                }
                else {
                    printf("Invalid light index\n");
                }
                break;

            case 3:
                printf("Enter the index of the light you want to adjust the brightness of (1-%d): ", NUM_LIGHTS);
                scanf("%d", &lightIndex);
                if (lightIndex >= 1 && lightIndex <= NUM_LIGHTS) {
                    printf("Enter the new brightness level (0-%d): ", MAX_BRIGHTNESS);
                    int newBrightness;
                    scanf("%d", &newBrightness);
                    adjustBrightness(&lights[lightIndex-1], newBrightness);
                }
                else {
                    printf("Invalid light index\n");
                }
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}