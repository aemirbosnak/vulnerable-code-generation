//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the fitness tracker
#define MAX_STEPS 10000

// Define the maximum number of activities that can be stored in the fitness tracker
#define MAX_ACTIVITIES 10

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
    int steps[MAX_STEPS];
    int num_steps;
    char activities[MAX_ACTIVITIES][50];
    int num_activities;
    time_t start_time;
    time_t end_time;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->num_steps = 0;
    tracker->num_activities = 0;
    tracker->start_time = time(NULL);
    tracker->end_time = time(NULL);
    return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker);
}

// Add a step to the fitness tracker
void add_step(fitness_tracker *tracker) {
    tracker->steps[tracker->num_steps] = 1;
    tracker->num_steps++;
}

// Add an activity to the fitness tracker
void add_activity(fitness_tracker *tracker, char *activity) {
    strcpy(tracker->activities[tracker->num_activities], activity);
    tracker->num_activities++;
}

// Set the start time of the fitness tracker
void set_start_time(fitness_tracker *tracker, time_t start_time) {
    tracker->start_time = start_time;
}

// Set the end time of the fitness tracker
void set_end_time(fitness_tracker *tracker, time_t end_time) {
    tracker->end_time = end_time;
}

// Get the total number of steps taken by the fitness tracker
int get_total_steps(fitness_tracker *tracker) {
    return tracker->num_steps;
}

// Get the total number of activities recorded by the fitness tracker
int get_total_activities(fitness_tracker *tracker) {
    return tracker->num_activities;
}

// Get the start time of the fitness tracker
time_t get_start_time(fitness_tracker *tracker) {
    return tracker->start_time;
}

// Get the end time of the fitness tracker
time_t get_end_time(fitness_tracker *tracker) {
    return tracker->end_time;
}

// Print the fitness tracker data to the console
void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Total steps: %d\n", tracker->num_steps);
    printf("Total activities: %d\n", tracker->num_activities);
    printf("Start time: %s", ctime(&tracker->start_time));
    printf("End time: %s", ctime(&tracker->end_time));
    for (int i = 0; i < tracker->num_activities; i++) {
        printf("Activity %d: %s\n", i + 1, tracker->activities[i]);
    }
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker *tracker = create_fitness_tracker();

    // Add some steps to the fitness tracker
    for (int i = 0; i < 1000; i++) {
        add_step(tracker);
    }

    // Add some activities to the fitness tracker
    add_activity(tracker, "Walking");
    add_activity(tracker, "Running");
    add_activity(tracker, "Cycling");

    // Set the start and end times of the fitness tracker
    set_start_time(tracker, time(NULL) - 3600);
    set_end_time(tracker, time(NULL));

    // Print the fitness tracker data to the console
    print_fitness_tracker(tracker);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}