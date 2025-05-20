//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

typedef struct FitnessTracker {
  int stepsTaken;
  int caloriesBurned;
  char mood;
  struct FitnessTracker* next;
} FitnessTracker;

void initializeFitnessTracker(FitnessTracker* tracker) {
  tracker->stepsTaken = 0;
  tracker->caloriesBurned = 0;
  tracker->mood = 'A';
  tracker->next = NULL;
}

void trackStep(FitnessTracker* tracker) {
  tracker->stepsTaken++;
  if (tracker->stepsTaken % MAX_NUM == 0) {
    tracker->caloriesBurned++;
  }
}

void trackMood(FitnessTracker* tracker, char mood) {
  tracker->mood = mood;
}

void printFitnessTracker(FitnessTracker* tracker) {
  printf("Steps taken: %d\n", tracker->stepsTaken);
  printf("Calories burned: %d\n", tracker->caloriesBurned);
  printf("Mood: %c\n", tracker->mood);
}

int main() {
  FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
  initializeFitnessTracker(tracker);

  for (int i = 0; i < MAX_NUM; i++) {
    trackStep(tracker);
  }

  trackMood(tracker, 'B');

  printFitnessTracker(tracker);

  free(tracker);

  return 0;
}