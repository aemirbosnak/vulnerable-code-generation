//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct {
    int timestamp;
    int count;
} step_t;

// Define the structure of a fitness tracker
typedef struct {
    char *name;
    int step_count;
    step_t steps[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *create_fitness_tracker(char *name) {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    tracker->name = strdup(name);
    tracker->step_count = 0;
    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker_t *tracker) {
    free(tracker->name);
    free(tracker);
}

// Add a step to a fitness tracker
void add_step(fitness_tracker_t *tracker, int timestamp, int count) {
    tracker->steps[tracker->step_count].timestamp = timestamp;
    tracker->steps[tracker->step_count].count = count;
    tracker->step_count++;
}

// Get the total number of steps in a fitness tracker
int get_total_steps(fitness_tracker_t *tracker) {
    return tracker->step_count;
}

// Get the average number of steps per day in a fitness tracker
float get_average_steps_per_day(fitness_tracker_t *tracker) {
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);
    int days_since_epoch = now_tm->tm_yday + 1;
    return (float)tracker->step_count / days_since_epoch;
}

// Print the steps in a fitness tracker
void print_steps(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->step_count; i++) {
        printf("Step %d: %d steps at %d\n", i + 1, tracker->steps[i].count, tracker->steps[i].timestamp);
    }
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker_t *tracker = create_fitness_tracker("John Smith");

    // Add some steps to the fitness tracker
    add_step(tracker, time(NULL), 1000);
    add_step(tracker, time(NULL) + 3600, 2000);
    add_step(tracker, time(NULL) + 7200, 3000);

    // Print the steps in the fitness tracker
    print_steps(tracker);

    // Get the total number of steps in the fitness tracker
    int total_steps = get_total_steps(tracker);
    printf("Total steps: %d\n", total_steps);

    // Get the average number of steps per day in the fitness tracker
    float average_steps_per_day = get_average_steps_per_day(tracker);
    printf("Average steps per day: %.2f\n", average_steps_per_day);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}