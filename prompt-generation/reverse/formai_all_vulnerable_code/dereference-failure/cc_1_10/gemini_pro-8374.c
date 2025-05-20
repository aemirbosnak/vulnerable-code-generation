//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure of an activity
typedef struct activity {
    char *name;
    int duration;
    int calories_burned;
} activity;

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
    activity activities[MAX_ACTIVITIES];
    int num_activities;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->num_activities = 0;
    return tracker;
}

// Add an activity to a fitness tracker
void add_activity(fitness_tracker *tracker, activity *activity) {
    if (tracker->num_activities < MAX_ACTIVITIES) {
        tracker->activities[tracker->num_activities] = *activity;
        tracker->num_activities++;
    } else {
        printf("Error: Fitness tracker is full, cannot add more activities.\n");
    }
}

// Get the total duration of all activities in a fitness tracker
int get_total_duration(fitness_tracker *tracker) {
    int total_duration = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        total_duration += tracker->activities[i].duration;
    }
    return total_duration;
}

// Get the total calories burned by all activities in a fitness tracker
int get_total_calories_burned(fitness_tracker *tracker) {
    int total_calories_burned = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        total_calories_burned += tracker->activities[i].calories_burned;
    }
    return total_calories_burned;
}

// Print the details of all activities in a fitness tracker
void print_activities(fitness_tracker *tracker) {
    printf("Activities:\n");
    for (int i = 0; i < tracker->num_activities; i++) {
        printf("  %s: %d minutes, %d calories burned\n", tracker->activities[i].name, tracker->activities[i].duration, tracker->activities[i].calories_burned);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker *tracker) {
    for (int i = 0; i < tracker->num_activities; i++) {
        free(tracker->activities[i].name);
    }
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker *tracker = create_fitness_tracker();

    // Add some activities to the fitness tracker
    activity activity1 = {"Walking", 30, 150};
    add_activity(tracker, &activity1);
    activity activity2 = {"Running", 20, 200};
    add_activity(tracker, &activity2);
    activity activity3 = {"Cycling", 45, 250};
    add_activity(tracker, &activity3);

    // Print the details of all activities in the fitness tracker
    print_activities(tracker);

    // Get the total duration of all activities in the fitness tracker
    int total_duration = get_total_duration(tracker);
    printf("Total duration: %d minutes\n", total_duration);

    // Get the total calories burned by all activities in the fitness tracker
    int total_calories_burned = get_total_calories_burned(tracker);
    printf("Total calories burned: %d calories\n", total_calories_burned);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}