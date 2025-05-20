//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fitness tracker structure
typedef struct fitness_tracker {
  int steps;
  int calories;
  int distance;
  time_t start_time;
  time_t end_time;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* fitness_tracker_new() {
  fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
  tracker->steps = 0;
  tracker->calories = 0;
  tracker->distance = 0;
  tracker->start_time = time(NULL);
  tracker->end_time = time(NULL);
  return tracker;
}

// Start the fitness tracker
void fitness_tracker_start(fitness_tracker* tracker) {
  tracker->start_time = time(NULL);
}

// Stop the fitness tracker
void fitness_tracker_stop(fitness_tracker* tracker) {
  tracker->end_time = time(NULL);
}

// Add steps to the fitness tracker
void fitness_tracker_add_steps(fitness_tracker* tracker, int steps) {
  tracker->steps += steps;
}

// Add calories to the fitness tracker
void fitness_tracker_add_calories(fitness_tracker* tracker, int calories) {
  tracker->calories += calories;
}

// Add distance to the fitness tracker
void fitness_tracker_add_distance(fitness_tracker* tracker, int distance) {
  tracker->distance += distance;
}

// Get the total steps from the fitness tracker
int fitness_tracker_get_steps(fitness_tracker* tracker) {
  return tracker->steps;
}

// Get the total calories from the fitness tracker
int fitness_tracker_get_calories(fitness_tracker* tracker) {
  return tracker->calories;
}

// Get the total distance from the fitness tracker
int fitness_tracker_get_distance(fitness_tracker* tracker) {
  return tracker->distance;
}

// Get the start time from the fitness tracker
time_t fitness_tracker_get_start_time(fitness_tracker* tracker) {
  return tracker->start_time;
}

// Get the end time from the fitness tracker
time_t fitness_tracker_get_end_time(fitness_tracker* tracker) {
  return tracker->end_time;
}

// Free the fitness tracker
void fitness_tracker_free(fitness_tracker* tracker) {
  free(tracker);
}

// Main function
int main() {
  // Create a new fitness tracker
  fitness_tracker* tracker = fitness_tracker_new();

  // Start the fitness tracker
  fitness_tracker_start(tracker);

  // Add some steps to the fitness tracker
  fitness_tracker_add_steps(tracker, 1000);

  // Add some calories to the fitness tracker
  fitness_tracker_add_calories(tracker, 200);

  // Add some distance to the fitness tracker
  fitness_tracker_add_distance(tracker, 5);

  // Stop the fitness tracker
  fitness_tracker_stop(tracker);

  // Get the total steps from the fitness tracker
  int steps = fitness_tracker_get_steps(tracker);

  // Get the total calories from the fitness tracker
  int calories = fitness_tracker_get_calories(tracker);

  // Get the total distance from the fitness tracker
  int distance = fitness_tracker_get_distance(tracker);

  // Get the start time from the fitness tracker
  time_t start_time = fitness_tracker_get_start_time(tracker);

  // Get the end time from the fitness tracker
  time_t end_time = fitness_tracker_get_end_time(tracker);

  // Print the fitness tracker data
  printf("Steps: %d\n", steps);
  printf("Calories: %d\n", calories);
  printf("Distance: %d\n", distance);
  printf("Start Time: %s\n", ctime(&start_time));
  printf("End Time: %s\n", ctime(&end_time));

  // Free the fitness tracker
  fitness_tracker_free(tracker);

  return 0;
}