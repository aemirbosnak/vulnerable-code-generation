//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the tracker
#define MAX_STEPS 1000

// Define the structure of a fitness tracker entry
typedef struct {
  time_t timestamp;
  int steps;
  int distance;
  int calories;
} fitness_tracker_entry;

// Define the fitness tracker structure
typedef struct {
  fitness_tracker_entry entries[MAX_STEPS];
  int num_entries;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker* create_fitness_tracker() {
  fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
  tracker->num_entries = 0;
  return tracker;
}

// Add a new entry to the fitness tracker
void add_entry(fitness_tracker* tracker, time_t timestamp, int steps, int distance, int calories) {
  if (tracker->num_entries < MAX_STEPS) {
    tracker->entries[tracker->num_entries].timestamp = timestamp;
    tracker->entries[tracker->num_entries].steps = steps;
    tracker->entries[tracker->num_entries].distance = distance;
    tracker->entries[tracker->num_entries].calories = calories;
    tracker->num_entries++;
  }
}

// Get the total number of steps recorded by the fitness tracker
int get_total_steps(fitness_tracker* tracker) {
  int total_steps = 0;
  for (int i = 0; i < tracker->num_entries; i++) {
    total_steps += tracker->entries[i].steps;
  }
  return total_steps;
}

// Get the total distance recorded by the fitness tracker
int get_total_distance(fitness_tracker* tracker) {
  int total_distance = 0;
  for (int i = 0; i < tracker->num_entries; i++) {
    total_distance += tracker->entries[i].distance;
  }
  return total_distance;
}

// Get the total calories burned recorded by the fitness tracker
int get_total_calories(fitness_tracker* tracker) {
  int total_calories = 0;
  for (int i = 0; i < tracker->num_entries; i++) {
    total_calories += tracker->entries[i].calories;
  }
  return total_calories;
}

// Print the fitness tracker data to the console
void print_fitness_tracker(fitness_tracker* tracker) {
  printf("Fitness Tracker Data:\n");
  for (int i = 0; i < tracker->num_entries; i++) {
    printf("Timestamp: %ld\n", tracker->entries[i].timestamp);
    printf("Steps: %d\n", tracker->entries[i].steps);
    printf("Distance: %d\n", tracker->entries[i].distance);
    printf("Calories: %d\n\n", tracker->entries[i].calories);
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

  // Add some sample data to the fitness tracker
  add_entry(tracker, time(NULL), 1000, 1000, 100);
  add_entry(tracker, time(NULL), 2000, 2000, 200);
  add_entry(tracker, time(NULL), 3000, 3000, 300);

  // Print the fitness tracker data to the console
  print_fitness_tracker(tracker);

  // Get the total number of steps recorded by the fitness tracker
  int total_steps = get_total_steps(tracker);
  printf("Total steps: %d\n", total_steps);

  // Get the total distance recorded by the fitness tracker
  int total_distance = get_total_distance(tracker);
  printf("Total distance: %d\n", total_distance);

  // Get the total calories burned recorded by the fitness tracker
  int total_calories = get_total_calories(tracker);
  printf("Total calories: %d\n", total_calories);

  // Free the memory allocated for the fitness tracker
  free_fitness_tracker(tracker);

  return 0;
}