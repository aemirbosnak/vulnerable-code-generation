//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define NUM_LANES 3
#define NUM_CARS 100

typedef struct {
  int x, y;  // Coordinates
  int speed;  // Speed in km/h
  int lane;   // Lane number
} Car;

typedef struct {
  int length;  // Length in km
  int num_lanes;  // Number of lanes
  Car **cars;  // Array of cars on the road
} Road;

// Create a new road
Road *create_road(int length, int num_lanes) {
  Road *road = malloc(sizeof(Road));
  road->length = length;
  road->num_lanes = num_lanes;
  road->cars = malloc(sizeof(Car *) * NUM_CARS);
  return road;
}

// Create a new car
Car *create_car(int x, int y, int speed, int lane) {
  Car *car = malloc(sizeof(Car));
  car->x = x;
  car->y = y;
  car->speed = speed;
  car->lane = lane;
  return car;
}

// Initialize the simulation
void init_simulation(Road **roads) {
  for (int i = 0; i < NUM_ROADS; i++) {
    roads[i] = create_road(10, NUM_LANES);
    for (int j = 0; j < NUM_CARS; j++) {
      roads[i]->cars[j] = create_car(rand() % 10, i, rand() % 100, rand() % NUM_LANES);
    }
  }
}

// Update the simulation
void update_simulation(Road **roads) {
  for (int i = 0; i < NUM_ROADS; i++) {
    for (int j = 0; j < NUM_CARS; j++) {
      Car *car = roads[i]->cars[j];
      car->x += car->speed;
      if (car->x >= roads[i]->length) {
        car->x = 0;
      }
    }
  }
}

// Draw the simulation
void draw_simulation(Road **roads) {
  for (int i = 0; i < NUM_ROADS; i++) {
    for (int j = 0; j < roads[i]->num_lanes; j++) {
      printf("|");
      for (int k = 0; k < NUM_CARS; k++) {
        Car *car = roads[i]->cars[k];
        if (car->lane == j) {
          printf("X");
        } else {
          printf(" ");
        }
      }
    }
    printf("|\n");
  }
}

// Main simulation loop
int main() {
  srand(time(NULL));

  Road *roads[NUM_ROADS];
  init_simulation(roads);

  while (1) {
    update_simulation(roads);
    draw_simulation(roads);
    usleep(100000);
  }

  return 0;
}