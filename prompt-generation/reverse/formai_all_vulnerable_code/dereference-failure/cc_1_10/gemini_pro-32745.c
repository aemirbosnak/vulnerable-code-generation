//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker.
#define MAX_STEPS 1000

// Define the maximum number of calories that can be stored in the tracker.
#define MAX_CALORIES 1000

// Define the maximum number of minutes that can be stored in the tracker.
#define MAX_MINUTES 1000

// Define the structure of a fitness tracker entry.
typedef struct {
    time_t timestamp;
    uint32_t steps;
    uint32_t calories;
    uint32_t minutes;
} fitness_tracker_entry;

// Define the structure of a fitness tracker.
typedef struct {
    fitness_tracker_entry entries[MAX_STEPS];
    uint32_t num_entries;
} fitness_tracker;

// Create a new fitness tracker.
fitness_tracker* fitness_tracker_new() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    if (tracker == NULL) {
        return NULL;
    }

    tracker->num_entries = 0;

    return tracker;
}

// Add a new entry to the fitness tracker.
void fitness_tracker_add_entry(fitness_tracker* tracker, time_t timestamp, uint32_t steps, uint32_t calories, uint32_t minutes) {
    if (tracker->num_entries >= MAX_STEPS) {
        return;
    }

    tracker->entries[tracker->num_entries].timestamp = timestamp;
    tracker->entries[tracker->num_entries].steps = steps;
    tracker->entries[tracker->num_entries].calories = calories;
    tracker->entries[tracker->num_entries].minutes = minutes;

    tracker->num_entries++;
}

// Get the total number of steps in the fitness tracker.
uint32_t fitness_tracker_get_total_steps(fitness_tracker* tracker) {
    uint32_t total_steps = 0;
    for (uint32_t i = 0; i < tracker->num_entries; i++) {
        total_steps += tracker->entries[i].steps;
    }

    return total_steps;
}

// Get the total number of calories in the fitness tracker.
uint32_t fitness_tracker_get_total_calories(fitness_tracker* tracker) {
    uint32_t total_calories = 0;
    for (uint32_t i = 0; i < tracker->num_entries; i++) {
        total_calories += tracker->entries[i].calories;
    }

    return total_calories;
}

// Get the total number of minutes in the fitness tracker.
uint32_t fitness_tracker_get_total_minutes(fitness_tracker* tracker) {
    uint32_t total_minutes = 0;
    for (uint32_t i = 0; i < tracker->num_entries; i++) {
        total_minutes += tracker->entries[i].minutes;
    }

    return total_minutes;
}

// Print the fitness tracker to the console.
void fitness_tracker_print(fitness_tracker* tracker) {
    for (uint32_t i = 0; i < tracker->num_entries; i++) {
        printf("Timestamp: %s\n", ctime(&tracker->entries[i].timestamp));
        printf("Steps: %d\n", tracker->entries[i].steps);
        printf("Calories: %d\n", tracker->entries[i].calories);
        printf("Minutes: %d\n", tracker->entries[i].minutes);
        printf("\n");
    }
}

// Free the memory used by the fitness tracker.
void fitness_tracker_free(fitness_tracker* tracker) {
    free(tracker);
}

// Main function.
int main() {
    // Create a new fitness tracker.
    fitness_tracker* tracker = fitness_tracker_new();

    // Add some entries to the fitness tracker.
    fitness_tracker_add_entry(tracker, time(NULL), 1000, 200, 30);
    fitness_tracker_add_entry(tracker, time(NULL), 2000, 300, 40);
    fitness_tracker_add_entry(tracker, time(NULL), 3000, 400, 50);

    // Print the fitness tracker to the console.
    fitness_tracker_print(tracker);

    // Get the total number of steps in the fitness tracker.
    uint32_t total_steps = fitness_tracker_get_total_steps(tracker);

    // Get the total number of calories in the fitness tracker.
    uint32_t total_calories = fitness_tracker_get_total_calories(tracker);

    // Get the total number of minutes in the fitness tracker.
    uint32_t total_minutes = fitness_tracker_get_total_minutes(tracker);

    // Print the total number of steps, calories, and minutes to the console.
    printf("Total steps: %d\n", total_steps);
    printf("Total calories: %d\n", total_calories);
    printf("Total minutes: %d\n", total_minutes);

    // Free the memory used by the fitness tracker.
    fitness_tracker_free(tracker);

    return 0;
}