//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to generate a random number between min and max
int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Structure to represent a fitness tracker
typedef struct fitness_tracker {
    int steps_taken;
    int calories_burned;
    int distance_traveled;
    int sleep_duration;
    int heart_rate;
    char *mood;
} fitness_tracker;

// Function to create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->steps_taken = 0;
    tracker->calories_burned = 0;
    tracker->distance_traveled = 0;
    tracker->sleep_duration = 0;
    tracker->heart_rate = 0;
    tracker->mood = "Happy";
    return tracker;
}

// Function to update the fitness tracker with new data
void update_fitness_tracker(fitness_tracker *tracker, int steps_taken, int calories_burned, int distance_traveled, int sleep_duration, int heart_rate, char *mood) {
    tracker->steps_taken += steps_taken;
    tracker->calories_burned += calories_burned;
    tracker->distance_traveled += distance_traveled;
    tracker->sleep_duration += sleep_duration;
    tracker->heart_rate += heart_rate;
    tracker->mood = mood;
}

// Function to print the fitness tracker data
void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Steps taken: %d\n", tracker->steps_taken);
    printf("Calories burned: %d\n", tracker->calories_burned);
    printf("Distance traveled: %d\n", tracker->distance_traveled);
    printf("Sleep duration: %d\n", tracker->sleep_duration);
    printf("Heart rate: %d\n", tracker->heart_rate);
    printf("Mood: %s\n", tracker->mood);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new fitness tracker
    fitness_tracker *tracker = create_fitness_tracker();

    // Update the fitness tracker with some sample data
    update_fitness_tracker(tracker, random_number(1000, 10000), random_number(100, 500), random_number(1, 10), random_number(6, 9), random_number(60, 100), "Great!");

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free(tracker);

    return 0;
}