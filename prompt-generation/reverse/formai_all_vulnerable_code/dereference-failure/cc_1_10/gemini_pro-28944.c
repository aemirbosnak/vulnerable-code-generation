//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char *name;
  int steps;
  int calories;
  int distance;
} Activity;

typedef struct {
  char *name;
  Activity *activities;
  int num_activities;
} User;

// Function prototypes
User *create_user(char *name);
Activity *create_activity(char *name, int steps, int calories, int distance);
void add_activity(User *user, Activity *activity);
void print_user(User *user);

// Main function
int main() {
  // Create a new user
  User *user = create_user("John Doe");

  // Create some activities
  Activity *activity1 = create_activity("Walking", 5000, 250, 2);
  Activity *activity2 = create_activity("Running", 3000, 350, 1.5);
  Activity *activity3 = create_activity("Cycling", 2000, 400, 1);

  // Add the activities to the user
  add_activity(user, activity1);
  add_activity(user, activity2);
  add_activity(user, activity3);

  // Print the user's information
  print_user(user);

  // Free the memory allocated for the user and activities
  free(user->name);
  for (int i = 0; i < user->num_activities; i++) {
    free(user->activities[i].name);
  }
  free(user->activities);
  free(user);

  return 0;
}

// Function to create a new user
User *create_user(char *name) {
  User *user = malloc(sizeof(User));
  user->name = strdup(name);
  user->activities = NULL;
  user->num_activities = 0;
  return user;
}

// Function to create a new activity
Activity *create_activity(char *name, int steps, int calories, int distance) {
  Activity *activity = malloc(sizeof(Activity));
  activity->name = strdup(name);
  activity->steps = steps;
  activity->calories = calories;
  activity->distance = distance;
  return activity;
}

// Function to add an activity to a user
void add_activity(User *user, Activity *activity) {
  user->activities = realloc(user->activities, sizeof(Activity) * (user->num_activities + 1));
  user->activities[user->num_activities++] = *activity;
}

// Function to print the user's information
void print_user(User *user) {
  printf("Name: %s\n", user->name);
  printf("Number of activities: %d\n", user->num_activities);
  for (int i = 0; i < user->num_activities; i++) {
    printf("Activity %d:\n", i + 1);
    printf("  Name: %s\n", user->activities[i].name);
    printf("  Steps: %d\n", user->activities[i].steps);
    printf("  Calories: %d\n", user->activities[i].calories);
    printf("  Distance: %d\n", user->activities[i].distance);
  }
}