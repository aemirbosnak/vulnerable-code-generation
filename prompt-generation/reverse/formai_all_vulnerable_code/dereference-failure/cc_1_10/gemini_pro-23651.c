//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Constants
#define NUM_LIGHTS      4
#define NUM_SENSORS    3

// Sensor data
typedef struct {
    uint8_t type;    // 0=motion, 1=temperature, 2=humidity
    uint16_t value;  // Sensor reading
} sensor_data_t;

// Light state
typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_DIM
} light_state_t;

// Smart home state
typedef struct {
    light_state_t lights[NUM_LIGHTS];
    sensor_data_t sensors[NUM_SENSORS];
} smart_home_state_t;

// Function prototypes
void update_smart_home_state(smart_home_state_t *state, sensor_data_t *data);
void print_smart_home_state(smart_home_state_t *state);

// Main function
int main() {
    // Initialize smart home state
    smart_home_state_t state;
    for (int i = 0; i < NUM_LIGHTS; i++) {
        state.lights[i] = LIGHT_OFF;
    }
    for (int i = 0; i < NUM_SENSORS; i++) {
        state.sensors[i] = (sensor_data_t){
            .type = i,
            .value = 0
        };
    }

    // Read sensor data
    while (1) {
        for (int i = 0; i < NUM_SENSORS; i++) {
            state.sensors[i].value = rand() % 100;
        }

        // Update smart home state
        update_smart_home_state(&state, state.sensors);

        // Print smart home state
        print_smart_home_state(&state);
    }

    return 0;
}

// Update smart home state
void update_smart_home_state(smart_home_state_t *state, sensor_data_t *data) {
    // Update lights
    for (int i = 0; i < NUM_LIGHTS; i++) {
        switch (data[i].type) {
            case 0: // Motion sensor
                if (data[i].value > 50) {
                    state->lights[i] = LIGHT_ON;
                } else {
                    state->lights[i] = LIGHT_OFF;
                }
                break;
            case 1: // Temperature sensor
                if (data[i].value > 250) {
                    state->lights[i] = LIGHT_DIM;
                } else {
                    state->lights[i] = LIGHT_OFF;
                }
                break;
            case 2: // Humidity sensor
                if (data[i].value > 600) {
                    state->lights[i] = LIGHT_OFF;
                } else {
                    state->lights[i] = LIGHT_ON;
                }
                break;
        }
    }
}

// Print smart home state
void print_smart_home_state(smart_home_state_t *state) {
    printf("Smart home state:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("  Light %d: %s\n", i, state->lights[i] == LIGHT_OFF ? "OFF" : (state->lights[i] == LIGHT_ON ? "ON" : "DIM"));
    }
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("  Sensor %d: type=%d, value=%d\n", i, state->sensors[i].type, state->sensors[i].value);
    }
}