//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the fitness tracker
#define MAX_STEPS 1000

// Define the maximum number of activities that can be stored in the fitness tracker
#define MAX_ACTIVITIES 100

// Define the types of activities that can be tracked
typedef enum {
    WALKING,
    RUNNING,
    CYCLING,
    SWIMMING,
    OTHER
} activity_type;

// Define the structure of a step
typedef struct {
    int timestamp;
    int count;
} step;

// Define the structure of an activity
typedef struct {
    activity_type type;
    int start_timestamp;
    int end_timestamp;
    int distance;
    int duration;
    int calories_burned;
} activity;

// Define the structure of the fitness tracker
typedef struct {
    int num_steps;
    step steps[MAX_STEPS];
    int num_activities;
    activity activities[MAX_ACTIVITIES];
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = (fitness_tracker*)malloc(sizeof(fitness_tracker));
    tracker->num_steps = 0;
    tracker->num_activities = 0;
    return tracker;
}

// Add a step to the fitness tracker
void add_step(fitness_tracker* tracker, int timestamp, int count) {
    if (tracker->num_steps < MAX_STEPS) {
        tracker->steps[tracker->num_steps].timestamp = timestamp;
        tracker->steps[tracker->num_steps].count = count;
        tracker->num_steps++;
    }
}

// Add an activity to the fitness tracker
void add_activity(fitness_tracker* tracker, activity_type type, int start_timestamp, int end_timestamp, int distance, int duration, int calories_burned) {
    if (tracker->num_activities < MAX_ACTIVITIES) {
        tracker->activities[tracker->num_activities].type = type;
        tracker->activities[tracker->num_activities].start_timestamp = start_timestamp;
        tracker->activities[tracker->num_activities].end_timestamp = end_timestamp;
        tracker->activities[tracker->num_activities].distance = distance;
        tracker->activities[tracker->num_activities].duration = duration;
        tracker->activities[tracker->num_activities].calories_burned = calories_burned;
        tracker->num_activities++;
    }
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Steps: %d\n", tracker->num_steps);
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("  - %d: %d steps\n", tracker->steps[i].timestamp, tracker->steps[i].count);
    }

    printf("Activities: %d\n", tracker->num_activities);
    for (int i = 0; i < tracker->num_activities; i++) {
        printf("  - %d: %s, %d - %d, %d km, %d min, %d calories\n", i,
            tracker->activities[i].type == WALKING ? "Walking" :
            tracker->activities[i].type == RUNNING ? "Running" :
            tracker->activities[i].type == CYCLING ? "Cycling" :
            tracker->activities[i].type == SWIMMING ? "Swimming" : "Other",
            tracker->activities[i].start_timestamp, tracker->activities[i].end_timestamp,
            tracker->activities[i].distance, tracker->activities[i].duration, tracker->activities[i].calories_burned);
    }
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker();

    // Add some steps to the fitness tracker
    add_step(tracker, 1658038400, 1000);
    add_step(tracker, 1658042000, 1200);
    add_step(tracker, 1658045600, 1500);

    // Add some activities to the fitness tracker
    add_activity(tracker, WALKING, 1658038400, 1658042000, 2, 30, 100);
    add_activity(tracker, RUNNING, 1658042000, 1658045600, 4, 20, 150);
    add_activity(tracker, CYCLING, 1658045600, 1658050400, 10, 45, 200);

    // Print the fitness tracker data
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}