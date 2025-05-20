//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>

// A step forward, and two steps back...
#define STEP 1
#define TWO_STEPS 2

// The fitness tracker
typedef struct {
    int steps;
    int floors;
    int calories;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker* create_fitness_tracker() {
    FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
    tracker->steps = 0;
    tracker->floors = 0;
    tracker->calories = 0;
    return tracker;
}

// Take a step
void take_step(FitnessTracker* tracker) {
    tracker->steps += STEP;
    tracker->calories += STEP;
}

// Climb a floor
void climb_floor(FitnessTracker* tracker) {
    tracker->floors += TWO_STEPS;
    tracker->calories += TWO_STEPS;
}

// Burn calories
void burn_calories(FitnessTracker* tracker, int calories) {
    tracker->calories -= calories;
}

// Get the number of steps taken
int get_steps(FitnessTracker* tracker) {
    return tracker->steps;
}

// Get the number of floors climbed
int get_floors(FitnessTracker* tracker) {
    return tracker->floors;
}

// Get the number of calories burned
int get_calories(FitnessTracker* tracker) {
    return tracker->calories;
}

// Print the fitness tracker data
void print_fitness_tracker(FitnessTracker* tracker) {
    printf("Steps: %d\nFloors: %d\nCalories: %d\n",
        tracker->steps, tracker->floors, tracker->calories);
}

// The main function
int main() {
    // Create a new fitness tracker
    FitnessTracker* tracker = create_fitness_tracker();

    // Take 10 steps
    for (int i = 0; i < 10; i++) {
        take_step(tracker);
    }
    // Climb 5 floors
    for (int i = 0; i < 5; i++) {
        climb_floor(tracker);
    }
    // Burn 100 calories
    burn_calories(tracker, 100);

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the fitness tracker
    free(tracker);

    return 0;
}