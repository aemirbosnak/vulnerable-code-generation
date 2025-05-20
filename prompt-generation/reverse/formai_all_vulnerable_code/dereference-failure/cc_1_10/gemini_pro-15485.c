//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define the number of traffic lights
#define NUM_LIGHTS 3

// Define the states of a traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN
} light_state;

// Define the data structure for a traffic light
typedef struct {
    light_state state;
    int duration;
} traffic_light;

// Define the data structure for the traffic light controller
typedef struct {
    traffic_light lights[NUM_LIGHTS];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} traffic_light_controller;

// Create a new traffic light controller
traffic_light_controller* create_traffic_light_controller() {
    traffic_light_controller* controller = malloc(sizeof(traffic_light_controller));
    if (controller == NULL) {
        return NULL;
    }

    // Initialize the mutex and condition variable
    pthread_mutex_init(&controller->mutex, NULL);
    pthread_cond_init(&controller->cond, NULL);

    // Initialize the traffic lights
    for (int i = 0; i < NUM_LIGHTS; i++) {
        controller->lights[i].state = RED;
        controller->lights[i].duration = 10;
    }

    return controller;
}

// Destroy a traffic light controller
void destroy_traffic_light_controller(traffic_light_controller* controller) {
    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&controller->mutex);
    pthread_cond_destroy(&controller->cond);

    // Free the memory allocated for the controller
    free(controller);
}

// Change the state of a traffic light
void change_light_state(traffic_light_controller* controller, int light_num, light_state state) {
    // Lock the mutex
    pthread_mutex_lock(&controller->mutex);

    // Change the state of the traffic light
    controller->lights[light_num].state = state;

    // Signal the condition variable
    pthread_cond_signal(&controller->cond);

    // Unlock the mutex
    pthread_mutex_unlock(&controller->mutex);
}

// Wait for a traffic light to change state
void wait_for_light_state_change(traffic_light_controller* controller, int light_num, light_state state) {
    // Lock the mutex
    pthread_mutex_lock(&controller->mutex);

    // Wait for the condition variable to be signaled
    while (controller->lights[light_num].state != state) {
        pthread_cond_wait(&controller->cond, &controller->mutex);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&controller->mutex);
}

// Run the traffic light controller
void run_traffic_light_controller(traffic_light_controller* controller) {
    // Loop forever
    while (1) {
        // Change the state of each traffic light in sequence
        for (int i = 0; i < NUM_LIGHTS; i++) {
            // Change the state of the traffic light to green
            change_light_state(controller, i, GREEN);

            // Wait for the green light to expire
            sleep(controller->lights[i].duration);

            // Change the state of the traffic light to yellow
            change_light_state(controller, i, YELLOW);

            // Wait for the yellow light to expire
            sleep(controller->lights[i].duration);

            // Change the state of the traffic light to red
            change_light_state(controller, i, RED);
        }
    }
}

// Main function
int main() {
    // Create a traffic light controller
    traffic_light_controller* controller = create_traffic_light_controller();

    // Run the traffic light controller
    run_traffic_light_controller(controller);

    // Destroy the traffic light controller
    destroy_traffic_light_controller(controller);

    return 0;
}