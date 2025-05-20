//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a fitness tracker entry
typedef struct {
    int steps;
    int caloriesBurned;
    int heartRate;
    char *activityType;
} FitnessTrackerEntry;

// Create a new fitness tracker entry
FitnessTrackerEntry *createFitnessTrackerEntry(int steps, int caloriesBurned, int heartRate, char *activityType) {
    FitnessTrackerEntry *entry = malloc(sizeof(FitnessTrackerEntry));
    entry->steps = steps;
    entry->caloriesBurned = caloriesBurned;
    entry->heartRate = heartRate;
    entry->activityType = activityType;
    return entry;
}

// Print a fitness tracker entry
void printFitnessTrackerEntry(FitnessTrackerEntry *entry) {
    printf("Steps: %d\n", entry->steps);
    printf("Calories burned: %d\n", entry->caloriesBurned);
    printf("Heart rate: %d\n", entry->heartRate);
    printf("Activity type: %s\n", entry->activityType);
}

// Create a fitness tracker log
FitnessTrackerEntry **createFitnessTrackerLog(int numEntries) {
    FitnessTrackerEntry **log = malloc(sizeof(FitnessTrackerEntry *) * numEntries);
    for (int i = 0; i < numEntries; i++) {
        log[i] = createFitnessTrackerEntry(0, 0, 0, "Unknown");
    }
    return log;
}

// Add an entry to a fitness tracker log
void addEntryToFitnessTrackerLog(FitnessTrackerEntry **log, int numEntries, FitnessTrackerEntry *entry) {
    log[numEntries - 1] = entry;
}

// Print a fitness tracker log
void printFitnessTrackerLog(FitnessTrackerEntry **log, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printFitnessTrackerEntry(log[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a fitness tracker log with 7 entries
    FitnessTrackerEntry **log = createFitnessTrackerLog(7);

    // Add some entries to the log
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(10000, 500, 120, "Walking"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(15000, 750, 140, "Running"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(20000, 1000, 160, "Cycling"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(25000, 1250, 180, "Swimming"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(30000, 1500, 200, "Hiking"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(35000, 1750, 220, "Weightlifting"));
    addEntryToFitnessTrackerLog(log, 7, createFitnessTrackerEntry(40000, 2000, 240, "Other"));

    // Print the fitness tracker log
    printFitnessTrackerLog(log, 7);

    // Free the allocated memory
    for (int i = 0; i < 7; i++) {
        free(log[i]);
    }
    free(log);

    return 0;
}