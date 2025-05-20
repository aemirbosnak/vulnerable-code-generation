//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the states of a light
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the structure of a light
typedef struct {
    char name[20];
    light_state_t state;
} light_t;

// Define the array of lights
light_t lights[MAX_LIGHTS];

// Define the function to initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        char num[3];
        sprintf(num, "%d", i + 1);
        strcat(lights[i].name, num);
        lights[i].state = LIGHT_OFF;
    }
}

// Define the function to print the status of the lights
void print_lights() {
    printf("Lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("  %s: ", lights[i].name);
        switch (lights[i].state) {
            case LIGHT_OFF:
                printf("OFF\n");
                break;
            case LIGHT_ON:
                printf("ON\n");
                break;
            case LIGHT_DIMMED:
                printf("DIMMED\n");
                break;
        }
    }
}

// Define the function to turn on a light
void turn_on_light(int light_number) {
    if (light_number < 1 || light_number > MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }

    lights[light_number - 1].state = LIGHT_ON;
}

// Define the function to turn off a light
void turn_off_light(int light_number) {
    if (light_number < 1 || light_number > MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }

    lights[light_number - 1].state = LIGHT_OFF;
}

// Define the function to dim a light
void dim_light(int light_number) {
    if (light_number < 1 || light_number > MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }

    lights[light_number - 1].state = LIGHT_DIMMED;
}

// Define the function to get the state of a light
light_state_t get_light_state(int light_number) {
    if (light_number < 1 || light_number > MAX_LIGHTS) {
        printf("Invalid light number\n");
        return LIGHT_OFF;
    }

    return lights[light_number - 1].state;
}

// Define the main function
int main() {
    // Initialize the lights
    init_lights();

    // Print the status of the lights
    print_lights();

    // Turn on light 1
    turn_on_light(1);

    // Dim light 3
    dim_light(3);

    // Turn off light 5
    turn_off_light(5);

    // Print the status of the lights
    print_lights();

    return 0;
}