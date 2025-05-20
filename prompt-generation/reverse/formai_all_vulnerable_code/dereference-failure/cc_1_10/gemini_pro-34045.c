//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker
#define MAX_STEPS 100

// Define the structure of a fitness tracker
typedef struct {
    int steps[MAX_STEPS];
    int num_steps;
    time_t start_time;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->num_steps = 0;
    tracker->start_time = time(NULL);
    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker* tracker) {
    free(tracker);
}

// Add a step to the fitness tracker
void add_step(fitness_tracker* tracker) {
    if (tracker->num_steps < MAX_STEPS) {
        tracker->steps[tracker->num_steps++] = 1;
    }
}

// Get the total number of steps in the fitness tracker
int get_total_steps(fitness_tracker* tracker) {
    return tracker->num_steps;
}

// Get the average number of steps per day in the fitness tracker
double get_average_steps_per_day(fitness_tracker* tracker) {
    time_t end_time = time(NULL);
    double days = difftime(end_time, tracker->start_time) / (60 * 60 * 24);
    return tracker->num_steps / days;
}

// Print the fitness tracker data to the console
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Total steps: %d\n", tracker->num_steps);
    printf("Average steps per day: %.2f\n", get_average_steps_per_day(tracker));
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some steps to the fitness tracker
    for (int i = 0; i < 100; i++) {
        add_step(tracker);
    }

    // Print the fitness tracker data to the console
    print_fitness_tracker(tracker);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}