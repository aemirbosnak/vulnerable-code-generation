//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to represent a user's fitness data
typedef struct {
  char *name;
  int age;
  int height;
  int weight;
  int steps;
  int calories;
  int distance;
  int sleep;
} FitnessData;

// Function to create a new FitnessData struct
FitnessData *new_fitness_data(char *name, int age, int height, int weight) {
  FitnessData *data = malloc(sizeof(FitnessData));
  data->name = strdup(name);
  data->age = age;
  data->height = height;
  data->weight = weight;
  data->steps = 0;
  data->calories = 0;
  data->distance = 0;
  data->sleep = 0;
  return data;
}

// Function to print the contents of a FitnessData struct
void print_fitness_data(FitnessData *data) {
  printf("Name: %s\n", data->name);
  printf("Age: %d\n", data->age);
  printf("Height: %d\n", data->height);
  printf("Weight: %d\n", data->weight);
  printf("Steps: %d\n", data->steps);
  printf("Calories: %d\n", data->calories);
  printf("Distance: %d\n", data->distance);
  printf("Sleep: %d\n", data->sleep);
}

// Function to generate random fitness data for a given user
void generate_fitness_data(FitnessData *data) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate random values for each field
  data->steps = rand() % 10000;
  data->calories = rand() % 1000;
  data->distance = rand() % 100;
  data->sleep = rand() % 10;
}

// Main function
int main() {
  // Create a new FitnessData struct for the user
  FitnessData *data = new_fitness_data("Neo", 30, 180, 80);

  // Generate random fitness data for the user
  generate_fitness_data(data);

  // Print the contents of the FitnessData struct
  print_fitness_data(data);

  return 0;
}