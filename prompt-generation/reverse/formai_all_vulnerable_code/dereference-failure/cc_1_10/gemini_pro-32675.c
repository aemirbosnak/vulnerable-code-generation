//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 100000

typedef struct {
  int steps;
  int distance;
  int calories;
  char *date;
} fitness_data;

fitness_data *fitness_data_create(int steps, int distance, int calories, char *date) {
  fitness_data *data = malloc(sizeof(fitness_data));
  if (data == NULL) {
    return NULL;
  }

  data->steps = steps;
  data->distance = distance;
  data->calories = calories;
  data->date = strdup(date);

  return data;
}

void fitness_data_destroy(fitness_data *data) {
  if (data == NULL) {
    return;
  }

  free(data->date);
  free(data);
}

int main() {
  // Create some sample fitness data.
  fitness_data *data[3];
  data[0] = fitness_data_create(10000, 5, 500, "2023-01-01");
  data[1] = fitness_data_create(12000, 6, 600, "2023-01-02");
  data[2] = fitness_data_create(15000, 7, 700, "2023-01-03");

  // Print the fitness data.
  for (int i = 0; i < 3; i++) {
    printf("Steps: %d\n", data[i]->steps);
    printf("Distance: %d\n", data[i]->distance);
    printf("Calories: %d\n", data[i]->calories);
    printf("Date: %s\n\n", data[i]->date);
  }

  // Destroy the fitness data.
  for (int i = 0; i < 3; i++) {
    fitness_data_destroy(data[i]);
  }

  return 0;
}