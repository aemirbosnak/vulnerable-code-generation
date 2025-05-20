//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the data structure for a fitness tracker entry
typedef struct fitness_tracker_entry {
    time_t timestamp;
    int steps;
    int heart_rate;
    int calories_burned;
} fitness_tracker_entry_t;

// Define the data structure for a fitness tracker
typedef struct fitness_tracker {
    fitness_tracker_entry_t *entries;
    int num_entries;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *create_fitness_tracker() {
    fitness_tracker_t *ft = malloc(sizeof(fitness_tracker_t));
    ft->entries = NULL;
    ft->num_entries = 0;
    return ft;
}

// Add an entry to a fitness tracker
void add_entry_to_fitness_tracker(fitness_tracker_t *ft, fitness_tracker_entry_t entry) {
    ft->entries = realloc(ft->entries, (ft->num_entries + 1) * sizeof(fitness_tracker_entry_t));
    ft->entries[ft->num_entries] = entry;
    ft->num_entries++;
}

// Print the entries of a fitness tracker
void print_fitness_tracker(fitness_tracker_t *ft) {
    for (int i = 0; i < ft->num_entries; i++) {
        fitness_tracker_entry_t entry = ft->entries[i];
        printf("Timestamp: %ld\n", entry.timestamp);
        printf("Steps: %d\n", entry.steps);
        printf("Heart rate: %d\n", entry.heart_rate);
        printf("Calories burned: %d\n\n", entry.calories_burned);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker_t *ft) {
    free(ft->entries);
    free(ft);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker_t *ft = create_fitness_tracker();

    // Add some entries to the fitness tracker
    time_t timestamp = time(NULL);
    fitness_tracker_entry_t entry1 = {timestamp, 10000, 70, 500};
    add_entry_to_fitness_tracker(ft, entry1);

    timestamp = time(NULL);
    fitness_tracker_entry_t entry2 = {timestamp, 12000, 75, 550};
    add_entry_to_fitness_tracker(ft, entry2);

    timestamp = time(NULL);
    fitness_tracker_entry_t entry3 = {timestamp, 15000, 80, 600};
    add_entry_to_fitness_tracker(ft, entry3);

    // Print the entries of the fitness tracker
    print_fitness_tracker(ft);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(ft);

    return 0;
}