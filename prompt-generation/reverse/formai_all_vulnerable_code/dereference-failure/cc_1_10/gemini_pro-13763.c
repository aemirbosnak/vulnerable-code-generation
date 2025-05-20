//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
// Ada Lovelace style C Fitness Tracker

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 10000

// Define the maximum number of heart rate readings that can be recorded
#define MAX_HEART_RATE_READINGS 100

// Define the maximum number of calories burned that can be recorded
#define MAX_CALORIES_BURNED 1000

// Define the maximum number of minutes of exercise that can be recorded
#define MAX_MINUTES_OF_EXERCISE 60

// Define the maximum number of fitness activities that can be recorded
#define MAX_FITNESS_ACTIVITIES 10

// Define the structure of a fitness activity
typedef struct fitness_activity {
  char *name;
  int steps;
  int heart_rate_readings[MAX_HEART_RATE_READINGS];
  int calories_burned;
  int minutes_of_exercise;
} fitness_activity;

// Define the structure of a fitness tracker
typedef struct fitness_tracker {
  fitness_activity activities[MAX_FITNESS_ACTIVITIES];
  int num_activities;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
  fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
  tracker->num_activities = 0;
  return tracker;
}

// Add a new fitness activity to the tracker
void add_fitness_activity(fitness_tracker *tracker, fitness_activity activity) {
  tracker->activities[tracker->num_activities] = activity;
  tracker->num_activities++;
}

// Print the fitness tracker to the console
void print_fitness_tracker(fitness_tracker *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    fitness_activity activity = tracker->activities[i];
    printf("Activity %d:\n", i + 1);
    printf("  Name: %s\n", activity.name);
    printf("  Steps: %d\n", activity.steps);
    printf("  Heart rate readings: ");
    for (int j = 0; j < activity.heart_rate_readings; j++) {
      printf("%d ", activity.heart_rate_readings[j]);
    }
    printf("\n");
    printf("  Calories burned: %d\n", activity.calories_burned);
    printf("  Minutes of exercise: %d\n", activity.minutes_of_exercise);
    printf("\n");
  }
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker *tracker) {
  for (int i = 0; i < tracker->num_activities; i++) {
    free(tracker->activities[i].name);
  }
  free(tracker);
}

// Main function
int main() {
  // Create a new fitness tracker
  fitness_tracker *tracker = create_fitness_tracker();

  // Add some fitness activities to the tracker
  fitness_activity activity1 = {
    .name = "Walking",
    .steps = 1000,
    .heart_rate_readings = {70, 72, 75, 78, 80, 82, 85, 87, 89, 90},
    .calories_burned = 100,
    .minutes_of_exercise = 30
  };
  add_fitness_activity(tracker, activity1);

  fitness_activity activity2 = {
    .name = "Running",
    .steps = 2000,
    .heart_rate_readings = {90, 92, 95, 98, 100, 102, 105, 107, 109, 110},
    .calories_burned = 200,
    .minutes_of_exercise = 45
  };
  add_fitness_activity(tracker, activity2);

  fitness_activity activity3 = {
    .name = "Cycling",
    .steps = 3000,
    .heart_rate_readings = {80, 82, 85, 88, 90, 92, 95, 97, 99, 100},
    .calories_burned = 300,
    .minutes_of_exercise = 60
  };
  add_fitness_activity(tracker, activity3);

  // Print the fitness tracker to the console
  print_fitness_tracker(tracker);

  // Free the memory allocated for the fitness tracker
  free_fitness_tracker(tracker);

  return 0;
}