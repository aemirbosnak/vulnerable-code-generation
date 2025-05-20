//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _FitnessTracker {
    int stepsTaken;
    float distanceTraveled;
    char mood;
    struct _FitnessTracker* next;
} FitnessTracker;

FitnessTracker* createFitnessTracker() {
    FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->stepsTaken = 0;
    tracker->distanceTraveled = 0.0f;
    tracker->mood = 'N';
    tracker->next = NULL;
    return tracker;
}

void addFitnessTracker(FitnessTracker* tracker, int stepsTaken, float distanceTraveled, char mood) {
    FitnessTracker* newTracker = createFitnessTracker();
    newTracker->stepsTaken = stepsTaken;
    newTracker->distanceTraveled = distanceTraveled;
    newTracker->mood = mood;

    if (tracker) {
        tracker->next = newTracker;
    } else {
        tracker = newTracker;
    }
}

void printFitnessTracker(FitnessTracker* tracker) {
    while (tracker) {
        printf("Steps taken: %d\n", tracker->stepsTaken);
        printf("Distance traveled: %.2f miles\n", tracker->distanceTraveled);
        printf("Mood: %c\n", tracker->mood);
        printf("\n");
        tracker = tracker->next;
    }
}

int main() {
    FitnessTracker* tracker = createFitnessTracker();
    addFitnessTracker(tracker, 1000, 2.5f, 'H');
    addFitnessTracker(tracker, 1200, 3.0f, 'A');
    addFitnessTracker(tracker, 1400, 3.5f, 'G');
    printFitnessTracker(tracker);

    return 0;
}