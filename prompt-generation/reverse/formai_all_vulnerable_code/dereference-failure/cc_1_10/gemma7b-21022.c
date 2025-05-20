//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEASURES 1024

typedef struct Measurement {
    int timestamp;
    float value;
    char unit;
} Measurement;

typedef struct FitnessTracker {
    Measurement measurements[MAX_MEASURES];
    int currentMeasureIndex;
    char name[255];
    float targetHeartRate;
} FitnessTracker;

void initializeFitnessTracker(FitnessTracker* tracker) {
    tracker->currentMeasureIndex = 0;
    tracker->name[0] = '\0';
    tracker->targetHeartRate = -1.0f;
}

void addMeasurement(FitnessTracker* tracker, int timestamp, float value, char unit) {
    if (tracker->currentMeasureIndex >= MAX_MEASURES) {
        return;
    }

    tracker->measurements[tracker->currentMeasureIndex].timestamp = timestamp;
    tracker->measurements[tracker->currentMeasureIndex].value = value;
    tracker->measurements[tracker->currentMeasureIndex].unit = unit;

    tracker->currentMeasureIndex++;
}

void printMeasurements(FitnessTracker* tracker) {
    for (int i = 0; i < tracker->currentMeasureIndex; i++) {
        printf("%d: %.2f %c\n", tracker->measurements[i].timestamp, tracker->measurements[i].value, tracker->measurements[i].unit);
    }
}

int main() {
    FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
    initializeFitnessTracker(tracker);

    addMeasurement(tracker, 1234, 76.5f, 'F');
    addMeasurement(tracker, 1235, 82.2f, 'H');
    addMeasurement(tracker, 1236, 78.1f, 'M');

    printMeasurements(tracker);

    free(tracker);

    return 0;
}