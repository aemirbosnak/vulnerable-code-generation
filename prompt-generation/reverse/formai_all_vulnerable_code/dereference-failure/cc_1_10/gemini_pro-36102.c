//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: lively
// Let's orchestrate a symphony of lights!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

typedef unsigned int light;

void flip(light* light) {
    *light = (*light + 1) % 3;
}

void show(light light) {
    switch (light) {
        case GREEN:
            printf("🟢");
            break;
        case YELLOW:
            printf("🟡");
            break;
        case RED:
            printf("🔴");
            break;
        default:
            printf("?");
    }
}

void traffic_light_controller(light* lights, int num_lights) {
    while (1) {
        for (light current = 0; current < num_lights; current += 2) {
            // Green on even lights
            lights[current] = GREEN;
            // Red on odd lights
            lights[current + 1] = RED;
            printf("Light %d: ", current);
            show(lights[current]);
            printf(" | Light %d: ", current + 1);
            show(lights[current + 1]);
            printf("\n");
            sleep(3);

            // Yellow on even lights
            lights[current] = YELLOW;
            printf("Light %d: ", current);
            show(lights[current]);
            printf(" | Light %d: ", current + 1);
            show(lights[current + 1]);
            printf("\n");
            sleep(1);
        }

        for (light current = 1; current < num_lights; current += 2) {
            // Green on odd lights
            lights[current] = GREEN;
            // Red on even lights
            lights[current - 1] = RED;
            printf("Light %d: ", current);
            show(lights[current]);
            printf(" | Light %d: ", current - 1);
            show(lights[current - 1]);
            printf("\n");
            sleep(3);

            // Yellow on odd lights
            lights[current] = YELLOW;
            printf("Light %d: ", current);
            show(lights[current]);
            printf(" | Light %d: ", current - 1);
            show(lights[current - 1]);
            printf("\n");
            sleep(1);
        }
    }
}

int main(int argc, char** argv) {
    int num_lights = argc - 1;
    if (num_lights <= 0) {
        printf("Please provide the number of traffic lights as command-line arguments.\n");
        return 1;
    }

    light* lights = malloc(num_lights * sizeof(light));
    if (!lights) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_lights; i++) {
        lights[i] = RED;
    }

    printf("Starting traffic light controller with %d lights...\n", num_lights);
    traffic_light_controller(lights, num_lights);

    // Cleanup
    free(lights);

    return 0;
}