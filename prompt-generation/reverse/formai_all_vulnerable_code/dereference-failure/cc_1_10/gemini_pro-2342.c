//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure of an activity
typedef struct Activity {
  char *name;
  int duration;
  int distance;
  int calories;
} Activity;

// Define the structure of the fitness tracker
typedef struct FitnessTracker {
  Activity activities[MAX_ACTIVITIES];
  int num_activities;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *create_fitness_tracker() {
  FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
  tracker->num_activities = 0;
  return tracker;
}

// Add an activity to the fitness tracker
void add_activity(FitnessTracker *tracker, Activity activity) {
  if (tracker->num_activities < MAX_ACTIVITIES) {
    tracker->activities[tracker->num_activities] = activity;
    tracker->num_activities++;
  }
}

// Print the activities in the fitness tracker
void print_activities(FitnessTracker *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    printf("%s: %d minutes, %d miles, %d calories\n", tracker->activities[i].name,
           tracker->activities[i].duration, tracker->activities[i].distance,
           tracker->activities[i].calories);
  }
}

// Get the total duration of all activities in the fitness tracker
int get_total_duration(FitnessTracker *tracker) {
  int total_duration = 0;
  for (int i = 0; i < tracker->num_activities; i++) {
    total_duration += tracker->activities[i].duration;
  }
  return total_duration;
}

// Get the total distance of all activities in the fitness tracker
int get_total_distance(FitnessTracker *tracker) {
  int total_distance = 0;
  for (int i = 0; i < tracker->num_activities; i++) {
    total_distance += tracker->activities[i].distance;
  }
  return total_distance;
}

// Get the total calories burned from all activities in the fitness tracker
int get_total_calories(FitnessTracker *tracker) {
  int total_calories = 0;
  for (int i = 0; i < tracker->num_activities; i++) {
    total_calories += tracker->activities[i].calories;
  }
  return total_calories;
}

// Main function
int main() {
  // Create a new fitness tracker
  FitnessTracker *tracker = create_fitness_tracker();

  // Add some activities to the fitness tracker
  Activity running = {"Running", 30, 5, 300};
  add_activity(tracker, running);
  Activity cycling = {"Cycling", 45, 10, 450};
  add_activity(tracker, cycling);
  Activity swimming = {"Swimming", 60, 1, 600};
  add_activity(tracker, swimming);

  // Print the activities in the fitness tracker
  printf("Activities:\n");
  print_activities(tracker);

  // Get the total duration of all activities in the fitness tracker
  int total_duration = get_total_duration(tracker);
  printf("Total duration: %d minutes\n", total_duration);

  // Get the total distance of all activities in the fitness tracker
  int total_distance = get_total_distance(tracker);
  printf("Total distance: %d miles\n", total_distance);

  // Get the total calories burned from all activities in the fitness tracker
  int total_calories = get_total_calories(tracker);
  printf("Total calories burned: %d calories\n", total_calories);

  return 0;
}