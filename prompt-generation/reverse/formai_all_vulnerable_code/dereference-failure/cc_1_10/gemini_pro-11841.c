//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct exercise {
  char *name;
  int duration;
  int calories;
};

struct fitness_tracker {
  struct exercise *exercises;
  int num_exercises;
  int total_duration;
  int total_calories;
};

struct fitness_tracker *create_fitness_tracker() {
  struct fitness_tracker *tracker = malloc(sizeof(struct fitness_tracker));
  tracker->exercises = NULL;
  tracker->num_exercises = 0;
  tracker->total_duration = 0;
  tracker->total_calories = 0;
  return tracker;
}

void add_exercise(struct fitness_tracker *tracker, char *name, int duration, int calories) {
  tracker->exercises = realloc(tracker->exercises, (tracker->num_exercises + 1) * sizeof(struct exercise));
  tracker->exercises[tracker->num_exercises].name = strdup(name);
  tracker->exercises[tracker->num_exercises].duration = duration;
  tracker->exercises[tracker->num_exercises].calories = calories;
  tracker->num_exercises++;
  tracker->total_duration += duration;
  tracker->total_calories += calories;
}

void print_fitness_tracker(struct fitness_tracker *tracker) {
  printf("Fitness Tracker\n");
  printf("Total Duration: %d minutes\n", tracker->total_duration);
  printf("Total Calories: %d\n", tracker->total_calories);
  printf("Exercises:\n");
  for (int i = 0; i < tracker->num_exercises; i++) {
    printf("  %s: %d minutes, %d calories\n", tracker->exercises[i].name, tracker->exercises[i].duration, tracker->exercises[i].calories);
  }
}

int main() {
  struct fitness_tracker *tracker = create_fitness_tracker();
  add_exercise(tracker, "Running", 30, 200);
  add_exercise(tracker, "Cycling", 45, 300);
  add_exercise(tracker, "Swimming", 60, 400);
  print_fitness_tracker(tracker);
  return 0;
}