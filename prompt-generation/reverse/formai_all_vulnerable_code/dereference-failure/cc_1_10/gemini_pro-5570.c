//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the possible light states
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the possible light commands
typedef enum {
    LIGHT_CMD_TURN_ON,
    LIGHT_CMD_TURN_OFF,
    LIGHT_CMD_DIM,
    LIGHT_CMD_BRIGHTEN
} light_cmd_t;

// Define the light struct
typedef struct {
    light_state_t state;
    int brightness;
} light_t;

// Create a new light
light_t* light_new() {
    light_t* light = malloc(sizeof(light_t));
    light->state = LIGHT_OFF;
    light->brightness = 0;
    return light;
}

// Free a light
void light_free(light_t* light) {
    free(light);
}

// Turn the light on
void light_on(light_t* light) {
    light->state = LIGHT_ON;
    light->brightness = 100;
}

// Turn the light off
void light_off(light_t* light) {
    light->state = LIGHT_OFF;
    light->brightness = 0;
}

// Dim the light
void light_dim(light_t* light) {
    if (light->brightness > 0) {
        light->brightness -= 10;
    }
}

// Brighten the light
void light_brighten(light_t* light) {
    if (light->brightness < 100) {
        light->brightness += 10;
    }
}

// Execute a light command
void light_execute_cmd(light_t* light, light_cmd_t cmd) {
    switch (cmd) {
        case LIGHT_CMD_TURN_ON:
            light_on(light);
            break;
        case LIGHT_CMD_TURN_OFF:
            light_off(light);
            break;
        case LIGHT_CMD_DIM:
            light_dim(light);
            break;
        case LIGHT_CMD_BRIGHTEN:
            light_brighten(light);
            break;
    }
}

// Print the light state
void light_print_state(light_t* light) {
    switch (light->state) {
        case LIGHT_OFF:
            printf("Light is off\n");
            break;
        case LIGHT_ON:
            printf("Light is on at %d%% brightness\n", light->brightness);
            break;
        case LIGHT_DIMMED:
            printf("Light is dimmed at %d%% brightness\n", light->brightness);
            break;
    }
}

// Main function
int main() {
    // Create a new light
    light_t* light = light_new();

    // Execute some light commands
    light_execute_cmd(light, LIGHT_CMD_TURN_ON);
    light_execute_cmd(light, LIGHT_CMD_DIM);
    light_execute_cmd(light, LIGHT_CMD_BRIGHTEN);
    light_execute_cmd(light, LIGHT_CMD_TURN_OFF);

    // Print the light state
    light_print_state(light);

    // Free the light
    light_free(light);

    return 0;
}