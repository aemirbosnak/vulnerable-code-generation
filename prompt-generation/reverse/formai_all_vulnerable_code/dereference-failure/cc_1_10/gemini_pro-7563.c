//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fitness tracker data structure
typedef struct FitnessTracker {
  int steps;
  int calories;
  int distance;
  time_t timestamp;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *create_fitness_tracker() {
  FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
  tracker->steps = 0;
  tracker->calories = 0;
  tracker->distance = 0;
  tracker->timestamp = time(NULL);
  return tracker;
}

// Update the fitness tracker with new data
void update_fitness_tracker(FitnessTracker *tracker, int steps, int calories, int distance) {
  tracker->steps += steps;
  tracker->calories += calories;
  tracker->distance += distance;
  tracker->timestamp = time(NULL);
}

// Print the fitness tracker data
void print_fitness_tracker(FitnessTracker *tracker) {
  printf("Steps: %d\n", tracker->steps);
  printf("Calories: %d\n", tracker->calories);
  printf("Distance: %d\n", tracker->distance);
  printf("Timestamp: %s\n", ctime(&tracker->timestamp));
}

// Generate random fitness tracker data
FitnessTracker *generate_random_fitness_tracker() {
  FitnessTracker *tracker = create_fitness_tracker();
  tracker->steps = rand() % 10000;
  tracker->calories = rand() % 1000;
  tracker->distance = rand() % 100;
  return tracker;
}

// Main function
int main() {
  // Create a new fitness tracker
  FitnessTracker *tracker = create_fitness_tracker();

  // Update the fitness tracker with some data
  update_fitness_tracker(tracker, 1000, 500, 10);

  // Print the fitness tracker data
  print_fitness_tracker(tracker);

  // Generate some random fitness tracker data
  FitnessTracker *random_tracker = generate_random_fitness_tracker();

  // Print the random fitness tracker data
  print_fitness_tracker(random_tracker);

  // Free the memory allocated for the fitness trackers
  free(tracker);
  free(random_tracker);

  return 0;
}