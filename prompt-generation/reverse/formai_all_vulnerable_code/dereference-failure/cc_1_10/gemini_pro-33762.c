//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure of an activity
typedef struct {
    char* name;
    int duration;
    int intensity;
} Activity;

// Define the structure of a fitness tracker
typedef struct {
    Activity activities[MAX_ACTIVITIES];
    int numActivities;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker* createFitnessTracker() {
    FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
    tracker->numActivities = 0;
    return tracker;
}

// Add an activity to a fitness tracker
void addActivity(FitnessTracker* tracker, Activity activity) {
    if (tracker->numActivities < MAX_ACTIVITIES) {
        tracker->activities[tracker->numActivities++] = activity;
    } else {
        printf("Error: Maximum number of activities reached.\n");
    }
}

// Print the activities in a fitness tracker
void printActivities(FitnessTracker* tracker) {
    for (int i = 0; i < tracker->numActivities; i++) {
        printf("Activity %d:\n", i + 1);
        printf("    Name: %s\n", tracker->activities[i].name);
        printf("    Duration: %d minutes\n", tracker->activities[i].duration);
        printf("    Intensity: %d\n", tracker->activities[i].intensity);
        printf("\n");
    }
}

// Calculate the total duration of all activities in a fitness tracker
int calculateTotalDuration(FitnessTracker* tracker) {
    int totalDuration = 0;
    for (int i = 0; i < tracker->numActivities; i++) {
        totalDuration += tracker->activities[i].duration;
    }
    return totalDuration;
}

// Calculate the average intensity of all activities in a fitness tracker
int calculateAverageIntensity(FitnessTracker* tracker) {
    int totalIntensity = 0;
    for (int i = 0; i < tracker->numActivities; i++) {
        totalIntensity += tracker->activities[i].intensity;
    }
    return totalIntensity / tracker->numActivities;
}

// Free the memory allocated for a fitness tracker
void freeFitnessTracker(FitnessTracker* tracker) {
    for (int i = 0; i < tracker->numActivities; i++) {
        free(tracker->activities[i].name);
    }
    free(tracker);
}

// Main function
int main() {
    // Create a fitness tracker
    FitnessTracker* tracker = createFitnessTracker();

    // Add some activities to the fitness tracker
    Activity activity1 = {"Running", 30, 7};
    addActivity(tracker, activity1);
    Activity activity2 = {"Cycling", 45, 8};
    addActivity(tracker, activity2);
    Activity activity3 = {"Swimming", 20, 9};
    addActivity(tracker, activity3);

    // Print the activities in the fitness tracker
    printActivities(tracker);

    // Calculate the total duration of all activities in the fitness tracker
    int totalDuration = calculateTotalDuration(tracker);
    printf("Total duration: %d minutes\n", totalDuration);

    // Calculate the average intensity of all activities in the fitness tracker
    int averageIntensity = calculateAverageIntensity(tracker);
    printf("Average intensity: %d\n", averageIntensity);

    // Free the memory allocated for the fitness tracker
    freeFitnessTracker(tracker);

    return 0;
}