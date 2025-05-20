//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the data structures for the fitness tracker
typedef struct {
    int steps;
    int distance;
    int calories;
    time_t time;
} FitnessData;

typedef struct {
    FitnessData *data;
    int size;
    int capacity;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *fitness_tracker_create() {
    FitnessTracker *tracker = (FitnessTracker *)malloc(sizeof(FitnessTracker));
    tracker->data = (FitnessData *)malloc(sizeof(FitnessData) * 100);
    tracker->size = 0;
    tracker->capacity = 100;
    return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(FitnessTracker *tracker) {
    free(tracker->data);
    free(tracker);
}

// Add a new data point to the fitness tracker
void fitness_tracker_add_data(FitnessTracker *tracker, FitnessData data) {
    if (tracker->size == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->data = (FitnessData *)realloc(tracker->data, sizeof(FitnessData) * tracker->capacity);
    }
    tracker->data[tracker->size++] = data;
}

// Get the total steps taken by the user
int fitness_tracker_get_total_steps(FitnessTracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->size; i++) {
        total_steps += tracker->data[i].steps;
    }
    return total_steps;
}

// Get the total distance traveled by the user
int fitness_tracker_get_total_distance(FitnessTracker *tracker) {
    int total_distance = 0;
    for (int i = 0; i < tracker->size; i++) {
        total_distance += tracker->data[i].distance;
    }
    return total_distance;
}

// Get the total calories burned by the user
int fitness_tracker_get_total_calories(FitnessTracker *tracker) {
    int total_calories = 0;
    for (int i = 0; i < tracker->size; i++) {
        total_calories += tracker->data[i].calories;
    }
    return total_calories;
}

// Get the average steps taken by the user per day
int fitness_tracker_get_average_steps_per_day(FitnessTracker *tracker) {
    double average_steps_per_day = (double)fitness_tracker_get_total_steps(tracker) / tracker->size;
    return (int)round(average_steps_per_day);
}

// Get the average distance traveled by the user per day
int fitness_tracker_get_average_distance_per_day(FitnessTracker *tracker) {
    double average_distance_per_day = (double)fitness_tracker_get_total_distance(tracker) / tracker->size;
    return (int)round(average_distance_per_day);
}

// Get the average calories burned by the user per day
int fitness_tracker_get_average_calories_per_day(FitnessTracker *tracker) {
    double average_calories_per_day = (double)fitness_tracker_get_total_calories(tracker) / tracker->size;
    return (int)round(average_calories_per_day);
}

// Print the fitness tracker data
void fitness_tracker_print_data(FitnessTracker *tracker) {
    for (int i = 0; i < tracker->size; i++) {
        printf("%d steps, %d distance, %d calories, %s\n",
               tracker->data[i].steps, tracker->data[i].distance, tracker->data[i].calories, ctime(&tracker->data[i].time));
    }
}

// Main function
int main() {
    // Create a new fitness tracker
    FitnessTracker *tracker = fitness_tracker_create();

    // Add some sample data to the fitness tracker
    FitnessData data1 = {1000, 1000, 100, time(NULL)};
    FitnessData data2 = {2000, 2000, 200, time(NULL)};
    FitnessData data3 = {3000, 3000, 300, time(NULL)};
    fitness_tracker_add_data(tracker, data1);
    fitness_tracker_add_data(tracker, data2);
    fitness_tracker_add_data(tracker, data3);

    // Print the fitness tracker data
    fitness_tracker_print_data(tracker);

    // Get the total steps taken by the user
    int total_steps = fitness_tracker_get_total_steps(tracker);

    // Get the total distance traveled by the user
    int total_distance = fitness_tracker_get_total_distance(tracker);

    // Get the total calories burned by the user
    int total_calories = fitness_tracker_get_total_calories(tracker);

    // Get the average steps taken by the user per day
    int average_steps_per_day = fitness_tracker_get_average_steps_per_day(tracker);

    // Get the average distance traveled by the user per day
    int average_distance_per_day = fitness_tracker_get_average_distance_per_day(tracker);

    // Get the average calories burned by the user per day
    int average_calories_per_day = fitness_tracker_get_average_calories_per_day(tracker);

    // Print the fitness tracker statistics
    printf("Total steps: %d\n", total_steps);
    printf("Total distance: %d\n", total_distance);
    printf("Total calories: %d\n", total_calories);
    printf("Average steps per day: %d\n", average_steps_per_day);
    printf("Average distance per day: %d\n", average_distance_per_day);
    printf("Average calories per day: %d\n", average_calories_per_day);

    // Destroy the fitness tracker
    fitness_tracker_destroy(tracker);

    return 0;
}