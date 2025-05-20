//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the fitness tracker struct
typedef struct fitness_tracker {
    char *name;
    int age;
    int height;
    int weight;
    int steps;
    int calories;
    int distance;
    time_t start_time;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *new_fitness_tracker(char *name, int age, int height, int weight) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->name = strdup(name);
    tracker->age = age;
    tracker->height = height;
    tracker->weight = weight;
    tracker->steps = 0;
    tracker->calories = 0;
    tracker->distance = 0;
    tracker->start_time = time(NULL);
    return tracker;
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker);
}

// Update the fitness tracker with new data
void update_fitness_tracker(fitness_tracker *tracker, int steps, int calories, int distance) {
    tracker->steps += steps;
    tracker->calories += calories;
    tracker->distance += distance;
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Height: %d\n", tracker->height);
    printf("Weight: %d\n", tracker->weight);
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Distance: %d\n", tracker->distance);
    printf("Start time: %s", ctime(&tracker->start_time));
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker *tracker = new_fitness_tracker("John Doe", 30, 180, 80);

    // Update the fitness tracker with new data
    update_fitness_tracker(tracker, 10000, 500, 10);

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}