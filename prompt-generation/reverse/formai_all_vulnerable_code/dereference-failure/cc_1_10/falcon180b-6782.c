//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a fitness tracker
struct fitness_tracker {
    int steps;
    int heart_rate;
    int active_minutes;
    int calories_burned;
};

// Function to initialize a new fitness tracker
struct fitness_tracker* init_fitness_tracker() {
    struct fitness_tracker* tracker = (struct fitness_tracker*) malloc(sizeof(struct fitness_tracker));
    tracker->steps = 0;
    tracker->heart_rate = 0;
    tracker->active_minutes = 0;
    tracker->calories_burned = 0;
    return tracker;
}

// Function to add steps to the fitness tracker
void add_steps(struct fitness_tracker* tracker, int steps) {
    tracker->steps += steps;
}

// Function to add heart rate to the fitness tracker
void add_heart_rate(struct fitness_tracker* tracker, int heart_rate) {
    tracker->heart_rate += heart_rate;
}

// Function to add active minutes to the fitness tracker
void add_active_minutes(struct fitness_tracker* tracker, int active_minutes) {
    tracker->active_minutes += active_minutes;
}

// Function to add calories burned to the fitness tracker
void add_calories_burned(struct fitness_tracker* tracker, int calories_burned) {
    tracker->calories_burned += calories_burned;
}

// Function to print the fitness tracker data
void print_fitness_tracker(struct fitness_tracker* tracker) {
    printf("Steps: %d\n", tracker->steps);
    printf("Heart Rate: %d\n", tracker->heart_rate);
    printf("Active Minutes: %d\n", tracker->active_minutes);
    printf("Calories Burned: %d\n", tracker->calories_burned);
}

// Function to recursively add fitness tracker data
void recursive_fitness_tracker(struct fitness_tracker* tracker, int steps, int heart_rate, int active_minutes, int calories_burned) {
    add_steps(tracker, steps);
    add_heart_rate(tracker, heart_rate);
    add_active_minutes(tracker, active_minutes);
    add_calories_burned(tracker, calories_burned);
    print_fitness_tracker(tracker);
    recursive_fitness_tracker(tracker, steps + 1000, heart_rate + 10, active_minutes + 30, calories_burned + 50);
}

// Main function to initialize and run the fitness tracker
int main() {
    struct fitness_tracker* tracker = init_fitness_tracker();
    recursive_fitness_tracker(tracker, 0, 0, 0, 0);
    return 0;
}