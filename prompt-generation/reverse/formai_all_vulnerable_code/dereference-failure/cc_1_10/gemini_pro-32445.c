//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the fitness tracker data structure
typedef struct fitness_tracker {
  char name[32];
  int age;
  int height;
  int weight;
  int steps;
  int calories;
  int distance;
  int heart_rate;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker(char *name, int age, int height, int weight) {
  fitness_tracker *tracker = malloc(sizeof(fitness_tracker));

  // Copy the name, age, height, and weight to the tracker
  strcpy(tracker->name, name);
  tracker->age = age;
  tracker->height = height;
  tracker->weight = weight;

  // Initialize the steps, calories, distance, and heart rate to 0
  tracker->steps = 0;
  tracker->calories = 0;
  tracker->distance = 0;
  tracker->heart_rate = 0;

  return tracker;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *tracker) {
  free(tracker);
}

// Get the name of a fitness tracker
char *get_fitness_tracker_name(fitness_tracker *tracker) {
  return tracker->name;
}

// Get the age of a fitness tracker
int get_fitness_tracker_age(fitness_tracker *tracker) {
  return tracker->age;
}

// Get the height of a fitness tracker
int get_fitness_tracker_height(fitness_tracker *tracker) {
  return tracker->height;
}

// Get the weight of a fitness tracker
int get_fitness_tracker_weight(fitness_tracker *tracker) {
  return tracker->weight;
}

// Get the steps of a fitness tracker
int get_fitness_tracker_steps(fitness_tracker *tracker) {
  return tracker->steps;
}

// Get the calories of a fitness tracker
int get_fitness_tracker_calories(fitness_tracker *tracker) {
  return tracker->calories;
}

// Get the distance of a fitness tracker
int get_fitness_tracker_distance(fitness_tracker *tracker) {
  return tracker->distance;
}

// Get the heart rate of a fitness tracker
int get_fitness_tracker_heart_rate(fitness_tracker *tracker) {
  return tracker->heart_rate;
}

// Set the steps of a fitness tracker
void set_fitness_tracker_steps(fitness_tracker *tracker, int steps) {
  tracker->steps = steps;
}

// Set the calories of a fitness tracker
void set_fitness_tracker_calories(fitness_tracker *tracker, int calories) {
  tracker->calories = calories;
}

// Set the distance of a fitness tracker
void set_fitness_tracker_distance(fitness_tracker *tracker, int distance) {
  tracker->distance = distance;
}

// Set the heart rate of a fitness tracker
void set_fitness_tracker_heart_rate(fitness_tracker *tracker, int heart_rate) {
  tracker->heart_rate = heart_rate;
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker *tracker) {
  printf("Name: %s\n", tracker->name);
  printf("Age: %d\n", tracker->age);
  printf("Height: %d\n", tracker->height);
  printf("Weight: %d\n", tracker->weight);
  printf("Steps: %d\n", tracker->steps);
  printf("Calories: %d\n", tracker->calories);
  printf("Distance: %d\n", tracker->distance);
  printf("Heart rate: %d\n", tracker->heart_rate);
}

// Main function
int main() {
  // Create a fitness tracker
  fitness_tracker *tracker = create_fitness_tracker("John Doe", 30, 180, 80);

  // Print the fitness tracker data
  print_fitness_tracker(tracker);

  // Set the steps of the fitness tracker
  set_fitness_tracker_steps(tracker, 10000);

  // Print the fitness tracker data
  print_fitness_tracker(tracker);

  // Destroy the fitness tracker
  destroy_fitness_tracker(tracker);

  return 0;
}