//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure of an activity
typedef struct {
    char *name;
    int duration;
    int intensity;
} Activity;

// Define the structure of a fitness tracker
typedef struct {
    char *name;
    Activity activities[MAX_ACTIVITIES];
    int num_activities;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *create_fitness_tracker(char *name) {
    FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
    tracker->name = strdup(name);
    tracker->num_activities = 0;
    return tracker;
}

// Add an activity to a fitness tracker
void add_activity(FitnessTracker *tracker, Activity activity) {
    if (tracker->num_activities < MAX_ACTIVITIES) {
        tracker->activities[tracker->num_activities++] = activity;
    } else {
        printf("Error: cannot add more activities to fitness tracker\n");
    }
}

// Print the activities of a fitness tracker
void print_activities(FitnessTracker *tracker) {
    for (int i = 0; i < tracker->num_activities; i++) {
        Activity activity = tracker->activities[i];
        printf("%s: %d minutes, %d intensity\n", activity.name, activity.duration, activity.intensity);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(FitnessTracker *tracker) {
    for (int i = 0; i < tracker->num_activities; i++) {
        free(tracker->activities[i].name);
    }
    free(tracker->name);
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    FitnessTracker *tracker = create_fitness_tracker("My Fitness Tracker");

    // Add some activities to the fitness tracker
    Activity activity1 = {"Running", 30, 7};
    add_activity(tracker, activity1);
    Activity activity2 = {"Cycling", 45, 8};
    add_activity(tracker, activity2);
    Activity activity3 = {"Swimming", 60, 9};
    add_activity(tracker, activity3);

    // Print the activities of the fitness tracker
    print_activities(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}