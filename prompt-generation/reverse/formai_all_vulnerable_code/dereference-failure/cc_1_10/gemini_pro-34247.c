//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STEPS 100000
#define MAX_HEART_RATE 220
#define MAX_CALORIES 5000

typedef struct {
  int steps;
  int heart_rate;
  int calories;
  time_t timestamp;
} fitness_data_t;

fitness_data_t *fitness_data;
int fitness_data_count = 0;

void add_fitness_data(int steps, int heart_rate, int calories) {
  if (fitness_data_count >= MAX_STEPS) {
    fprintf(stderr, "Error: fitness data buffer is full.\n");
    return;
  }

  fitness_data[fitness_data_count].steps = steps;
  fitness_data[fitness_data_count].heart_rate = heart_rate;
  fitness_data[fitness_data_count].calories = calories;
  fitness_data[fitness_data_count].timestamp = time(NULL);

  fitness_data_count++;
}

void print_fitness_data() {
  for (int i = 0; i < fitness_data_count; i++) {
    printf("Steps: %d\n", fitness_data[i].steps);
    printf("Heart rate: %d\n", fitness_data[i].heart_rate);
    printf("Calories: %d\n", fitness_data[i].calories);
    printf("Timestamp: %s\n", ctime(&fitness_data[i].timestamp));
    printf("\n");
  }
}

void generate_random_fitness_data() {
  for (int i = 0; i < MAX_STEPS; i++) {
    int steps = rand() % MAX_STEPS;
    int heart_rate = rand() % MAX_HEART_RATE;
    int calories = rand() % MAX_CALORIES;

    add_fitness_data(steps, heart_rate, calories);
  }
}

int main() {
  fitness_data = malloc(sizeof(fitness_data_t) * MAX_STEPS);

  generate_random_fitness_data();
  print_fitness_data();

  free(fitness_data);

  return 0;
}