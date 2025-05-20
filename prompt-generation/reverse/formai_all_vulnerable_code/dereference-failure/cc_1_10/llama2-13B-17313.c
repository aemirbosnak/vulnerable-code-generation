//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants and types
#define ANT_SPEED 5.0f
#define ANT_ATTRACTION_STRENGTH 10.0f
#define ANT_REPULSION_STRENGTH 5.0f
#define ANT_MAX_AGE 100
#define ANT_MAX_FOOD 100
#define GRID_SIZE 100

// Define structures and functions
typedef struct {
  float x, y; // position
  float age; // age
  float food; // food level
} Ant;

void updateAnts(Ant *ants, int numAnts);
void drawAnts(Ant *ants, int numAnts);

int main() {
  // Initialize grid and ants
  Ant *ants = malloc(GRID_SIZE * GRID_SIZE * sizeof(Ant));
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      ants[i * GRID_SIZE + j].x = (float)i / 10.0f;
      ants[i * GRID_SIZE + j].y = (float)j / 10.0f;
      ants[i * GRID_SIZE + j].age = 0;
      ants[i * GRID_SIZE + j].food = 0;
    }
  }

  // Simulate ants for 1000 steps
  for (int i = 0; i < 1000; i++) {
    updateAnts(ants, GRID_SIZE * GRID_SIZE);
  }

  // Draw the final state of the ants
  drawAnts(ants, GRID_SIZE * GRID_SIZE);

  return 0;
}

// Update ant behavior
void updateAnts(Ant *ants, int numAnts) {
  // Update movement
  for (int i = 0; i < numAnts; i++) {
    Ant *ant = &ants[i];
    float direction = (float)rand() / RAND_MAX * 2 - 1;
    ant->x += direction * ANT_SPEED;
    if (ant->x < 0 || ant->x >= GRID_SIZE) {
      ant->x = (float)rand() / RAND_MAX * GRID_SIZE * 2 - 1;
    }

    // Update food level
    if (ant->x == 0 || ant->x == GRID_SIZE || ant->y == 0 || ant->y == GRID_SIZE) {
      ant->food += ANT_MAX_FOOD;
    } else {
      ant->food += (float)rand() / RAND_MAX * ANT_MAX_FOOD;
    }

    // Update age
    ant->age++;

    // Apply attraction and repulsion forces
    for (int j = 0; j < numAnts; j++) {
      Ant *otherAnt = &ants[j];
      if (i != j) {
        float distance = sqrtf(pow(ant->x - otherAnt->x, 2) + pow(ant->y - otherAnt->y, 2));
        float force = ANT_ATTRACTION_STRENGTH * (1 - distance / 10.0f);
        ant->x += force * (otherAnt->x - ant->x) / 10.0f;
        ant->y += force * (otherAnt->y - ant->y) / 10.0f;
      }
    }
  }
}

// Draw the ants
void drawAnts(Ant *ants, int numAnts) {
  for (int i = 0; i < numAnts; i++) {
    Ant *ant = &ants[i];
    printf("%.2f,%.2f\n", ant->x, ant->y);
  }
}