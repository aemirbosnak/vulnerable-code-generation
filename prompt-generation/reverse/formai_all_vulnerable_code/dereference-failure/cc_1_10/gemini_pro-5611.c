//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps and activities that can be stored in the tracker
#define MAX_STEPS 1000
#define MAX_ACTIVITIES 100

// Define the structure of a step
typedef struct step {
    int timestamp;
    int count;
} step;

// Define the structure of an activity
typedef struct activity {
    int start_time;
    int end_time;
    char *name;
} activity;

// Create an instance of the fitness tracker
struct fitness_tracker {
    int num_steps;
    step *steps;
    int num_activities;
    activity *activities;
};

// Create a new fitness tracker
struct fitness_tracker *new_fitness_tracker() {
    struct fitness_tracker *tracker = malloc(sizeof(struct fitness_tracker));
    tracker->num_steps = 0;
    tracker->steps = malloc(MAX_STEPS * sizeof(step));
    tracker->num_activities = 0;
    tracker->activities = malloc(MAX_ACTIVITIES * sizeof(activity));
    return tracker;
}

// Add a new step to the tracker
void add_step(struct fitness_tracker *tracker, int timestamp, int count) {
    tracker->steps[tracker->num_steps].timestamp = timestamp;
    tracker->steps[tracker->num_steps].count = count;
    tracker->num_steps++;
}

// Add a new activity to the tracker
void add_activity(struct fitness_tracker *tracker, int start_time, int end_time, char *name) {
    tracker->activities[tracker->num_activities].start_time = start_time;
    tracker->activities[tracker->num_activities].end_time = end_time;
    tracker->activities[tracker->num_activities].name = name;
    tracker->num_activities++;
}

// Get the total number of steps taken by the user
int get_total_steps(struct fitness_tracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        total_steps += tracker->steps[i].count;
    }
    return total_steps;
}

// Get the total duration of all activities performed by the user
int get_total_activity_duration(struct fitness_tracker *tracker) {
    int total_duration = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        total_duration += tracker->activities[i].end_time - tracker->activities[i].start_time;
    }
    return total_duration;
}

// Get the average number of steps taken per hour
float get_average_steps_per_hour(struct fitness_tracker *tracker) {
    int total_steps = get_total_steps(tracker);
    int total_duration = get_total_activity_duration(tracker);
    float average_steps_per_hour = (float)total_steps / (total_duration / 3600);
    return average_steps_per_hour;
}

// Get the most popular activity performed by the user
char *get_most_popular_activity(struct fitness_tracker *tracker) {
    char *most_popular_activity = NULL;
    int max_count = 0;
    for (int i = 0; i < tracker->num_activities; i++) {
        int count = 0;
        for (int j = 0; j < tracker->num_activities; j++) {
            if (strcmp(tracker->activities[i].name, tracker->activities[j].name) == 0) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_popular_activity = tracker->activities[i].name;
        }
    }
    return most_popular_activity;
}

// Free the memory allocated to the fitness tracker
void free_fitness_tracker(struct fitness_tracker *tracker) {
    free(tracker->steps);
    for (int i = 0; i < tracker->num_activities; i++) {
        free(tracker->activities[i].name);
    }
    free(tracker->activities);
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    struct fitness_tracker *tracker = new_fitness_tracker();

    // Add some steps to the tracker
    add_step(tracker, 1649740800, 1000);
    add_step(tracker, 1649740860, 2000);
    add_step(tracker, 1649740920, 3000);

    // Add some activities to the tracker
    add_activity(tracker, 1649740980, 1649741040, "Walking");
    add_activity(tracker, 1649741100, 1649741160, "Running");
    add_activity(tracker, 1649741220, 1649741280, "Cycling");

    // Get the total number of steps taken by the user
    int total_steps = get_total_steps(tracker);
    printf("Total steps: %d\n", total_steps);

    // Get the total duration of all activities performed by the user
    int total_activity_duration = get_total_activity_duration(tracker);
    printf("Total activity duration: %d seconds\n", total_activity_duration);

    // Get the average number of steps taken per hour
    float average_steps_per_hour = get_average_steps_per_hour(tracker);
    printf("Average steps per hour: %.2f\n", average_steps_per_hour);

    // Get the most popular activity performed by the user
    char *most_popular_activity = get_most_popular_activity(tracker);
    printf("Most popular activity: %s\n", most_popular_activity);

    // Free the memory allocated to the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}