//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData {
  int stepsTaken;
  int distanceTraveled;
  int caloriesBurned;
  char activityType;
} FitnessTrackerData;

// Function to calculate the number of steps taken
int calculateStepsTaken(int minutes) {
  return minutes * 20;
}

// Function to calculate the distance traveled
int calculateDistanceTraveled(int stepsTaken) {
  return stepsTaken * 0.05;
}

// Function to calculate the number of calories burned
int calculateCaloriesBurned(int minutes, char activityType) {
  int caloriesBurned = minutes * 6;
  if (activityType == 'H') {
    caloriesBurned *= 1.2;
  } else if (activityType == 'M') {
    caloriesBurned *= 1.0;
  } else if (activityType == 'L') {
    caloriesBurned *= 0.8;
  }
  return caloriesBurned;
}

int main() {
  // Create a fitness tracker data structure
  FitnessTrackerData fitnessTrackerData;

  // Get the user's input
  printf("Enter the number of minutes you spent exercising: ");
  int minutes = atoi(stdin);

  // Calculate the number of steps taken
  fitnessTrackerData.stepsTaken = calculateStepsTaken(minutes);

  // Calculate the distance traveled
  fitnessTrackerData.distanceTraveled = calculateDistanceTraveled(fitnessTrackerData.stepsTaken);

  // Calculate the number of calories burned
  fitnessTrackerData.caloriesBurned = calculateCaloriesBurned(minutes, fitnessTrackerData.activityType);

  // Print the fitness tracker data
  printf("Number of steps taken: %d\n", fitnessTrackerData.stepsTaken);
  printf("Distance traveled: %.2f miles\n", fitnessTrackerData.distanceTraveled);
  printf("Number of calories burned: %d\n", fitnessTrackerData.caloriesBurned);

  return 0;
}