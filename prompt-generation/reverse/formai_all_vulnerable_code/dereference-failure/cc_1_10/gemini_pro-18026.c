//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a fitness tracker entry
typedef struct fitness_tracker_entry {
    time_t timestamp;
    int steps;
    int distance;
    int calories;
    int heart_rate;
} fitness_tracker_entry;

// Create a new fitness tracker entry
fitness_tracker_entry* create_fitness_tracker_entry(time_t timestamp, int steps, int distance, int calories, int heart_rate) {
    fitness_tracker_entry* entry = malloc(sizeof(fitness_tracker_entry));
    entry->timestamp = timestamp;
    entry->steps = steps;
    entry->distance = distance;
    entry->calories = calories;
    entry->heart_rate = heart_rate;
    return entry;
}

// Print a fitness tracker entry
void print_fitness_tracker_entry(fitness_tracker_entry* entry) {
    printf("Timestamp: %s", ctime(&entry->timestamp));
    printf("Steps: %d\n", entry->steps);
    printf("Distance: %d\n", entry->distance);
    printf("Calories: %d\n", entry->calories);
    printf("Heart rate: %d\n", entry->heart_rate);
}

// Create a new fitness tracker
typedef struct fitness_tracker {
    int num_entries;
    fitness_tracker_entry** entries;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->num_entries = 0;
    tracker->entries = NULL;
    return tracker;
}

// Add an entry to a fitness tracker
void add_entry_to_fitness_tracker(fitness_tracker* tracker, fitness_tracker_entry* entry) {
    tracker->num_entries++;
    tracker->entries = realloc(tracker->entries, sizeof(fitness_tracker_entry*) * tracker->num_entries);
    tracker->entries[tracker->num_entries - 1] = entry;
}

// Print a fitness tracker
void print_fitness_tracker(fitness_tracker* tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        print_fitness_tracker_entry(tracker->entries[i]);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker* tracker) {
    for (int i = 0; i < tracker->num_entries; i++) {
        free(tracker->entries[i]);
    }
    free(tracker->entries);
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some entries to the fitness tracker
    add_entry_to_fitness_tracker(tracker, create_fitness_tracker_entry(time(NULL), 10000, 5000, 500, 100));
    add_entry_to_fitness_tracker(tracker, create_fitness_tracker_entry(time(NULL), 12000, 6000, 600, 110));
    add_entry_to_fitness_tracker(tracker, create_fitness_tracker_entry(time(NULL), 15000, 7500, 750, 120));

    // Print the fitness tracker
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}