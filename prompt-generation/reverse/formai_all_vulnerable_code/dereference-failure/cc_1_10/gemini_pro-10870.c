//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the user's fitness data
typedef struct {
  int age;
  int weight;
  int height;
  int steps;
  int distance;
  int calories;
  int heart_rate;
} FitnessData;

// Function to create a new fitness data record
FitnessData* create_fitness_data(int age, int weight, int height, int steps, int distance, int calories, int heart_rate) {
  FitnessData* data = malloc(sizeof(FitnessData));
  data->age = age;
  data->weight = weight;
  data->height = height;
  data->steps = steps;
  data->distance = distance;
  data->calories = calories;
  data->heart_rate = heart_rate;
  return data;
}

// Function to print the fitness data record
void print_fitness_data(FitnessData* data) {
  printf("Age: %d\n", data->age);
  printf("Weight: %d\n", data->weight);
  printf("Height: %d\n", data->height);
  printf("Steps: %d\n", data->steps);
  printf("Distance: %d\n", data->distance);
  printf("Calories: %d\n", data->calories);
  printf("Heart rate: %d\n", data->heart_rate);
}

// Main function
int main() {
  // Create a new fitness data record
  FitnessData* data = create_fitness_data(30, 70, 170, 10000, 5, 500, 70);

  // Print the fitness data record
  print_fitness_data(data);

  // Free the fitness data record
  free(data);

  return 0;
}