//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    char *name;
    int steps;
    int calories;
    time_t timestamp;
} Activity;

Activity *createActivity(char *name, int steps, int calories, time_t timestamp) {
    Activity *activity = malloc(sizeof(Activity));
    activity->name = strdup(name);
    activity->steps = steps;
    activity->calories = calories;
    activity->timestamp = timestamp;
    return activity;
}

void destroyActivity(Activity *activity) {
    free(activity->name);
    free(activity);
}

int main() {
    // Create an array of activities
    Activity *activities[] = {
        createActivity("Walking", 1000, 100, time(NULL)),
        createActivity("Running", 2000, 200, time(NULL)),
        createActivity("Cycling", 3000, 300, time(NULL)),
        createActivity("Swimming", 4000, 400, time(NULL)),
        createActivity("Sleeping", 5000, 500, time(NULL)),
    };

    // Print the activities
    for (int i = 0; i < 5; i++) {
        printf("%s: %d steps, %d calories, %s\n", activities[i]->name, activities[i]->steps, activities[i]->calories, ctime(&activities[i]->timestamp));
    }

    // Destroy the activities
    for (int i = 0; i < 5; i++) {
        destroyActivity(activities[i]);
    }

    return 0;
}