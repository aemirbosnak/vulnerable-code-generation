//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of activities and the maximum length of an activity name
#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME 20

// Define the structure of an activity
typedef struct activity {
    char name[MAX_ACTIVITY_NAME];
    int duration;
    int calories;
} activity_t;

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
    activity_t activities[MAX_ACTIVITIES];
    int num_activities;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *create_fitness_tracker() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    tracker->num_activities = 0;
    return tracker;
}

// Add an activity to a fitness tracker
void add_activity(fitness_tracker_t *tracker, char *name, int duration, int calories) {
    if (tracker->num_activities < MAX_ACTIVITIES) {
        strcpy(tracker->activities[tracker->num_activities].name, name);
        tracker->activities[tracker->num_activities].duration = duration;
        tracker->activities[tracker->num_activities].calories = calories;
        tracker->num_activities++;
    }
}

// Print the activities in a fitness tracker
void print_activities(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_activities; i++) {
        printf("%s: %d minutes, %d calories\n", tracker->activities[i].name, tracker->activities[i].duration, tracker->activities[i].calories);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker_t *tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker_t *tracker = create_fitness_tracker();

    // Add some activities to the fitness tracker
    add_activity(tracker, "Walking", 30, 150);
    add_activity(tracker, "Running", 20, 200);
    add_activity(tracker, "Cycling", 45, 300);

    // Print the activities in the fitness tracker
    print_activities(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}