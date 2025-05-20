//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fitness tracker's data structure
typedef struct {
    char *name;
    int steps;
    int distance;
    int calories;
    int heart_rate;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker(char *name) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->name = name;
    tracker->steps = 0;
    tracker->distance = 0;
    tracker->calories = 0;
    tracker->heart_rate = 0;
    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker);
}

// Update the fitness tracker's data
void update_fitness_tracker(fitness_tracker *tracker, int steps, int distance, int calories, int heart_rate) {
    tracker->steps += steps;
    tracker->distance += distance;
    tracker->calories += calories;
    tracker->heart_rate += heart_rate;
}

// Print the fitness tracker's data
void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Steps: %d\n", tracker->steps);
    printf("Distance: %d\n", tracker->distance);
    printf("Calories: %d\n", tracker->calories);
    printf("Heart rate: %d\n", tracker->heart_rate);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker *tracker = create_fitness_tracker("John Doe");

    // Update the fitness tracker's data
    update_fitness_tracker(tracker, 10000, 5000, 2000, 120);

    // Print the fitness tracker's data
    print_fitness_tracker(tracker);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}