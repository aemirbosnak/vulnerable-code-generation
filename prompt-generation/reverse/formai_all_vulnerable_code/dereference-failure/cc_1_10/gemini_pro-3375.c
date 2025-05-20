//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home light states
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIMMED
} light_state_t;

// Define the smart home light commands
typedef enum {
    CMD_TURN_ON,
    CMD_TURN_OFF,
    CMD_DIM,
    CMD_BRIGHTEN
} light_command_t;

// Define the smart home light control structure
typedef struct {
    light_state_t state;
    char *name;
} light_control_t;

// Create a new smart home light control object
light_control_t *light_control_new(char *name) {
    light_control_t *light = malloc(sizeof(light_control_t));
    light->state = LIGHT_OFF;
    light->name = strdup(name);
    return light;
}

// Delete a smart home light control object
void light_control_delete(light_control_t *light) {
    free(light->name);
    free(light);
}

// Turn on the smart home light
void light_control_turn_on(light_control_t *light) {
    light->state = LIGHT_ON;
    printf("%s turned on\n", light->name);
}

// Turn off the smart home light
void light_control_turn_off(light_control_t *light) {
    light->state = LIGHT_OFF;
    printf("%s turned off\n", light->name);
}

// Dim the smart home light
void light_control_dim(light_control_t *light) {
    light->state = LIGHT_DIMMED;
    printf("%s dimmed\n", light->name);
}

// Brighten the smart home light
void light_control_brighten(light_control_t *light) {
    light->state = LIGHT_ON;
    printf("%s brightened\n", light->name);
}

// Process a smart home light command
void light_control_process_command(light_control_t *light, light_command_t command) {
    switch (command) {
        case CMD_TURN_ON:
            light_control_turn_on(light);
            break;
        case CMD_TURN_OFF:
            light_control_turn_off(light);
            break;
        case CMD_DIM:
            light_control_dim(light);
            break;
        case CMD_BRIGHTEN:
            light_control_brighten(light);
            break;
    }
}

// Main function
int main() {
    // Create a smart home light control object
    light_control_t *light = light_control_new("Living Room Light");

    // Process a series of smart home light commands
    light_control_process_command(light, CMD_TURN_ON);
    light_control_process_command(light, CMD_DIM);
    light_control_process_command(light, CMD_TURN_OFF);

    // Delete the smart home light control object
    light_control_delete(light);

    return 0;
}