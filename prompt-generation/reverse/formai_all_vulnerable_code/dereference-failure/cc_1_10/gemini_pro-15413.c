//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int steps;
    int calories;
    int distance;
    time_t timestamp;
} ActivityLog;

typedef struct {
    char name[32];
    int age;
    int weight;
    int height;
    char gender;
} Profile;

typedef struct {
    Profile profile;
    ActivityLog *log;
    int logSize;
} FitnessTracker;

ActivityLog* createActivityLog(int steps, int calories, int distance) {
    ActivityLog *log = malloc(sizeof(ActivityLog));
    log->steps = steps;
    log->calories = calories;
    log->distance = distance;
    log->timestamp = time(NULL);
    return log;
}

void addActivityLog(FitnessTracker *tracker, ActivityLog *log) {
    tracker->log = realloc(tracker->log, (tracker->logSize + 1) * sizeof(ActivityLog));
    tracker->log[tracker->logSize++] = *log;
}

void printActivityLog(ActivityLog *log) {
    printf("Steps: %d\n", log->steps);
    printf("Calories: %d\n", log->calories);
    printf("Distance: %d\n", log->distance);
    printf("Timestamp: %s\n", ctime(&log->timestamp));
}

void printFitnessTracker(FitnessTracker *tracker) {
    printf("Name: %s\n", tracker->profile.name);
    printf("Age: %d\n", tracker->profile.age);
    printf("Weight: %d\n", tracker->profile.weight);
    printf("Height: %d\n", tracker->profile.height);
    printf("Gender: %c\n", tracker->profile.gender);
    printf("Activity Log:\n");
    for (int i = 0; i < tracker->logSize; i++) {
        printActivityLog(&tracker->log[i]);
    }
}

int main() {
    FitnessTracker tracker;
    strcpy(tracker.profile.name, "John Doe");
    tracker.profile.age = 30;
    tracker.profile.weight = 80;
    tracker.profile.height = 180;
    tracker.profile.gender = 'M';
    tracker.logSize = 0;
    tracker.log = NULL;

    addActivityLog(&tracker, createActivityLog(10000, 500, 5));
    addActivityLog(&tracker, createActivityLog(15000, 600, 6));
    addActivityLog(&tracker, createActivityLog(20000, 700, 7));

    printFitnessTracker(&tracker);

    return 0;
}