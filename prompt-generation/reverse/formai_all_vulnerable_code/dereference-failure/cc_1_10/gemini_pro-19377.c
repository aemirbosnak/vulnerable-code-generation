//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User data structure
typedef struct User {
  char name[32];
  int age;
  double height, weight;
} User;

// Fitness data structure
typedef struct FitnessData {
  int steps;
  int caloriesBurned;
  double distance;
} FitnessData;

// Function to create a new user
User* createUser(char* name, int age, double height, double weight) {
  User* user = (User*)malloc(sizeof(User));
  strcpy(user->name, name);
  user->age = age;
  user->height = height;
  user->weight = weight;
  return user;
}

// Function to create a new fitness data entry
FitnessData* createFitnessData(int steps, int caloriesBurned, double distance) {
  FitnessData* fitnessData = (FitnessData*)malloc(sizeof(FitnessData));
  fitnessData->steps = steps;
  fitnessData->caloriesBurned = caloriesBurned;
  fitnessData->distance = distance;
  return fitnessData;
}

// Function to print user data
void printUser(User* user) {
  printf("Name: %s\n", user->name);
  printf("Age: %d\n", user->age);
  printf("Height: %.2f m\n", user->height);
  printf("Weight: %.2f kg\n", user->weight);
}

// Function to print fitness data
void printFitnessData(FitnessData* fitnessData) {
  printf("Steps: %d\n", fitnessData->steps);
  printf("Calories burned: %d\n", fitnessData->caloriesBurned);
  printf("Distance: %.2f km\n", fitnessData->distance);
}

// Main function
int main() {
  // Create a new user
  User* user = createUser("John Doe", 30, 1.80, 80.0);

  // Create a new fitness data entry
  FitnessData* fitnessData = createFitnessData(10000, 500, 5.0);

  // Print the user data
  printf("User data:\n");
  printUser(user);

  // Print the fitness data
  printf("\nFitness data:\n");
  printFitnessData(fitnessData);

  // Free the allocated memory
  free(user);
  free(fitnessData);

  return 0;
}