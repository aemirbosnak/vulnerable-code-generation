//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct {
    int timestamp;
    int count;
} step_t;

// Define the structure of the fitness tracker
typedef struct {
    int num_steps;
    step_t steps[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *fitness_tracker_create() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    if (tracker == NULL) {
        return NULL;
    }

    tracker->num_steps = 0;

    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker_t *tracker) {
    free(tracker);
}

// Add a step to a fitness tracker
void fitness_tracker_add_step(fitness_tracker_t *tracker, int timestamp, int count) {
    tracker->steps[tracker->num_steps].timestamp = timestamp;
    tracker->steps[tracker->num_steps].count = count;
    tracker->num_steps++;
}

// Get the total number of steps in a fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker_t *tracker) {
    return tracker->num_steps;
}

// Get the steps taken in a given time interval
int fitness_tracker_get_steps_in_interval(fitness_tracker_t *tracker, int start_timestamp, int end_timestamp) {
    int total_steps = 0;

    for (int i = 0; i < tracker->num_steps; i++) {
        if (tracker->steps[i].timestamp >= start_timestamp && tracker->steps[i].timestamp <= end_timestamp) {
            total_steps += tracker->steps[i].count;
        }
    }

    return total_steps;
}

// Print the steps in a fitness tracker
void fitness_tracker_print_steps(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("%d: %d\n", tracker->steps[i].timestamp, tracker->steps[i].count);
    }
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker_t *tracker = fitness_tracker_create();

    // Add some steps to the fitness tracker
    fitness_tracker_add_step(tracker, 1589743200, 1000);
    fitness_tracker_add_step(tracker, 1589743260, 2000);
    fitness_tracker_add_step(tracker, 1589743320, 3000);

    // Get the total number of steps in the fitness tracker
    int total_steps = fitness_tracker_get_total_steps(tracker);

    // Get the steps taken in a given time interval
    int steps_in_interval = fitness_tracker_get_steps_in_interval(tracker, 1589743200, 1589743320);

    // Print the steps in the fitness tracker
    fitness_tracker_print_steps(tracker);

    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);

    return 0;
}