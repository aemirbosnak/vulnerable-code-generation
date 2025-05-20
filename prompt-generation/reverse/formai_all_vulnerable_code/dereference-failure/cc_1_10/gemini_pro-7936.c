//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a fitness tracker entry
typedef struct FitnessTrackerEntry {
    int steps;
    int distance;
    int calories;
    int heartRate;
    char* date;
} FitnessTrackerEntry;

// Create a new fitness tracker entry
FitnessTrackerEntry* createFitnessTrackerEntry(int steps, int distance, int calories, int heartRate, char* date) {
    FitnessTrackerEntry* entry = malloc(sizeof(FitnessTrackerEntry));
    entry->steps = steps;
    entry->distance = distance;
    entry->calories = calories;
    entry->heartRate = heartRate;
    entry->date = date;
    return entry;
}

// Print a fitness tracker entry
void printFitnessTrackerEntry(FitnessTrackerEntry* entry) {
    printf("Steps: %d\n", entry->steps);
    printf("Distance: %d km\n", entry->distance);
    printf("Calories: %d\n", entry->calories);
    printf("Heart rate: %d bpm\n", entry->heartRate);
    printf("Date: %s\n", entry->date);
}

// Create a new fitness tracker
FitnessTrackerEntry** createFitnessTracker(int numEntries) {
    FitnessTrackerEntry** tracker = malloc(sizeof(FitnessTrackerEntry*) * numEntries);
    for (int i = 0; i < numEntries; i++) {
        tracker[i] = NULL;
    }
    return tracker;
}

// Add a new entry to a fitness tracker
void addFitnessTrackerEntry(FitnessTrackerEntry** tracker, int index, FitnessTrackerEntry* entry) {
    tracker[index] = entry;
}

// Print a fitness tracker
void printFitnessTracker(FitnessTrackerEntry** tracker, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d:\n", i + 1);
        printFitnessTrackerEntry(tracker[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new fitness tracker with 3 entries
    FitnessTrackerEntry** tracker = createFitnessTracker(3);

    // Add some entries to the tracker
    addFitnessTrackerEntry(tracker, 0, createFitnessTrackerEntry(10000, 5, 500, 120, "2023-01-01"));
    addFitnessTrackerEntry(tracker, 1, createFitnessTrackerEntry(12000, 6, 600, 130, "2023-01-02"));
    addFitnessTrackerEntry(tracker, 2, createFitnessTrackerEntry(14000, 7, 700, 140, "2023-01-03"));

    // Print the fitness tracker
    printFitnessTracker(tracker, 3);

    // Free the memory allocated for the fitness tracker
    for (int i = 0; i < 3; i++) {
        free(tracker[i]);
    }
    free(tracker);

    return 0;
}