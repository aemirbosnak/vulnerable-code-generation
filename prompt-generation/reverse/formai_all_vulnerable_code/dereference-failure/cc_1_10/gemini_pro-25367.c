//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of lanes and the length of the road
#define NUM_LANES 3
#define ROAD_LENGTH 1000

// Define the maximum speed of a car
#define MAX_SPEED 100

// Define the probability of a car changing lanes
#define LANE_CHANGE_PROBABILITY 0.1

// Define the probability of a car braking
#define BRAKING_PROBABILITY 0.05

// Define the probability of a car entering the road
#define ENTERING_PROBABILITY 0.01

// Define the probability of a car leaving the road
#define LEAVING_PROBABILITY 0.01

// Define the structure of a car
typedef struct car {
  int lane;
  int speed;
  int position;
} car;

// Create a new car
car *new_car() {
  car *c = malloc(sizeof(car));
  c->lane = rand() % NUM_LANES;
  c->speed = rand() % MAX_SPEED;
  c->position = 0;
  return c;
}

// Update the state of a car
void update_car(car *c) {
  // Check if the car is braking
  if (rand() % 100 < BRAKING_PROBABILITY) {
    c->speed -= 10;
  }

  // Check if the car is changing lanes
  if (rand() % 100 < LANE_CHANGE_PROBABILITY) {
    c->lane = rand() % NUM_LANES;
  }

  // Check if the car is entering the road
  if (rand() % 100 < ENTERING_PROBABILITY) {
    c->lane = rand() % NUM_LANES;
    c->position = 0;
  }

  // Check if the car is leaving the road
  if (rand() % 100 < LEAVING_PROBABILITY) {
    c->position = ROAD_LENGTH;
  }

  // Update the car's position
  c->position += c->speed;
}

// Print the state of the road
void print_road(car **cars, int num_cars) {
  for (int i = 0; i < ROAD_LENGTH; i++) {
    for (int j = 0; j < NUM_LANES; j++) {
      int found = 0;
      for (int k = 0; k < num_cars; k++) {
        if (cars[k]->lane == j && cars[k]->position == i) {
          found = 1;
          break;
        }
      }
      if (found) {
        printf("X");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of cars
  car **cars = malloc(sizeof(car *) * 100);

  // Initialize the cars
  for (int i = 0; i < 100; i++) {
    cars[i] = new_car();
  }

  // Run the simulation for 100 time steps
  for (int i = 0; i < 100; i++) {
    // Update the state of each car
    for (int j = 0; j < 100; j++) {
      update_car(cars[j]);
    }

    // Print the state of the road
    print_road(cars, 100);
  }

  // Free the memory allocated for the cars
  for (int i = 0; i < 100; i++) {
    free(cars[i]);
  }
  free(cars);

  return 0;
}