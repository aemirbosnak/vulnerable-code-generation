//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure of an activity
typedef struct activity {
  char *name;
  int duration;
  int intensity;
} activity_t;

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
  activity_t activities[MAX_ACTIVITIES];
  int num_activities;
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *create_fitness_tracker() {
  fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
  tracker->num_activities = 0;
  return tracker;
}

// Add an activity to a fitness tracker
void add_activity(fitness_tracker_t *tracker, activity_t activity) {
  if (tracker->num_activities < MAX_ACTIVITIES) {
    tracker->activities[tracker->num_activities] = activity;
    tracker->num_activities++;
  }
}

// Print the activities in a fitness tracker
void print_activities(fitness_tracker_t *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    printf("%s: %d minutes, %d intensity\n", tracker->activities[i].name, tracker->activities[i].duration, tracker->activities[i].intensity);
  }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker_t *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    free(tracker->activities[i].name);
  }
  free(tracker);
}

// Main function
int main() {
  // Create a new fitness tracker
  fitness_tracker_t *tracker = create_fitness_tracker();

  // Add some activities to the tracker
  activity_t activity1 = {"Running", 30, 7};
  add_activity(tracker, activity1);
  activity_t activity2 = {"Cycling", 45, 8};
  add_activity(tracker, activity2);
  activity_t activity3 = {"Swimming", 60, 9};
  add_activity(tracker, activity3);

  // Print the activities in the tracker
  print_activities(tracker);

  // Free the memory allocated for the tracker
  free_fitness_tracker(tracker);

  return 0;
}