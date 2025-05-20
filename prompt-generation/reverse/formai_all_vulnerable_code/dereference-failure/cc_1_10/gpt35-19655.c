//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    int steps;
} FitnessData;

FitnessData newFitnessData(int steps) {
    FitnessData fitnessData;
    fitnessData.timestamp = time(NULL);
    fitnessData.steps = steps;
    return fitnessData;
}

typedef struct {
    FitnessData* data;
    int size;
    int capacity;
} FitnessTracker;

void initFitnessTracker(FitnessTracker* tracker) {
    tracker->size = 0;
    tracker->capacity = 10;
    tracker->data = (FitnessData*)malloc(sizeof(FitnessData)*tracker->capacity);
}

void resize(FitnessTracker* tracker) {
    tracker->capacity *= 2;
    tracker->data = (FitnessData*)realloc(tracker->data, sizeof(FitnessData)*tracker->capacity);
}

void addFitnessData(FitnessTracker* tracker, int steps) {
    if (tracker->size == tracker->capacity) {
        resize(tracker);
    }
    tracker->data[tracker->size] = newFitnessData(steps);
    tracker->size++;
}

void printFitnessData(FitnessData fitnessData) {
    char timestamp[30];
    strftime(timestamp, 30, "%Y-%m-%d %H:%M:%S", localtime(&(fitnessData.timestamp)));
    printf("%s: %d steps\n", timestamp, fitnessData.steps);
}

void printFitnessTracker(FitnessTracker tracker) {
    printf("Fitness Tracker:\n");
    for (int i=0; i<tracker.size; i++) {
        printFitnessData(tracker.data[i]);
    }
}

bool isOnTrack(FitnessTracker tracker, int goal) {
    int totalSteps = 0;
    for (int i=0; i<tracker.size; i++) {
        totalSteps += tracker.data[i].steps;
    }
    return totalSteps >= goal;
}

int main() {
    FitnessTracker tracker;
    initFitnessTracker(&tracker);
    
    int goal = 1000;
    int steps;
    while (true) {
        printf("Enter steps: ");
        scanf("%d", &steps);
        addFitnessData(&tracker, steps);
        printFitnessTracker(tracker);
        if (isOnTrack(tracker, goal)) {
            printf("Congratulations, you have reached your goal of %d steps!\n", goal);
            break;
        }
    }
    
    free(tracker.data);
}