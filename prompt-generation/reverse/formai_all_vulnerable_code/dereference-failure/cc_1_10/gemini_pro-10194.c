//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of steps and calories that can be recorded.
#define MAX_STEPS 10000
#define MAX_CALORIES 5000

// Define the structure of a fitness tracker entry.
typedef struct fitness_tracker_entry {
    int steps;
    int calories;
    char *date;
} fitness_tracker_entry;

// Define the structure of a fitness tracker.
typedef struct fitness_tracker {
    fitness_tracker_entry *entries;
    int num_entries;
} fitness_tracker;

// Create a new fitness tracker.
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->entries = malloc(MAX_STEPS * sizeof(fitness_tracker_entry));
    tracker->num_entries = 0;
    return tracker;
}

// Destroy a fitness tracker.
void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->entries);
    free(tracker);
}

// Add an entry to a fitness tracker.
void add_entry(fitness_tracker *tracker, int steps, int calories, char *date) {
    if (tracker->num_entries >= MAX_STEPS) {
        fprintf(stderr, "Error: Too many entries in fitness tracker.\n");
        return;
    }

    fitness_tracker_entry *entry = &tracker->entries[tracker->num_entries++];
    entry->steps = steps;
    entry->calories = calories;
    entry->date = malloc(strlen(date) + 1);
    strcpy(entry->date, date);
}

// Print the entries in a fitness tracker.
void print_entries(fitness_tracker *tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        fitness_tracker_entry *entry = &tracker->entries[i];
        printf("%s: %d steps, %d calories\n", entry->date, entry->steps, entry->calories);
    }
}

// Main function.
int main() {
    // Create a new fitness tracker.
    fitness_tracker *tracker = create_fitness_tracker();

    // Add some entries to the fitness tracker.
    add_entry(tracker, 1000, 200, "2023-03-08");
    add_entry(tracker, 2000, 300, "2023-03-09");
    add_entry(tracker, 3000, 400, "2023-03-10");

    // Print the entries in the fitness tracker.
    print_entries(tracker);

    // Destroy the fitness tracker.
    destroy_fitness_tracker(tracker);

    return 0;
}