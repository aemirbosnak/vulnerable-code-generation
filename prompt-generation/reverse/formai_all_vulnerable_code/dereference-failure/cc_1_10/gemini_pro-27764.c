//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of steps that can be stored in the log
#define MAX_STEPS 1000

// Define the structure of a log entry
typedef struct {
    time_t timestamp;
    int steps;
} LogEntry;

// Define the fitness tracker structure
typedef struct {
    char name[32];
    LogEntry log[MAX_STEPS];
    int num_steps;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker* create_fitness_tracker(char* name) {
    FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
    strcpy(tracker->name, name);
    tracker->num_steps = 0;
    return tracker;
}

// Add a new log entry to the fitness tracker
void add_log_entry(FitnessTracker* tracker, time_t timestamp, int steps) {
    tracker->log[tracker->num_steps].timestamp = timestamp;
    tracker->log[tracker->num_steps].steps = steps;
    tracker->num_steps++;
}

// Get the total number of steps recorded by the fitness tracker
int get_total_steps(FitnessTracker* tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        total_steps += tracker->log[i].steps;
    }
    return total_steps;
}

// Get the average number of steps per day recorded by the fitness tracker
float get_avg_steps_per_day(FitnessTracker* tracker) {
    float avg_steps_per_day = 0;
    time_t first_timestamp = tracker->log[0].timestamp;
    time_t last_timestamp = tracker->log[tracker->num_steps - 1].timestamp;
    int num_days = (last_timestamp - first_timestamp) / (60 * 60 * 24);
    avg_steps_per_day = (float)get_total_steps(tracker) / num_days;
    return avg_steps_per_day;
}

// Print the fitness tracker's log to the console
void print_log(FitnessTracker* tracker) {
    printf("Fitness tracker log for %s:\n", tracker->name);
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("%s: %d steps\n", ctime(&tracker->log[i].timestamp), tracker->log[i].steps);
    }
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(FitnessTracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    FitnessTracker* tracker = create_fitness_tracker("John");

    // Add some log entries to the fitness tracker
    add_log_entry(tracker, time(NULL), 1000);
    add_log_entry(tracker, time(NULL), 2000);
    add_log_entry(tracker, time(NULL), 3000);

    // Print the fitness tracker's log to the console
    print_log(tracker);

    // Get the total number of steps recorded by the fitness tracker
    int total_steps = get_total_steps(tracker);
    printf("Total steps: %d\n", total_steps);

    // Get the average number of steps per day recorded by the fitness tracker
    float avg_steps_per_day = get_avg_steps_per_day(tracker);
    printf("Average steps per day: %.2f\n", avg_steps_per_day);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}