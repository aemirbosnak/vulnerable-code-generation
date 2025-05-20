//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    char *name;
    int steps;
    int calories;
    int distance;
} fitness_tracker;

fitness_tracker *create_fitness_tracker(char *name) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->name = strdup(name);
    tracker->steps = 0;
    tracker->calories = 0;
    tracker->distance = 0;
    return tracker;
}

void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker);
}

void add_steps(fitness_tracker *tracker, int steps) {
    tracker->steps += steps;
}

void add_calories(fitness_tracker *tracker, int calories) {
    tracker->calories += calories;
}

void add_distance(fitness_tracker *tracker, int distance) {
    tracker->distance += distance;
}

void print_fitness_tracker(fitness_tracker *tracker) {
    printf("%s\n", tracker->name);
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Distance: %d\n", tracker->distance);
}

int main() {
    // Create a fitness tracker for yourself
    fitness_tracker *my_tracker = create_fitness_tracker("John Doe");

    // Add some steps to your tracker
    add_steps(my_tracker, 10000);

    // Add some calories to your tracker
    add_calories(my_tracker, 2000);

    // Add some distance to your tracker
    add_distance(my_tracker, 10);

    // Print your fitness tracker
    print_fitness_tracker(my_tracker);

    // Destroy your fitness tracker
    destroy_fitness_tracker(my_tracker);

    return 0;
}