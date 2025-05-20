//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct FitnessData {
    time_t timestamp;
    int steps;
    int heartRate;
    double distance;
    double caloriesBurned;
};

struct FitnessTracker {
    struct FitnessData *data;
    int size;
    int capacity;
};

struct FitnessTracker *createFitnessTracker() {
    struct FitnessTracker *tracker = (struct FitnessTracker *)malloc(sizeof(struct FitnessTracker));
    tracker->data = (struct FitnessData *)malloc(sizeof(struct FitnessData) * 10);
    tracker->size = 0;
    tracker->capacity = 10;
    return tracker;
}

void destroyFitnessTracker(struct FitnessTracker *tracker) {
    free(tracker->data);
    free(tracker);
}

void addFitnessData(struct FitnessTracker *tracker, struct FitnessData data) {
    if (tracker->size == tracker->capacity) {
        tracker->data = (struct FitnessData *)realloc(tracker->data, sizeof(struct FitnessData) * (tracker->capacity * 2));
        tracker->capacity *= 2;
    }
    tracker->data[tracker->size++] = data;
}

int main() {
    struct FitnessTracker *tracker = createFitnessTracker();

    struct FitnessData data;
    data.timestamp = time(NULL);
    data.steps = 10000;
    data.heartRate = 70;
    data.distance = 5.0;
    data.caloriesBurned = 200.0;
    addFitnessData(tracker, data);

    data.timestamp = time(NULL);
    data.steps = 12000;
    data.heartRate = 75;
    data.distance = 6.0;
    data.caloriesBurned = 250.0;
    addFitnessData(tracker, data);

    data.timestamp = time(NULL);
    data.steps = 14000;
    data.heartRate = 80;
    data.distance = 7.0;
    data.caloriesBurned = 300.0;
    addFitnessData(tracker, data);

    for (int i = 0; i < tracker->size; i++) {
        struct FitnessData data = tracker->data[i];
        printf("Timestamp: %ld\n", data.timestamp);
        printf("Steps: %d\n", data.steps);
        printf("Heart Rate: %d\n", data.heartRate);
        printf("Distance: %lf\n", data.distance);
        printf("Calories Burned: %lf\n\n", data.caloriesBurned);
    }

    destroyFitnessTracker(tracker);

    return 0;
}