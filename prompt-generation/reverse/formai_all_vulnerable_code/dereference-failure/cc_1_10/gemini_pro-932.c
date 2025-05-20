//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _FitnessTracker {
    char *name;
    int stepsTaken;
    int caloriesBurned;
    int distanceTraveled;
    int activeMinutes;
    int sleepDuration;
} FitnessTracker;

FitnessTracker *createFitnessTracker(char *name) {
    FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
    tracker->name = strdup(name);
    tracker->stepsTaken = 0;
    tracker->caloriesBurned = 0;
    tracker->distanceTraveled = 0;
    tracker->activeMinutes = 0;
    tracker->sleepDuration = 0;
    return tracker;
}

void destroyFitnessTracker(FitnessTracker *tracker) {
    free(tracker->name);
    free(tracker);
}

void logStepsTaken(FitnessTracker *tracker, int steps) {
    tracker->stepsTaken += steps;
}

void logCaloriesBurned(FitnessTracker *tracker, int calories) {
    tracker->caloriesBurned += calories;
}

void logDistanceTraveled(FitnessTracker *tracker, int distance) {
    tracker->distanceTraveled += distance;
}

void logActiveMinutes(FitnessTracker *tracker, int minutes) {
    tracker->activeMinutes += minutes;
}

void logSleepDuration(FitnessTracker *tracker, int duration) {
    tracker->sleepDuration += duration;
}

void printFitnessTrackerSummary(FitnessTracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Steps taken: %d\n", tracker->stepsTaken);
    printf("Calories burned: %d\n", tracker->caloriesBurned);
    printf("Distance traveled: %d\n", tracker->distanceTraveled);
    printf("Active minutes: %d\n", tracker->activeMinutes);
    printf("Sleep duration: %d\n", tracker->sleepDuration);
}

int main() {
    // Create a fitness tracker for John Doe
    FitnessTracker *tracker = createFitnessTracker("John Doe");

    // Log some activities
    logStepsTaken(tracker, 10000);
    logCaloriesBurned(tracker, 500);
    logDistanceTraveled(tracker, 5);
    logActiveMinutes(tracker, 60);
    logSleepDuration(tracker, 8);

    // Print a summary of the fitness tracker data
    printFitnessTrackerSummary(tracker);

    // Destroy the fitness tracker
    destroyFitnessTracker(tracker);

    return 0;
}