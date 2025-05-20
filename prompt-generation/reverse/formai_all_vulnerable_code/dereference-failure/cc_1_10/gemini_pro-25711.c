//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker
#define MAX_STEPS 10000

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
    int steps[MAX_STEPS];
    int steps_count;
    time_t start_time;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* fitness_tracker_create() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->steps_count = 0;
    tracker->start_time = time(NULL);
    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker* tracker) {
    free(tracker);
}

// Add a step to the tracker
void fitness_tracker_add_step(fitness_tracker* tracker) {
    if (tracker->steps_count < MAX_STEPS) {
        tracker->steps[tracker->steps_count++] = time(NULL);
    }
}

// Get the total number of steps in the tracker
int fitness_tracker_get_steps_count(fitness_tracker* tracker) {
    return tracker->steps_count;
}

// Get the start time of the tracker
time_t fitness_tracker_get_start_time(fitness_tracker* tracker) {
    return tracker->start_time;
}

// Print the steps in the tracker
void fitness_tracker_print_steps(fitness_tracker* tracker) {
    for (int i = 0; i < tracker->steps_count; i++) {
        printf("%d: %s\n", i, ctime(&tracker->steps[i]));
    }
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = fitness_tracker_create();

    // Add some steps to the tracker
    for (int i = 0; i < 100; i++) {
        fitness_tracker_add_step(tracker);
    }

    // Print the steps in the tracker
    fitness_tracker_print_steps(tracker);

    // Get the total number of steps in the tracker
    int steps_count = fitness_tracker_get_steps_count(tracker);
    printf("Total steps: %d\n", steps_count);

    // Get the start time of the tracker
    time_t start_time = fitness_tracker_get_start_time(tracker);
    printf("Start time: %s\n", ctime(&start_time));

    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);

    return 0;
}