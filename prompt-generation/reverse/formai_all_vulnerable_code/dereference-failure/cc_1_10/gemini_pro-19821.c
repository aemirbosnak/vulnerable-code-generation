//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be taken in a day
#define MAX_STEPS 10000

// Define the minimum number of steps that should be taken in a day
#define MIN_STEPS 5000

// Define the target number of steps that should be taken in a day
#define TARGET_STEPS 8000

// Create a struct to represent a fitness tracker
typedef struct fitness_tracker {
    int steps_taken;
    int calories_burned;
    int distance_traveled;
    time_t start_time;
    time_t end_time;
} fitness_tracker;

// Create a function to initialize a fitness tracker
fitness_tracker* init_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->steps_taken = 0;
    tracker->calories_burned = 0;
    tracker->distance_traveled = 0;
    tracker->start_time = time(NULL);
    tracker->end_time = time(NULL);
    return tracker;
}

// Create a function to update a fitness tracker
void update_fitness_tracker(fitness_tracker* tracker) {
    // Get the current time
    time_t now = time(NULL);

    // Update the steps taken
    int steps_taken = rand() % (MAX_STEPS - MIN_STEPS) + MIN_STEPS;
    tracker->steps_taken += steps_taken;

    // Update the calories burned
    int calories_burned = steps_taken * 0.05;
    tracker->calories_burned += calories_burned;

    // Update the distance traveled
    int distance_traveled = steps_taken * 0.0005;
    tracker->distance_traveled += distance_traveled;

    // Update the start time
    tracker->start_time = now;

    // Update the end time
    tracker->end_time = now;
}

// Create a function to print a fitness tracker
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Steps taken: %d\n", tracker->steps_taken);
    printf("Calories burned: %d\n", tracker->calories_burned);
    printf("Distance traveled: %d\n", tracker->distance_traveled);
    printf("Start time: %s\n", ctime(&tracker->start_time));
    printf("End time: %s\n", ctime(&tracker->end_time));
}

// Create a main function
int main() {
    // Initialize a fitness tracker
    fitness_tracker* tracker = init_fitness_tracker();

    // Update the fitness tracker
    update_fitness_tracker(tracker);

    // Print the fitness tracker
    print_fitness_tracker(tracker);

    // Free the fitness tracker
    free(tracker);

    return 0;
}