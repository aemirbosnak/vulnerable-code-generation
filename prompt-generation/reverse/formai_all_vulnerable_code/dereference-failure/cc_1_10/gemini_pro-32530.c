//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker
#define MAX_STEPS 1000

// Define the structure of a fitness tracker
typedef struct FitnessTracker {
  uint32_t steps[MAX_STEPS];
  uint32_t num_steps;
  time_t start_time;
  time_t end_time;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker* new_fitness_tracker() {
  FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
  tracker->num_steps = 0;
  tracker->start_time = time(NULL);
  tracker->end_time = time(NULL);
  return tracker;
}

// Add a step to the fitness tracker
void add_step(FitnessTracker* tracker) {
  if (tracker->num_steps < MAX_STEPS) {
    tracker->steps[tracker->num_steps++] = time(NULL);
  }
}

// Get the number of steps in the fitness tracker
uint32_t get_num_steps(FitnessTracker* tracker) {
  return tracker->num_steps;
}

// Get the total duration of the fitness tracker in seconds
uint32_t get_duration(FitnessTracker* tracker) {
  return tracker->end_time - tracker->start_time;
}

// Get the average number of steps per minute
float get_avg_steps_per_minute(FitnessTracker* tracker) {
  return (float)tracker->num_steps / get_duration(tracker) * 60;
}

// Get the maximum number of steps in a single minute
uint32_t get_max_steps_per_minute(FitnessTracker* tracker) {
  uint32_t max_steps = 0;
  for (uint32_t i = 0; i < tracker->num_steps; i++) {
    uint32_t steps_in_minute = 0;
    for (uint32_t j = i; j < tracker->num_steps; j++) {
      if (tracker->steps[j] - tracker->steps[i] < 60) {
        steps_in_minute++;
      }
    }
    if (steps_in_minute > max_steps) {
      max_steps = steps_in_minute;
    }
  }
  return max_steps;
}

// Print the summary of the fitness tracker
void print_summary(FitnessTracker* tracker) {
  printf("Number of steps: %d\n", tracker->num_steps);
  printf("Duration: %d seconds\n", get_duration(tracker));
  printf("Average steps per minute: %.2f\n", get_avg_steps_per_minute(tracker));
  printf("Maximum steps per minute: %d\n", get_max_steps_per_minute(tracker));
}

// Main function
int main() {
  // Create a fitness tracker
  FitnessTracker* tracker = new_fitness_tracker();

  // Add some steps to the fitness tracker
  for (uint32_t i = 0; i < 100; i++) {
    add_step(tracker);
  }

  // Print the summary of the fitness tracker
  print_summary(tracker);

  // Free the memory allocated for the fitness tracker
  free(tracker);

  return 0;
}