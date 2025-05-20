//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KnuthFitnessTracker {
  char name[20];
  int age;
  double weight;
  double height;
  double bodyFatPercentage;
  double targetHeartRate;
  double currentHeartRate;
  int stepsTaken;
  int caloriesBurned;
  struct KnuthFitnessTracker* next;
} KnuthFitnessTracker;

KnuthFitnessTracker* createKnuthFitnessTracker(char* name, int age, double weight, double height, double bodyFatPercentage, double targetHeartRate, double currentHeartRate, int stepsTaken, int caloriesBurned) {
  KnuthFitnessTracker* tracker = (KnuthFitnessTracker*)malloc(sizeof(KnuthFitnessTracker));

  strcpy(tracker->name, name);
  tracker->age = age;
  tracker->weight = weight;
  tracker->height = height;
  tracker->bodyFatPercentage = bodyFatPercentage;
  tracker->targetHeartRate = targetHeartRate;
  tracker->currentHeartRate = currentHeartRate;
  tracker->stepsTaken = stepsTaken;
  tracker->caloriesBurned = caloriesBurned;
  tracker->next = NULL;

  return tracker;
}

void printKnuthFitnessTracker(KnuthFitnessTracker* tracker) {
  printf("Name: %s\n", tracker->name);
  printf("Age: %d\n", tracker->age);
  printf("Weight: %.2lf\n", tracker->weight);
  printf("Height: %.2lf\n", tracker->height);
  printf("Body Fat Percentage: %.2lf%\n", tracker->bodyFatPercentage);
  printf("Target Heart Rate: %.2lf\n", tracker->targetHeartRate);
  printf("Current Heart Rate: %.2lf\n", tracker->currentHeartRate);
  printf("Steps Taken: %d\n", tracker->stepsTaken);
  printf("Calories Burned: %d\n", tracker->caloriesBurned);
  printf("\n");
}

int main() {
  KnuthFitnessTracker* tracker = createKnuthFitnessTracker("Donald Knuth", 75, 85.0, 1.8, 15.0, 120.0, 80.0, 10000, 2000);

  printKnuthFitnessTracker(tracker);

  return 0;
}