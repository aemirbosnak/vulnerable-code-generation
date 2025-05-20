//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of activities that can be tracked.
#define MAX_ACTIVITIES 100

// Define the structure of an activity.
typedef struct {
  char *name;
  int duration;
  int calories_burned;
} activity_t;

// Define the structure of a fitness tracker.
typedef struct {
  activity_t activities[MAX_ACTIVITIES];
  int num_activities;
} fitness_tracker_t;

// Create a new fitness tracker.
fitness_tracker_t *fitness_tracker_new() {
  fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
  tracker->num_activities = 0;
  return tracker;
}

// Add an activity to the fitness tracker.
void fitness_tracker_add_activity(fitness_tracker_t *tracker, activity_t activity) {
  if (tracker->num_activities >= MAX_ACTIVITIES) {
    printf("Error: cannot add more activities to the fitness tracker.\n");
    return;
  }
  tracker->activities[tracker->num_activities++] = activity;
}

// Print the fitness tracker data.
void fitness_tracker_print(fitness_tracker_t *tracker) {
  printf("Fitness Tracker Data:\n");
  for (int i = 0; i < tracker->num_activities; i++) {
    printf("Activity %d:\n", i + 1);
    printf("  Name: %s\n", tracker->activities[i].name);
    printf("  Duration: %d minutes\n", tracker->activities[i].duration);
    printf("  Calories Burned: %d\n", tracker->activities[i].calories_burned);
  }
}

// Free the memory allocated for the fitness tracker.
void fitness_tracker_free(fitness_tracker_t *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    free(tracker->activities[i].name);
  }
  free(tracker);
}

// Main function.
int main() {
  // Create a new fitness tracker.
  fitness_tracker_t *tracker = fitness_tracker_new();

  // Add some activities to the fitness tracker.
  activity_t activity1 = {"Running", 30, 300};
  fitness_tracker_add_activity(tracker, activity1);
  activity_t activity2 = {"Cycling", 45, 450};
  fitness_tracker_add_activity(tracker, activity2);
  activity_t activity3 = {"Swimming", 60, 600};
  fitness_tracker_add_activity(tracker, activity3);

  // Print the fitness tracker data.
  fitness_tracker_print(tracker);

  // Free the memory allocated for the fitness tracker.
  fitness_tracker_free(tracker);

  return 0;
}