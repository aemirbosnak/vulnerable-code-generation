//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
// Linus Torvalds style C Fitness Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct {
    time_t timestamp;
    int count;
} step_t;

// Define the structure of a fitness tracker
typedef struct {
    char *name;
    int total_steps;
    step_t steps[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *fitness_tracker_new(char *name) {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    tracker->name = strdup(name);
    tracker->total_steps = 0;
    for (int i = 0; i < MAX_STEPS; i++) {
        tracker->steps[i].timestamp = 0;
        tracker->steps[i].count = 0;
    }
    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker_t *tracker) {
    free(tracker->name);
    free(tracker);
}

// Add a step to a fitness tracker
void fitness_tracker_add_step(fitness_tracker_t *tracker, time_t timestamp, int count) {
    tracker->steps[tracker->total_steps].timestamp = timestamp;
    tracker->steps[tracker->total_steps].count = count;
    tracker->total_steps++;
}

// Get the total number of steps in a fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker_t *tracker) {
    return tracker->total_steps;
}

// Get the steps in a fitness tracker
step_t *fitness_tracker_get_steps(fitness_tracker_t *tracker) {
    return tracker->steps;
}

// Print the steps in a fitness tracker
void fitness_tracker_print_steps(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->total_steps; i++) {
        printf("%ld: %d\n", tracker->steps[i].timestamp, tracker->steps[i].count);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new fitness tracker
    fitness_tracker_t *tracker = fitness_tracker_new("Linus Torvalds");

    // Add some steps to the fitness tracker
    fitness_tracker_add_step(tracker, time(NULL), 1000);
    fitness_tracker_add_step(tracker, time(NULL) + 60 * 60, 1500);
    fitness_tracker_add_step(tracker, time(NULL) + 2 * 60 * 60, 2000);

    // Print the steps in the fitness tracker
    fitness_tracker_print_steps(tracker);

    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);

    return 0;
}