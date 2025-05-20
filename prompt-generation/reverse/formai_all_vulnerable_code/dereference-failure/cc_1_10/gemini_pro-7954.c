//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    double height;
    double weight;
    int steps;
    int calories;
    double distance;
    time_t start_time;
    time_t end_time;
} activity_t;

activity_t *create_activity(char *name) {
    activity_t *activity = malloc(sizeof(activity_t));
    if (activity == NULL) {
        return NULL;
    }

    activity->name = strdup(name);
    activity->age = 0;
    activity->height = 0.0;
    activity->weight = 0.0;
    activity->steps = 0;
    activity->calories = 0;
    activity->distance = 0.0;
    activity->start_time = time(NULL);
    activity->end_time = 0;

    return activity;
}

void destroy_activity(activity_t *activity) {
    if (activity == NULL) {
        return;
    }

    free(activity->name);
    free(activity);
}

int main() {
    // Create an activity with the name "Walking"
    activity_t *activity = create_activity("Walking");

    // Set the user's age, height, and weight
    activity->age = 30;
    activity->height = 1.75;
    activity->weight = 70.0;

    // Start the activity timer
    activity->start_time = time(NULL);

    // Walk for 30 minutes at a speed of 3 mph
    int duration = 30;
    int speed = 3;
    activity->steps = duration * speed * 120;
    activity->calories = duration * speed * 3.5;
    activity->distance = duration * speed;

    // Stop the activity timer
    activity->end_time = time(NULL);

    // Print the activity details
    printf("Activity: %s\n", activity->name);
    printf("Age: %d\n", activity->age);
    printf("Height: %f\n", activity->height);
    printf("Weight: %f\n", activity->weight);
    printf("Steps: %d\n", activity->steps);
    printf("Calories: %d\n", activity->calories);
    printf("Distance: %f\n", activity->distance);
    printf("Duration: %d\n", activity->end_time - activity->start_time);

    // Destroy the activity
    destroy_activity(activity);

    return 0;
}