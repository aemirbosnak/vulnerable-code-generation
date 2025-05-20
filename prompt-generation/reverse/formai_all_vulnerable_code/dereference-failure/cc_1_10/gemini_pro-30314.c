//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker.
#define MAX_STEPS 1000

// Define the structure of a step.
typedef struct {
    int timestamp;  // The time when the step was taken, in seconds since the epoch.
    int x;          // The x-coordinate of the step, in millimeters.
    int y;          // The y-coordinate of the step, in millimeters.
    int z;          // The z-coordinate of the step, in millimeters.
} step_t;

// Define the structure of the fitness tracker.
typedef struct {
    int num_steps;      // The number of steps that have been stored in the tracker.
    step_t steps[MAX_STEPS];  // The array of steps that have been stored in the tracker.
} fitness_tracker_t;

// Create a new fitness tracker.
fitness_tracker_t* create_fitness_tracker() {
    fitness_tracker_t* tracker = malloc(sizeof(fitness_tracker_t));
    tracker->num_steps = 0;
    return tracker;
}

// Destroy a fitness tracker.
void destroy_fitness_tracker(fitness_tracker_t* tracker) {
    free(tracker);
}

// Add a step to the fitness tracker.
void add_step(fitness_tracker_t* tracker, step_t step) {
    tracker->steps[tracker->num_steps] = step;
    tracker->num_steps++;
}

// Get the number of steps that have been stored in the fitness tracker.
int get_num_steps(fitness_tracker_t* tracker) {
    return tracker->num_steps;
}

// Get the step at the specified index.
step_t get_step(fitness_tracker_t* tracker, int index) {
    return tracker->steps[index];
}

// Print the steps in the fitness tracker.
void print_steps(fitness_tracker_t* tracker) {
    for (int i = 0; i < tracker->num_steps; i++) {
        step_t step = tracker->steps[i];
        printf("Step %d: timestamp=%d, x=%d, y=%d, z=%d\n", i, step.timestamp, step.x, step.y, step.z);
    }
}

// Main function.
int main() {
    // Create a new fitness tracker.
    fitness_tracker_t* tracker = create_fitness_tracker();

    // Add some steps to the fitness tracker.
    for (int i = 0; i < 10; i++) {
        step_t step;
        step.timestamp = time(NULL);
        step.x = rand() % 100;
        step.y = rand() % 100;
        step.z = rand() % 100;
        add_step(tracker, step);
    }

    // Print the steps in the fitness tracker.
    print_steps(tracker);

    // Destroy the fitness tracker.
    destroy_fitness_tracker(tracker);

    return 0;
}