//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define struct for exercises
typedef struct Exercise {
  char* name;
  int reps;
  int sets;
  float weight;
} Exercise;

// Define function to create new exercises
Exercise* createExercise(char* name, int reps, int sets, float weight) {
  Exercise* newExercise = (Exercise*) malloc(sizeof(Exercise));
  newExercise->name = name;
  newExercise->reps = reps;
  newExercise->sets = sets;
  newExercise->weight = weight;
  return newExercise;
}

int main() {
  // Create an array to store exercises
  Exercise* workouts[5];

  // Prompt user to add exercises
  printf("Welcome to the Fitness Tracker!\n\n");
  printf("Please enter 5 exercises to track:\n\n");

  // Use a for loop to iterate 5 times and prompt user for exercise details
  for (int i = 0; i < 5; i++) {
    char* name = (char*) malloc(sizeof(char) * 50);
    int reps, sets;
    float weight;

    printf("Enter the name of exercise #%d: ", i + 1);
    scanf("%s", name);

    printf("Enter the number of reps for exercise #%d: ", i + 1);
    scanf("%d", &reps);

    printf("Enter the number of sets for exercise #%d: ", i + 1);
    scanf("%d", &sets);

    printf("Enter the weight used for exercise #%d (in lbs): ", i + 1);
    scanf("%f", &weight);

    // Create new exercise and add to array
    workouts[i] = createExercise(name, reps, sets, weight);
  }

  // Print out list of completed exercises
  printf("\nHere are the exercises you entered:\n\n");

  for (int i = 0; i < 5; i++) {
    printf("Exercise #%d: %s\n", i + 1, workouts[i]->name);
    printf("Sets: %d\n", workouts[i]->sets);
    printf("Reps: %d\n", workouts[i]->reps);
    printf("Weight: %.2f lbs\n\n", workouts[i]->weight);
  }

  printf("Thank you for using the Fitness Tracker!\n");

  // Free memory used by exercises
  for (int i = 0; i < 5; i++) {
    free(workouts[i]->name);
    free(workouts[i]);
  }

  return 0;
}