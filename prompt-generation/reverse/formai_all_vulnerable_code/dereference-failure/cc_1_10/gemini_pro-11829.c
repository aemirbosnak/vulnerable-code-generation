//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct FitnessTracker {
    int steps;
    int caloriesBurned;
    int distanceTravelled;
    time_t lastUpdated;
} FitnessTracker;

FitnessTracker* createFitnessTracker() {
    FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->steps = 0;
    tracker->caloriesBurned = 0;
    tracker->distanceTravelled = 0;
    tracker->lastUpdated = time(NULL);
    return tracker;
}

void destroyFitnessTracker(FitnessTracker* tracker) {
    free(tracker);
}

bool updateFitnessTracker(FitnessTracker* tracker, int steps, int caloriesBurned, int distanceTravelled) {
    if (steps < 0 || caloriesBurned < 0 || distanceTravelled < 0) {
        return false;
    }
    tracker->steps += steps;
    tracker->caloriesBurned += caloriesBurned;
    tracker->distanceTravelled += distanceTravelled;
    tracker->lastUpdated = time(NULL);
    return true;
}

void printFitnessTracker(FitnessTracker* tracker) {
    printf("Steps: %d\n", tracker->steps);
    printf("Calories Burned: %d\n", tracker->caloriesBurned);
    printf("Distance Travelled: %d\n", tracker->distanceTravelled);
    printf("Last Updated: %s\n", ctime(&tracker->lastUpdated));
}

int main() {
    FitnessTracker* tracker = createFitnessTracker();
    updateFitnessTracker(tracker, 1000, 500, 5);
    updateFitnessTracker(tracker, 2000, 1000, 10);
    printFitnessTracker(tracker);
    destroyFitnessTracker(tracker);
    return 0;
}