//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of steps per day
#define MAX_STEPS 10000

// Define the number of days in a week
#define DAYS_IN_WEEK 7

// Define a structure to represent a fitness tracker
typedef struct fitness_tracker {
  int steps[DAYS_IN_WEEK]; // The number of steps taken each day of the week
  int total_steps; // The total number of steps taken in the week
  int goal_steps; // The goal number of steps to take each day
  int average_steps; // The average number of steps taken each day
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker(int goal_steps) {
  fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
  tracker->total_steps = 0;
  tracker->goal_steps = goal_steps;
  for (int i = 0; i < DAYS_IN_WEEK; i++) {
    tracker->steps[i] = 0;
  }
  return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *tracker) {
  free(tracker);
}

// Add steps to a fitness tracker
void add_steps(fitness_tracker *tracker, int steps, int day) {
  tracker->steps[day] += steps;
  tracker->total_steps += steps;
}

// Calculate the average number of steps taken each day
void calculate_average_steps(fitness_tracker *tracker) {
  tracker->average_steps = tracker->total_steps / DAYS_IN_WEEK;
}

// Print the fitness tracker
void print_fitness_tracker(fitness_tracker *tracker) {
  printf("Fitness Tracker\n");
  printf("Goal Steps: %d\n", tracker->goal_steps);
  printf("Total Steps: %d\n", tracker->total_steps);
  for (int i = 0; i < DAYS_IN_WEEK; i++) {
    printf("Steps on day %d: %d\n", i + 1, tracker->steps[i]);
  }
  printf("Average Steps: %d\n", tracker->average_steps);
}

// Main function
int main() {
  // Create a new fitness tracker with a goal of 10,000 steps per day
  fitness_tracker *tracker = create_fitness_tracker(10000);

  // Add some steps to the tracker
  add_steps(tracker, 5000, 0); // Monday
  add_steps(tracker, 6000, 1); // Tuesday
  add_steps(tracker, 7000, 2); // Wednesday
  add_steps(tracker, 8000, 3); // Thursday
  add_steps(tracker, 9000, 4); // Friday
  add_steps(tracker, 10000, 5); // Saturday
  add_steps(tracker, 11000, 6); // Sunday

  // Calculate the average number of steps taken each day
  calculate_average_steps(tracker);

  // Print the fitness tracker
  print_fitness_tracker(tracker);

  // Destroy the fitness tracker
  destroy_fitness_tracker(tracker);

  return 0;
}