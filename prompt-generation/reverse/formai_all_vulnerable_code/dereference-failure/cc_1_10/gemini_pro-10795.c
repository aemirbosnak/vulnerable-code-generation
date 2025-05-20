//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the grid
#define GRID_SIZE 10

// Define the number of cars
#define NUM_CARS 10

// Define the maximum speed of a car
#define MAX_SPEED 5

// Define the probability of a car turning left or right
#define TURN_PROBABILITY 0.2

// Define the time quantum for each simulation step
#define TIME_QUANTUM 1

// Define the data structure for a car
typedef struct car {
  int x;
  int y;
  int speed;
  int direction;
} car;

// Define the data structure for the grid
typedef struct grid {
  car *cars[GRID_SIZE][GRID_SIZE];
} grid;

// Initialize the grid
void init_grid(grid *g) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      g->cars[i][j] = NULL;
    }
  }
}

// Create a new car
car *create_car(int x, int y, int speed, int direction) {
  car *c = malloc(sizeof(car));
  c->x = x;
  c->y = y;
  c->speed = speed;
  c->direction = direction;
  return c;
}

// Add a car to the grid
void add_car(grid *g, car *c) {
  g->cars[c->x][c->y] = c;
}

// Remove a car from the grid
void remove_car(grid *g, car *c) {
  g->cars[c->x][c->y] = NULL;
}

// Update the position of a car
void update_car(grid *g, car *c) {
  // Check if the car is at the edge of the grid
  if (c->x == 0 || c->x == GRID_SIZE-1 || c->y == 0 || c->y == GRID_SIZE-1) {
    // Turn the car around
    c->direction = (c->direction + 2) % 4;
  }

  // Check if the car is turning
  if (rand() < TURN_PROBABILITY * RAND_MAX) {
    // Turn the car left or right
    c->direction = (c->direction + 1) % 4;
  }

  // Update the car's position
  switch (c->direction) {
    case 0:  // North
      c->y -= c->speed;
      break;
    case 1:  // East
      c->x += c->speed;
      break;
    case 2:  // South
      c->y += c->speed;
      break;
    case 3:  // West
      c->x -= c->speed;
      break;
  }

  // Check if the car has collided with another car
  if (g->cars[c->x][c->y] != NULL && g->cars[c->x][c->y] != c) {
    // Remove both cars from the grid
    remove_car(g, c);
    remove_car(g, g->cars[c->x][c->y]);
  }
}

// Print the grid
void print_grid(grid *g) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (g->cars[i][j] != NULL) {
        printf("X");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Run the simulation
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new grid
  grid *g = malloc(sizeof(grid));
  init_grid(g);

  // Create a new car
  car *c = create_car(0, 0, 5, 0);

  // Add the car to the grid
  add_car(g, c);

  // Run the simulation for 100 time steps
  for (int i = 0; i < 100; i++) {
    // Update the position of the car
    update_car(g, c);

    // Print the grid
    print_grid(g);
  }

  // Free the memory allocated for the grid
  free(g);

  return 0;
}