//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_CALORIES 500
#define MAX_DISTANCE 100

typedef struct {
  int steps;
  int calories;
  int distance;
  char *date;
} FitnessData;

FitnessData *fitnessData;
int fitnessDataCount;

void initFitnessData() {
  fitnessData = malloc(sizeof(FitnessData) * MAX_STEPS);
  fitnessDataCount = 0;
}

void destroyFitnessData() {
  free(fitnessData);
}

void addFitnessData(int steps, int calories, int distance, char *date) {
  if (fitnessDataCount >= MAX_STEPS) {
    return;
  }

  fitnessData[fitnessDataCount].steps = steps;
  fitnessData[fitnessDataCount].calories = calories;
  fitnessData[fitnessDataCount].distance = distance;
  fitnessData[fitnessDataCount].date = strdup(date);
  fitnessDataCount++;
}

void printFitnessData() {
  for (int i = 0; i < fitnessDataCount; i++) {
    printf("%s: %d steps, %d calories, %d distance\n",
           fitnessData[i].date,
           fitnessData[i].steps,
           fitnessData[i].calories,
           fitnessData[i].distance);
  }
}

void generateRandomFitnessData() {
  srand(time(NULL));

  for (int i = 0; i < MAX_STEPS; i++) {
    int steps = rand() % MAX_STEPS;
    int calories = rand() % MAX_CALORIES;
    int distance = rand() % MAX_DISTANCE;
    char *date = malloc(11);
    sprintf(date, "%d-%d-%d",
            1970 + (rand() % 50),
            1 + (rand() % 12),
            1 + (rand() % 28));

    addFitnessData(steps, calories, distance, date);
  }
}

int main() {
  initFitnessData();
  generateRandomFitnessData();
  printFitnessData();
  destroyFitnessData();

  return 0;
}