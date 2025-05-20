//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 10000

// Define the structure of a step entry
typedef struct {
    int steps;
    char *timestamp;
} step_entry;

// Define the structure of a fitness tracker
typedef struct {
    char *name;
    int num_steps;
    step_entry *steps;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker(char *name) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->name = strdup(name);
    tracker->num_steps = 0;
    tracker->steps = malloc(sizeof(step_entry) * MAX_STEPS);
    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker->steps);
    free(tracker);
}

// Add a step entry to a fitness tracker
void add_step_entry(fitness_tracker *tracker, int steps, char *timestamp) {
    tracker->steps[tracker->num_steps].steps = steps;
    tracker->steps[tracker->num_steps].timestamp = strdup(timestamp);
    tracker->num_steps++;
}

// Print the steps recorded by a fitness tracker
void print_steps(fitness_tracker *tracker) {
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("%s: %d steps\n", tracker->steps[i].timestamp, tracker->steps[i].steps);
    }
}

// Get the total number of steps recorded by a fitness tracker
int get_total_steps(fitness_tracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        total_steps += tracker->steps[i].steps;
    }
    return total_steps;
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker *tracker = create_fitness_tracker("My Fitness Tracker");

    // Add some step entries to the fitness tracker
    add_step_entry(tracker, 1000, "2023-01-01 12:00:00");
    add_step_entry(tracker, 2000, "2023-01-02 12:00:00");
    add_step_entry(tracker, 3000, "2023-01-03 12:00:00");

    // Print the steps recorded by the fitness tracker
    print_steps(tracker);

    // Get the total number of steps recorded by the fitness tracker
    int total_steps = get_total_steps(tracker);
    printf("Total steps: %d\n", total_steps);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}