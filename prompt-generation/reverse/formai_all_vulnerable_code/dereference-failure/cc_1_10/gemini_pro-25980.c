//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 100000

// Define the structure of a step
typedef struct {
    int count;
    time_t timestamp;
} step_t;

// Define the structure of a fitness tracker
typedef struct {
    step_t* steps;
    int num_steps;
    int goal;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t* fitness_tracker_create(int goal) {
    fitness_tracker_t* tracker = malloc(sizeof(fitness_tracker_t));
    tracker->steps = malloc(sizeof(step_t) * MAX_STEPS);
    tracker->num_steps = 0;
    tracker->goal = goal;
    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker_t* tracker) {
    free(tracker->steps);
    free(tracker);
}

// Add a step to a fitness tracker
void fitness_tracker_add_step(fitness_tracker_t* tracker) {
    if (tracker->num_steps < MAX_STEPS) {
        tracker->steps[tracker->num_steps].count = 1;
        tracker->steps[tracker->num_steps].timestamp = time(NULL);
        tracker->num_steps++;
    }
}

// Get the total number of steps in a fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker_t* tracker) {
    return tracker->num_steps;
}

// Get the goal number of steps for a fitness tracker
int fitness_tracker_get_goal(fitness_tracker_t* tracker) {
    return tracker->goal;
}

// Check if a fitness tracker has met its goal
bool fitness_tracker_has_met_goal(fitness_tracker_t* tracker) {
    return tracker->num_steps >= tracker->goal;
}

// Print the steps in a fitness tracker
void fitness_tracker_print_steps(fitness_tracker_t* tracker) {
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("%d steps at %s\n", tracker->steps[i].count, ctime(&tracker->steps[i].timestamp));
    }
}

// Main function
int main() {
    // Create a fitness tracker with a goal of 10000 steps
    fitness_tracker_t* tracker = fitness_tracker_create(10000);

    // Add some steps to the fitness tracker
    for (int i = 0; i < 10; i++) {
        fitness_tracker_add_step(tracker);
    }

    // Print the steps in the fitness tracker
    fitness_tracker_print_steps(tracker);

    // Check if the fitness tracker has met its goal
    if (fitness_tracker_has_met_goal(tracker)) {
        printf("Congratulations! You have met your goal of %d steps.\n", tracker->goal);
    } else {
        printf("Keep going! You have %d steps to go.\n", tracker->goal - tracker->num_steps);
    }

    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);

    return 0;
}