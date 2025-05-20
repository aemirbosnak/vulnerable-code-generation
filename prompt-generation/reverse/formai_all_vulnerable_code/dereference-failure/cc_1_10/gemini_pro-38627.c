//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of activities that can be tracked.
#define MAX_ACTIVITIES 10

// Define the structure of an activity.
typedef struct {
    char name[32];
    int duration;
    int calories_burned;
} activity_t;

// Define the structure of the fitness tracker.
typedef struct {
    activity_t activities[MAX_ACTIVITIES];
    int num_activities;
} fitness_tracker_t;

// Create a new fitness tracker.
fitness_tracker_t *create_fitness_tracker() {
    fitness_tracker_t *tracker = (fitness_tracker_t *)malloc(sizeof(fitness_tracker_t));
    tracker->num_activities = 0;
    return tracker;
}

// Add an activity to the fitness tracker.
void add_activity(fitness_tracker_t *tracker, activity_t activity) {
    if (tracker->num_activities < MAX_ACTIVITIES) {
        tracker->activities[tracker->num_activities] = activity;
        tracker->num_activities++;
    }
}

// Print the activities in the fitness tracker.
void print_activities(fitness_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_activities; i++) {
        printf("%s: %d minutes, %d calories burned\n", tracker->activities[i].name, tracker->activities[i].duration, tracker->activities[i].calories_burned);
    }
}

// Get the total duration of all activities in the fitness tracker.
int get_total_duration(fitness_tracker_t *tracker) {
    int total_duration = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        total_duration += tracker->activities[i].duration;
    }
    return total_duration;
}

// Get the total calories burned from all activities in the fitness tracker.
int get_total_calories_burned(fitness_tracker_t *tracker) {
    int total_calories_burned = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        total_calories_burned += tracker->activities[i].calories_burned;
    }
    return total_calories_burned;
}

// Main function.
int main() {
    // Create a fitness tracker.
    fitness_tracker_t *tracker = create_fitness_tracker();

    // Add some activities to the fitness tracker.
    activity_t activity1 = {"Running", 30, 200};
    add_activity(tracker, activity1);
    activity_t activity2 = {"Cycling", 45, 300};
    add_activity(tracker, activity2);
    activity_t activity3 = {"Swimming", 60, 400};
    add_activity(tracker, activity3);

    // Print the activities in the fitness tracker.
    print_activities(tracker);

    // Get the total duration of all activities in the fitness tracker.
    int total_duration = get_total_duration(tracker);
    printf("Total duration: %d minutes\n", total_duration);

    // Get the total calories burned from all activities in the fitness tracker.
    int total_calories_burned = get_total_calories_burned(tracker);
    printf("Total calories burned: %d\n", total_calories_burned);

    // Free the memory allocated for the fitness tracker.
    free(tracker);

    return 0;
}