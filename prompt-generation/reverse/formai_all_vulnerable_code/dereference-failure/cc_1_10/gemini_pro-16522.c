//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct step {
  int timestamp;
  int count;
} step_t;

// Create a new fitness tracker
typedef struct fitness_tracker {
  char *name;
  int num_steps;
  step_t steps[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *fitness_tracker_new(char *name) {
  fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
  tracker->name = strdup(name);
  tracker->num_steps = 0;
  return tracker;
}

// Destroy a fitness tracker
void fitness_tracker_destroy(fitness_tracker_t *tracker) {
  free(tracker->name);
  free(tracker);
}

// Add a step to a fitness tracker
void fitness_tracker_add_step(fitness_tracker_t *tracker, int timestamp, int count) {
  if (tracker->num_steps < MAX_STEPS) {
    tracker->steps[tracker->num_steps].timestamp = timestamp;
    tracker->steps[tracker->num_steps].count = count;
    tracker->num_steps++;
  }
}

// Get the total number of steps in a fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker_t *tracker) {
  int total_steps = 0;
  for (int i = 0; i < tracker->num_steps; i++) {
    total_steps += tracker->steps[i].count;
  }
  return total_steps;
}

// Get the average number of steps per day in a fitness tracker
int fitness_tracker_get_average_steps_per_day(fitness_tracker_t *tracker) {
  int average_steps_per_day = 0;
  if (tracker->num_steps > 0) {
    average_steps_per_day = fitness_tracker_get_total_steps(tracker) / tracker->num_steps;
  }
  return average_steps_per_day;
}

// Print the steps in a fitness tracker
void fitness_tracker_print_steps(fitness_tracker_t *tracker) {
  for (int i = 0; i < tracker->num_steps; i++) {
    printf("%d: %d steps\n", tracker->steps[i].timestamp, tracker->steps[i].count);
  }
}

// Main function
int main() {
  // Create a new fitness tracker
  fitness_tracker_t *tracker = fitness_tracker_new("My Fitness Tracker");

  // Add some steps to the fitness tracker
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    int timestamp = rand() % 86400; // Random timestamp between 0 and 86400 seconds (1 day)
    int count = rand() % 1000 + 1; // Random step count between 1 and 1000
    fitness_tracker_add_step(tracker, timestamp, count);
  }

  // Print the steps in the fitness tracker
  fitness_tracker_print_steps(tracker);

  // Get the total number of steps in the fitness tracker
  int total_steps = fitness_tracker_get_total_steps(tracker);
  printf("Total steps: %d\n", total_steps);

  // Get the average number of steps per day in the fitness tracker
  int average_steps_per_day = fitness_tracker_get_average_steps_per_day(tracker);
  printf("Average steps per day: %d\n", average_steps_per_day);

  // Destroy the fitness tracker
  fitness_tracker_destroy(tracker);

  return 0;
}