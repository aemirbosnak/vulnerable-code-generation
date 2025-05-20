//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the maximum length of an activity name
#define MAX_ACTIVITY_NAME_LENGTH 20

// Define the structure of an activity
typedef struct activity {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int duration; // in minutes
    int calories_burned;
} activity_t;

// Define the structure of the fitness tracker
typedef struct fitness_tracker {
    activity_t activities[MAX_ACTIVITIES];
    int num_activities;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *create_fitness_tracker() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    if (tracker == NULL) {
        return NULL;
    }

    tracker->num_activities = 0;

    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker_t *tracker) {
    free(tracker);
}

// Add an activity to the fitness tracker
int add_activity(fitness_tracker_t *tracker, char *name, int duration, int calories_burned) {
    if (tracker->num_activities >= MAX_ACTIVITIES) {
        return -1; // Error: Maximum number of activities reached
    }

    strcpy(tracker->activities[tracker->num_activities].name, name);
    tracker->activities[tracker->num_activities].duration = duration;
    tracker->activities[tracker->num_activities].calories_burned = calories_burned;

    tracker->num_activities++;

    return 0;
}

// Get the total duration of all activities in the fitness tracker
int get_total_duration(fitness_tracker_t *tracker) {
    int total_duration = 0;

    for (int i = 0; i < tracker->num_activities; i++) {
        total_duration += tracker->activities[i].duration;
    }

    return total_duration;
}

// Get the total calories burned from all activities in the fitness tracker
int get_total_calories_burned(fitness_tracker_t *tracker) {
    int total_calories_burned = 0;

    for (int i = 0; i < tracker->num_activities; i++) {
        total_calories_burned += tracker->activities[i].calories_burned;
    }

    return total_calories_burned;
}

// Print the activities in the fitness tracker
void print_activities(fitness_tracker_t *tracker) {
    printf("Activities:\n");

    for (int i = 0; i < tracker->num_activities; i++) {
        printf(" - %s: %d minutes, %d calories burned\n", tracker->activities[i].name, tracker->activities[i].duration, tracker->activities[i].calories_burned);
    }
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker_t *tracker = create_fitness_tracker();

    // Add some activities to the fitness tracker
    add_activity(tracker, "Walking", 30, 200);
    add_activity(tracker, "Running", 20, 300);
    add_activity(tracker, "Cycling", 45, 400);

    // Print the activities in the fitness tracker
    print_activities(tracker);

    // Get the total duration of all activities
    int total_duration = get_total_duration(tracker);

    // Get the total calories burned from all activities
    int total_calories_burned = get_total_calories_burned(tracker);

    // Print the total duration and calories burned
    printf("Total duration: %d minutes\n", total_duration);
    printf("Total calories burned: %d\n", total_calories_burned);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}