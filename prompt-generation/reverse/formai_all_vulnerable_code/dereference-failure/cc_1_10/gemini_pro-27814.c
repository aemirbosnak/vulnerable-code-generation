//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the history
#define MAX_STEPS_HISTORY 100

// Define the structure of a step history entry
typedef struct {
    time_t timestamp;
    int steps;
} step_history_entry;

// Define the structure of the fitness tracker
typedef struct {
    int current_steps;
    step_history_entry history[MAX_STEPS_HISTORY];
    int history_index;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* fitness_tracker_create() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->current_steps = 0;
    tracker->history_index = 0;
    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker* tracker) {
    free(tracker);
}

// Add steps to the fitness tracker
void fitness_tracker_add_steps(fitness_tracker* tracker, int steps) {
    tracker->current_steps += steps;
    
    // Add the step history entry to the history
    tracker->history[tracker->history_index].timestamp = time(NULL);
    tracker->history[tracker->history_index].steps = steps;
    tracker->history_index = (tracker->history_index + 1) % MAX_STEPS_HISTORY;
}

// Get the current steps from the fitness tracker
int fitness_tracker_get_current_steps(fitness_tracker* tracker) {
    return tracker->current_steps;
}

// Get the total steps from the fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker* tracker) {
    int total_steps = 0;
    for (int i = 0; i < MAX_STEPS_HISTORY; i++) {
        total_steps += tracker->history[i].steps;
    }
    return total_steps;
}

// Get the average steps per day from the fitness tracker
float fitness_tracker_get_average_steps_per_day(fitness_tracker* tracker) {
    time_t now = time(NULL);
    time_t oldest_timestamp = tracker->history[tracker->history_index].timestamp;
    int days = (int)((now - oldest_timestamp) / (60 * 60 * 24));
    if (days == 0) {
        days = 1;
    }
    float average_steps_per_day = (float)fitness_tracker_get_total_steps(tracker) / days;
    return average_steps_per_day;
}

// Print the fitness tracker data
void fitness_tracker_print(fitness_tracker* tracker) {
    printf("Current steps: %d\n", tracker->current_steps);
    printf("Total steps: %d\n", fitness_tracker_get_total_steps(tracker));
    printf("Average steps per day: %f\n", fitness_tracker_get_average_steps_per_day(tracker));
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = fitness_tracker_create();
    
    // Add steps to the fitness tracker
    fitness_tracker_add_steps(tracker, 1000);
    fitness_tracker_add_steps(tracker, 2000);
    fitness_tracker_add_steps(tracker, 3000);
    
    // Print the fitness tracker data
    fitness_tracker_print(tracker);
    
    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);
    
    return 0;
}