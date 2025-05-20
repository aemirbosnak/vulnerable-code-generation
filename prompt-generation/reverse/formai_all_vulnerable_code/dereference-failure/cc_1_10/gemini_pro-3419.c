//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 100000

// Define the structure of a fitness tracker entry
typedef struct fitness_tracker_entry {
    int steps;
    int distance;
    int calories;
    int heart_rate;
    char timestamp[20];
} fitness_tracker_entry;

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
    fitness_tracker_entry entries[MAX_STEPS];
    int num_entries;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->num_entries = 0;
    return tracker;
}

// Add a new entry to the fitness tracker
void add_entry(fitness_tracker *tracker, int steps, int distance, int calories, int heart_rate, char *timestamp) {
    tracker->entries[tracker->num_entries].steps = steps;
    tracker->entries[tracker->num_entries].distance = distance;
    tracker->entries[tracker->num_entries].calories = calories;
    tracker->entries[tracker->num_entries].heart_rate = heart_rate;
    strcpy(tracker->entries[tracker->num_entries].timestamp, timestamp);
    tracker->num_entries++;
}

// Get the total number of steps recorded by the fitness tracker
int get_total_steps(fitness_tracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        total_steps += tracker->entries[i].steps;
    }
    return total_steps;
}

// Get the average heart rate recorded by the fitness tracker
int get_average_heart_rate(fitness_tracker *tracker) {
    int average_heart_rate = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        average_heart_rate += tracker->entries[i].heart_rate;
    }
    return average_heart_rate / tracker->num_entries;
}

// Print the fitness tracker data to the console
void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Fitness Tracker Data:\n");
    for (int i = 0; i < tracker->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Steps: %d\n", tracker->entries[i].steps);
        printf("Distance: %d\n", tracker->entries[i].distance);
        printf("Calories: %d\n", tracker->entries[i].calories);
        printf("Heart Rate: %d\n", tracker->entries[i].heart_rate);
        printf("Timestamp: %s\n", tracker->entries[i].timestamp);
        printf("\n");
    }
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker *tracker) {
    free(tracker);
}

int main() {
    // Create a new fitness tracker
    fitness_tracker *tracker = create_fitness_tracker();

    // Add some sample entries to the fitness tracker
    add_entry(tracker, 10000, 5000, 500, 120, "2023-01-01 00:00:00");
    add_entry(tracker, 15000, 7500, 750, 130, "2023-01-02 00:00:00");
    add_entry(tracker, 20000, 10000, 1000, 140, "2023-01-03 00:00:00");

    // Get the total number of steps recorded by the fitness tracker
    int total_steps = get_total_steps(tracker);

    // Get the average heart rate recorded by the fitness tracker
    int average_heart_rate = get_average_heart_rate(tracker);

    // Print the fitness tracker data to the console
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}