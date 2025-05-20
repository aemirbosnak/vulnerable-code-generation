//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct FitnessTracker {
  int steps;
  int calories;
  int distance;
  time_t start_time;
  time_t end_time;
} FitnessTracker;

FitnessTracker* create_fitness_tracker() {
  FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
  tracker->steps = 0;
  tracker->calories = 0;
  tracker->distance = 0;
  tracker->start_time = time(NULL);
  tracker->end_time = 0;
  return tracker;
}

void start_tracking(FitnessTracker* tracker) {
  tracker->start_time = time(NULL);
}

void stop_tracking(FitnessTracker* tracker) {
  tracker->end_time = time(NULL);
}

int get_steps(FitnessTracker* tracker) {
  return tracker->steps;
}

int get_calories(FitnessTracker* tracker) {
  return tracker->calories;
}

int get_distance(FitnessTracker* tracker) {
  return tracker->distance;
}

double get_duration(FitnessTracker* tracker) {
  return difftime(tracker->end_time, tracker->start_time);
}

void print_fitness_tracker(FitnessTracker* tracker) {
  printf("Steps: %d\n", tracker->steps);
  printf("Calories: %d\n", tracker->calories);
  printf("Distance: %d\n", tracker->distance);
  printf("Duration: %f\n", get_duration(tracker));
}

int main() {
  FitnessTracker* tracker = create_fitness_tracker();
  start_tracking(tracker);
  // Do some fitness activities here
  stop_tracking(tracker);
  print_fitness_tracker(tracker);
  return 0;
}