//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the data structures for the fitness tracker
typedef struct {
  char *name;
  int age;
  int height;
  int weight;
  int steps;
  int calories;
  int distance;
  int active_minutes;
  time_t timestamp;
} fitness_data;

// Define the function to create a new fitness data object
fitness_data *create_fitness_data(char *name, int age, int height, int weight) {
  fitness_data *data = malloc(sizeof(fitness_data));
  data->name = strdup(name);
  data->age = age;
  data->height = height;
  data->weight = weight;
  data->steps = 0;
  data->calories = 0;
  data->distance = 0;
  data->active_minutes = 0;
  data->timestamp = time(NULL);
  return data;
}

// Define the function to update the fitness data object with new data
void update_fitness_data(fitness_data *data, int steps, int calories, int distance, int active_minutes) {
  data->steps += steps;
  data->calories += calories;
  data->distance += distance;
  data->active_minutes += active_minutes;
  data->timestamp = time(NULL);
}

// Define the function to print the fitness data object
void print_fitness_data(fitness_data *data) {
  printf("Name: %s\n", data->name);
  printf("Age: %d\n", data->age);
  printf("Height: %d\n", data->height);
  printf("Weight: %d\n", data->weight);
  printf("Steps: %d\n", data->steps);
  printf("Calories: %d\n", data->calories);
  printf("Distance: %d\n", data->distance);
  printf("Active minutes: %d\n", data->active_minutes);
  printf("Timestamp: %s\n", ctime(&data->timestamp));
}

// Define the main function
int main() {
  // Create a new fitness data object
  fitness_data *data = create_fitness_data("John Doe", 30, 72, 180);

  // Update the fitness data object with new data
  update_fitness_data(data, 10000, 500, 5, 60);

  // Print the fitness data object
  print_fitness_data(data);

  // Free the memory allocated for the fitness data object
  free(data->name);
  free(data);

  return 0;
}