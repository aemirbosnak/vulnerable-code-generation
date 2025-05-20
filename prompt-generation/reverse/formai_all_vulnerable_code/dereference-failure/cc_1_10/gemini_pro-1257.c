//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct FitnessData {
    int steps;
    int calories;
    int distance;
    int heartRate;
    time_t timestamp;
};

struct FitnessTracker {
    struct FitnessData *data;
    int dataSize;
    int dataCapacity;
};

void initFitnessTracker(struct FitnessTracker *tracker) {
    tracker->dataSize = 0;
    tracker->dataCapacity = 10;
    tracker->data = malloc(tracker->dataCapacity * sizeof(struct FitnessData));
}

void destroyFitnessTracker(struct FitnessTracker *tracker) {
    free(tracker->data);
}

void addData(struct FitnessTracker *tracker, struct FitnessData data) {
    if (tracker->dataSize == tracker->dataCapacity) {
        tracker->dataCapacity *= 2;
        tracker->data = realloc(tracker->data, tracker->dataCapacity * sizeof(struct FitnessData));
    }

    tracker->data[tracker->dataSize++] = data;
}

void printData(struct FitnessTracker *tracker) {
    for (int i = 0; i < tracker->dataSize; i++) {
        struct FitnessData data = tracker->data[i];
        printf("Steps: %d\n", data.steps);
        printf("Calories: %d\n", data.calories);
        printf("Distance: %d\n", data.distance);
        printf("Heart Rate: %d\n", data.heartRate);
        printf("Timestamp: %s\n", ctime(&data.timestamp));
    }
}

int main() {
    struct FitnessTracker tracker;
    initFitnessTracker(&tracker);

    struct FitnessData data;
    data.steps = 10000;
    data.calories = 500;
    data.distance = 5;
    data.heartRate = 120;
    data.timestamp = time(NULL);
    addData(&tracker, data);

    data.steps = 12000;
    data.calories = 600;
    data.distance = 6;
    data.heartRate = 130;
    data.timestamp = time(NULL);
    addData(&tracker, data);

    printData(&tracker);
    destroyFitnessTracker(&tracker);

    return 0;
}