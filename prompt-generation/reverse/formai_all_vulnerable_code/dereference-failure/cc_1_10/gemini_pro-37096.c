//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps and calories
#define MAX_STEPS 10000
#define MAX_CALORIES 5000

// Define the data structure for the fitness tracker
typedef struct {
    int steps;
    int calories;
    time_t last_updated;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->steps = 0;
    tracker->calories = 0;
    tracker->last_updated = time(NULL);
    return tracker;
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker* tracker) {
    free(tracker);
}

// Add steps to the fitness tracker
void add_steps(fitness_tracker* tracker, int steps) {
    tracker->steps += steps;
    tracker->last_updated = time(NULL);
}

// Add calories to the fitness tracker
void add_calories(fitness_tracker* tracker, int calories) {
    tracker->calories += calories;
    tracker->last_updated = time(NULL);
}

// Get the number of steps from the fitness tracker
int get_steps(fitness_tracker* tracker) {
    return tracker->steps;
}

// Get the number of calories from the fitness tracker
int get_calories(fitness_tracker* tracker) {
    return tracker->calories;
}

// Get the last updated time of the fitness tracker
time_t get_last_updated(fitness_tracker* tracker) {
    return tracker->last_updated;
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Last Updated: %s", ctime(&tracker->last_updated));
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some steps and calories to the tracker
    add_steps(tracker, 1000);
    add_calories(tracker, 200);

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}