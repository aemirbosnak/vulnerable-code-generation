//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare our fitness tracker data structure
typedef struct {
    char *name;              // Name of the tracker
    int steps;               // Number of steps taken
    int caloriesBurned;       // Number of calories burned
    int distanceTraveled;    // Distance traveled in meters
    time_t startTime;        // Start time of the tracking session
    time_t endTime;          // End time of the tracking session
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *createFitnessTracker(char *name) {
    FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
    tracker->name = strdup(name);
    tracker->steps = 0;
    tracker->caloriesBurned = 0;
    tracker->distanceTraveled = 0;
    tracker->startTime = time(NULL);
    tracker->endTime = 0;
    return tracker;
}

// Destroy a fitness tracker
void destroyFitnessTracker(FitnessTracker *tracker) {
    free(tracker->name);
    free(tracker);
}

// Record a step taken
void recordStep(FitnessTracker *tracker) {
    tracker->steps++;
}

// Record calories burned
void recordCaloriesBurned(FitnessTracker *tracker, int calories) {
    tracker->caloriesBurned += calories;
}

// Record distance traveled
void recordDistanceTraveled(FitnessTracker *tracker, int distance) {
    tracker->distanceTraveled += distance;
}

// Start a tracking session
void startTrackingSession(FitnessTracker *tracker) {
    tracker->startTime = time(NULL);
}

// End a tracking session
void endTrackingSession(FitnessTracker *tracker) {
    tracker->endTime = time(NULL);
}

// Get the duration of a tracking session
int getTrackingSessionDuration(FitnessTracker *tracker) {
    return tracker->endTime - tracker->startTime;
}

// Get a summary of the tracking session
char *getTrackingSessionSummary(FitnessTracker *tracker) {
    char *summary = malloc(256);
    sprintf(summary, "Name: %s\nSteps: %d\nCalories Burned: %d\nDistance Traveled: %dm\nDuration: %ds\n", tracker->name, tracker->steps, tracker->caloriesBurned, tracker->distanceTraveled, getTrackingSessionDuration(tracker));
    return summary;
}

// Main function
int main() {
    // Create a new fitness tracker
    FitnessTracker *tracker = createFitnessTracker("My Fitness Tracker");

    // Record some steps, calories burned, and distance traveled
    recordStep(tracker);
    recordStep(tracker);
    recordStep(tracker);
    recordCaloriesBurned(tracker, 100);
    recordDistanceTraveled(tracker, 1000);

    // Start a tracking session
    startTrackingSession(tracker);

    // Do some fitness activities
    // ...

    // End the tracking session
    endTrackingSession(tracker);

    // Get a summary of the tracking session
    char *summary = getTrackingSessionSummary(tracker);

    // Print the summary
    printf("%s", summary);

    // Destroy the fitness tracker
    destroyFitnessTracker(tracker);

    return 0;
}