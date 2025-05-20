//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for lights
typedef struct {
    int id;
    char name[20];
    int state;
} Light;

// Function to initialize lights
Light *initialize_lights(int num_lights) {
    Light *lights = (Light *)malloc(sizeof(Light) * num_lights);
    for (int i = 0; i < num_lights; i++) {
        sprintf(lights[i].name, "Light %d", i+1);
        lights[i].id = i+1;
        lights[i].state = 0;
    }
    return lights;
}

// Function to control lights
void control_lights(Light *lights, int num_lights) {
    int light_id = 0;
    int on = 1;

    printf("Enter light ID to turn on (0 to exit): ");
    scanf("%d", &light_id);

    if (light_id == 0) {
        printf("Light control program ended.\n");
        return;
    }

    while (light_id!= 0) {
        printf("Turn light %d %s on? (y/n): ", light_id, lights[light_id].name);
        scanf("%s", &on);

        if (on == 'y') {
            lights[light_id].state = 1;
            printf("Light %d %s turned on.\n", light_id, lights[light_id].name);
        } else if (on == 'n') {
            lights[light_id].state = 0;
            printf("Light %d %s turned off.\n", light_id, lights[light_id].name);
        }

        printf("Enter light ID to turn on (0 to exit): ");
        scanf("%d", &light_id);
    }
}

// Main function
int main() {
    srand(time(0)); // Set random seed

    int num_lights = 5; // Number of lights
    Light *lights = initialize_lights(num_lights);

    printf("Smart home light control program\n");
    printf("-------------------------------\n");
    printf("Available lights:\n");
    for (int i = 0; i < num_lights; i++) {
        printf("%d. %s\n", i+1, lights[i].name);
    }

    printf("\n");
    control_lights(lights, num_lights);

    return 0;
}