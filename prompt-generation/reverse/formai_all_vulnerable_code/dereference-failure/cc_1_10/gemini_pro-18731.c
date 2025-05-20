//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Activity {
    int startTime;
    int endTime;
    char *type;
};

struct FitnessTracker {
    int numActivities;
    struct Activity *activities;
};

struct FitnessTracker *createFitnessTracker() {
    struct FitnessTracker *tracker = malloc(sizeof(struct FitnessTracker));
    tracker->numActivities = 0;
    tracker->activities = NULL;
    return tracker;
}

void addActivity(struct FitnessTracker *tracker, int startTime, int endTime, char *type) {
    if (tracker->numActivities == 0) {
        tracker->activities = malloc(sizeof(struct Activity));
    } else {
        tracker->activities = realloc(tracker->activities, sizeof(struct Activity) * (tracker->numActivities + 1));
    }
    struct Activity *activity = &tracker->activities[tracker->numActivities];
    activity->startTime = startTime;
    activity->endTime = endTime;
    activity->type = strdup(type);
    tracker->numActivities++;
}

void printFitnessTracker(struct FitnessTracker *tracker) {
    for (int i = 0; i < tracker->numActivities; i++) {
        struct Activity *activity = &tracker->activities[i];
        printf("Activity %d: %s from %d to %d\n", i + 1, activity->type, activity->startTime, activity->endTime);
    }
}

void freeFitnessTracker(struct FitnessTracker *tracker) {
    for (int i = 0; i < tracker->numActivities; i++) {
        free(tracker->activities[i].type);
    }
    free(tracker->activities);
    free(tracker);
}

int main() {
    struct FitnessTracker *tracker = createFitnessTracker();
    addActivity(tracker, 600, 700, "Walking");
    addActivity(tracker, 800, 900, "Cycling");
    addActivity(tracker, 1000, 1100, "Swimming");
    printFitnessTracker(tracker);
    freeFitnessTracker(tracker);
    return 0;
}