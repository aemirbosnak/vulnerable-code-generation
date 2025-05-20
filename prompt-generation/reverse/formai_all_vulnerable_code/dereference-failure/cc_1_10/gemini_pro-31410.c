//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ACTIVITY_LENGTH 20
#define MAX_ACTIVITIES 100

typedef struct {
  char name[MAX_NAME_LENGTH];
  char activity[MAX_ACTIVITY_LENGTH];
  int duration;
  int calories;
} activity_t;

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  int weight;
  int height;
  activity_t activities[MAX_ACTIVITIES];
  int num_activities;
} user_t;

user_t *create_user(char *name, int age, int weight, int height) {
  user_t *user = malloc(sizeof(user_t));
  strcpy(user->name, name);
  user->age = age;
  user->weight = weight;
  user->height = height;
  user->num_activities = 0;
  return user;
}

void add_activity(user_t *user, char *activity, int duration, int calories) {
  if (user->num_activities < MAX_ACTIVITIES) {
    strcpy(user->activities[user->num_activities].activity, activity);
    user->activities[user->num_activities].duration = duration;
    user->activities[user->num_activities].calories = calories;
    user->num_activities++;
  }
}

void print_user(user_t *user) {
  printf("User: %s\n", user->name);
  printf("Age: %d\n", user->age);
  printf("Weight: %d\n", user->weight);
  printf("Height: %d\n", user->height);
  printf("Activities:\n");
  for (int i = 0; i < user->num_activities; i++) {
    printf("  %s: %d minutes, %d calories\n", user->activities[i].activity, user->activities[i].duration, user->activities[i].calories);
  }
}

int main() {
  srand(time(NULL));

  // Create a user
  user_t *user = create_user("John Doe", 25, 75, 180);

  // Add some activities to the user
  add_activity(user, "Running", 30, 200);
  add_activity(user, "Cycling", 60, 300);
  add_activity(user, "Swimming", 45, 250);

  // Print the user's information
  print_user(user);

  return 0;
}