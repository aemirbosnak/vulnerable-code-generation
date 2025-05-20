//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the light states
enum light_state {
    OFF,
    ON,
    DIM
};

// Define the light commands
enum light_command {
    TURN_ON,
    TURN_OFF,
    DIM_UP,
    DIM_DOWN
};

// Define the light struct
struct light {
    enum light_state state;
    int brightness;
};

// Create a new light
struct light* create_light() {
    struct light* light = malloc(sizeof(struct light));
    light->state = OFF;
    light->brightness = 0;
    return light;
}

// Destroy a light
void destroy_light(struct light* light) {
    free(light);
}

// Turn on the light
void turn_on_light(struct light* light) {
    light->state = ON;
    light->brightness = 100;
}

// Turn off the light
void turn_off_light(struct light* light) {
    light->state = OFF;
    light->brightness = 0;
}

// Dim up the light
void dim_up_light(struct light* light) {
    if (light->brightness < 100) {
        light->brightness += 10;
    }
}

// Dim down the light
void dim_down_light(struct light* light) {
    if (light->brightness > 0) {
        light->brightness -= 10;
    }
}

// Print the light state
void print_light_state(struct light* light) {
    switch (light->state) {
    case OFF:
        printf("Light is off\n");
        break;
    case ON:
        printf("Light is on\n");
        break;
    case DIM:
        printf("Light is dimmed to %d%%\n", light->brightness);
        break;
    }
}

// Main function
int main() {
    // Create a new light
    struct light* light = create_light();

    // Turn on the light
    turn_on_light(light);

    // Dim up the light
    dim_up_light(light);

    // Print the light state
    print_light_state(light);

    // Dim down the light
    dim_down_light(light);

    // Print the light state
    print_light_state(light);

    // Turn off the light
    turn_off_light(light);

    // Destroy the light
    destroy_light(light);

    return 0;
}