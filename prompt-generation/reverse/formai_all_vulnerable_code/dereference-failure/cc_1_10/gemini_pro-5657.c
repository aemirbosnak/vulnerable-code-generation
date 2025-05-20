//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker
#define MAX_STEPS 1000

// Define the structure of a fitness tracker entry
typedef struct {
    time_t timestamp;
    int steps;
} fitness_tracker_entry;

// Define the fitness tracker data structure
typedef struct {
    fitness_tracker_entry entries[MAX_STEPS];
    int num_entries;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->num_entries = 0;
    return tracker;
}

// Add a new entry to the fitness tracker
void add_entry(fitness_tracker* tracker, time_t timestamp, int steps) {
    // Check if the tracker is full
    if (tracker->num_entries == MAX_STEPS) {
        printf("Error: fitness tracker is full\n");
        return;
    }

    // Add the new entry to the tracker
    tracker->entries[tracker->num_entries].timestamp = timestamp;
    tracker->entries[tracker->num_entries].steps = steps;
    tracker->num_entries++;
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker* tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        printf("%s: %d steps\n", ctime(&tracker->entries[i].timestamp), tracker->entries[i].steps);
    }
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some entries to the fitness tracker
    add_entry(tracker, time(NULL), 1000);
    add_entry(tracker, time(NULL) + 3600, 2000);
    add_entry(tracker, time(NULL) + 7200, 3000);

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}