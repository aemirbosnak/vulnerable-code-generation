//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of days to track
#define NUM_DAYS 30

// Define the number of activities to track
#define NUM_ACTIVITIES 5

// Define the structure of an activity
typedef struct {
  char *name;
  int duration; // in minutes
  int intensity; // on a scale of 1-10
} Activity;

// Define the structure of a day
typedef struct {
  Activity activities[NUM_ACTIVITIES];
  int totalDuration; // in minutes
  int totalIntensity; // on a scale of 1-10
} Day;

// Define the structure of a fitness tracker
typedef struct {
  Day days[NUM_DAYS];
  int totalDuration; // in minutes
  int totalIntensity; // on a scale of 1-10
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker *newFitnessTracker() {
  FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
  for (int i = 0; i < NUM_DAYS; i++) {
    for (int j = 0; j < NUM_ACTIVITIES; j++) {
      tracker->days[i].activities[j].name = NULL;
      tracker->days[i].activities[j].duration = 0;
      tracker->days[i].activities[j].intensity = 0;
    }
    tracker->days[i].totalDuration = 0;
    tracker->days[i].totalIntensity = 0;
  }
  tracker->totalDuration = 0;
  tracker->totalIntensity = 0;
  return tracker;
}

// Add an activity to a day
void addActivity(FitnessTracker *tracker, int day, Activity activity) {
  tracker->days[day].activities[tracker->days[day].totalDuration] = activity;
  tracker->days[day].totalDuration += activity.duration;
  tracker->days[day].totalIntensity += activity.intensity;
  tracker->totalDuration += activity.duration;
  tracker->totalIntensity += activity.intensity;
}

// Print the fitness tracker
void printFitnessTracker(FitnessTracker *tracker) {
  printf("Fitness Tracker\n");
  for (int i = 0; i < NUM_DAYS; i++) {
    printf("Day %d\n", i + 1);
    for (int j = 0; j < NUM_ACTIVITIES; j++) {
      printf("  %s: %d minutes, intensity %d\n",
             tracker->days[i].activities[j].name,
             tracker->days[i].activities[j].duration,
             tracker->days[i].activities[j].intensity);
    }
    printf("  Total duration: %d minutes\n", tracker->days[i].totalDuration);
    printf("  Total intensity: %d\n", tracker->days[i].totalIntensity);
  }
  printf("Total duration: %d minutes\n", tracker->totalDuration);
  printf("Total intensity: %d\n", tracker->totalIntensity);
}

// Free the memory allocated for the fitness tracker
void freeFitnessTracker(FitnessTracker *tracker) {
  for (int i = 0; i < NUM_DAYS; i++) {
    for (int j = 0; j < NUM_ACTIVITIES; j++) {
      free(tracker->days[i].activities[j].name);
    }
  }
  free(tracker);
}

// Main function
int main() {
  // Create a new fitness tracker
  FitnessTracker *tracker = newFitnessTracker();

  // Add some activities to the fitness tracker
  Activity activity1 = {"Walking", 30, 5};
  addActivity(tracker, 0, activity1);
  Activity activity2 = {"Running", 20, 7};
  addActivity(tracker, 0, activity2);
  Activity activity3 = {"Swimming", 25, 6};
  addActivity(tracker, 0, activity3);
  Activity activity4 = {"Cycling", 30, 8};
  addActivity(tracker, 1, activity4);
  Activity activity5 = {"Yoga", 20, 4};
  addActivity(tracker, 1, activity5);

  // Print the fitness tracker
  printFitnessTracker(tracker);

  // Free the memory allocated for the fitness tracker
  freeFitnessTracker(tracker);

  return 0;
}