//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the log.
#define MAX_STEPS 100

// Define the structure of a step log entry.
typedef struct step_log_entry {
    time_t timestamp;
    int steps;
} step_log_entry;

// Define the structure of the fitness tracker.
typedef struct fitness_tracker {
    int step_count;
    step_log_entry log[MAX_STEPS];
    int log_index;
} fitness_tracker;

// Create a new fitness tracker.
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->step_count = 0;
    tracker->log_index = 0;
    return tracker;
}

// Add a step to the fitness tracker.
void add_step(fitness_tracker* tracker) {
    tracker->step_count++;
    tracker->log[tracker->log_index].timestamp = time(NULL);
    tracker->log[tracker->log_index].steps = tracker->step_count;
    tracker->log_index++;
}

// Get the total number of steps taken by the fitness tracker.
int get_step_count(fitness_tracker* tracker) {
    return tracker->step_count;
}

// Get the step log from the fitness tracker.
step_log_entry* get_step_log(fitness_tracker* tracker) {
    return tracker->log;
}

// Get the number of steps taken in the last minute.
int get_steps_in_last_minute(fitness_tracker* tracker) {
    int steps = 0;
    time_t now = time(NULL);
    for (int i = tracker->log_index - 1; i >= 0; i--) {
        if (now - tracker->log[i].timestamp > 60) {
            break;
        }
        steps += tracker->log[i].steps;
    }
    return steps;
}

// Get the number of steps taken in the last hour.
int get_steps_in_last_hour(fitness_tracker* tracker) {
    int steps = 0;
    time_t now = time(NULL);
    for (int i = tracker->log_index - 1; i >= 0; i--) {
        if (now - tracker->log[i].timestamp > 3600) {
            break;
        }
        steps += tracker->log[i].steps;
    }
    return steps;
}

// Get the number of steps taken in the last day.
int get_steps_in_last_day(fitness_tracker* tracker) {
    int steps = 0;
    time_t now = time(NULL);
    for (int i = tracker->log_index - 1; i >= 0; i--) {
        if (now - tracker->log[i].timestamp > 86400) {
            break;
        }
        steps += tracker->log[i].steps;
    }
    return steps;
}

// Print the fitness tracker data to the console.
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Step Count: %d\n", tracker->step_count);
    printf("Step Log:\n");
    for (int i = 0; i < tracker->log_index; i++) {
        printf("%ld: %d steps\n", tracker->log[i].timestamp, tracker->log[i].steps);
    }
}

// Free the memory allocated for the fitness tracker.
void free_fitness_tracker(fitness_tracker* tracker) {
    free(tracker);
}

int main() {
    // Create a fitness tracker.
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some steps to the fitness tracker.
    for (int i = 0; i < 100; i++) {
        add_step(tracker);
    }

    // Print the fitness tracker data to the console.
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker.
    free_fitness_tracker(tracker);

    return 0;
}