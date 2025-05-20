//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the fitness tracker
#define MAX_ENTRIES 100

// Define the structure of a fitness entry
typedef struct fitness_entry {
    char *activity;
    int duration;
    int calories;
} fitness_entry_t;

// Define the structure of the fitness tracker
typedef struct fitness_tracker {
    fitness_entry_t entries[MAX_ENTRIES];
    int num_entries;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *fitness_tracker_create() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    tracker->num_entries = 0;
    return tracker;
}

// Add an entry to the fitness tracker
void fitness_tracker_add_entry(fitness_tracker_t *tracker, char *activity, int duration, int calories) {
    if (tracker->num_entries >= MAX_ENTRIES) {
        return;
    }

    tracker->entries[tracker->num_entries].activity = strdup(activity);
    tracker->entries[tracker->num_entries].duration = duration;
    tracker->entries[tracker->num_entries].calories = calories;
    tracker->num_entries++;
}

// Print the entries in the fitness tracker
void fitness_tracker_print(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        printf("%s: %d minutes, %d calories\n", tracker->entries[i].activity, tracker->entries[i].duration, tracker->entries[i].calories);
    }
}

// Free the memory allocated by the fitness tracker
void fitness_tracker_free(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        free(tracker->entries[i].activity);
    }

    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker_t *tracker = fitness_tracker_create();

    // Add some entries to the fitness tracker
    fitness_tracker_add_entry(tracker, "Running", 30, 200);
    fitness_tracker_add_entry(tracker, "Swimming", 20, 150);
    fitness_tracker_add_entry(tracker, "Cycling", 45, 300);

    // Print the entries in the fitness tracker
    fitness_tracker_print(tracker);

    // Free the memory allocated by the fitness tracker
    fitness_tracker_free(tracker);

    return 0;
}