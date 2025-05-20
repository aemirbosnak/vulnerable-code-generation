//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The number of cars in the simulation
#define NUM_CARS 100

// The length of the road in miles
#define ROAD_LENGTH 10

// The maximum speed of a car in miles per hour
#define MAX_SPEED 60

// The minimum speed of a car in miles per hour
#define MIN_SPEED 20

// The probability that a car will change lanes in a given time step
#define LANE_CHANGE_PROBABILITY 0.1

// The probability that a car will brake in a given time step
#define BRAKE_PROBABILITY 0.05

// The probability that a car will accelerate in a given time step
#define ACCELERATE_PROBABILITY 0.05

// The data structure for a car
typedef struct car {
  int id; // The ID of the car
  int lane; // The lane the car is in
  int speed; // The speed of the car in miles per hour
  int distance_to_next_car; // The distance to the next car in front of the car in miles
} car;

// The data structure for the road
typedef struct road {
  int length; // The length of the road in miles
  car cars[NUM_CARS]; // The array of cars on the road
} road;

// Create a new road
road *create_road() {
  road *r = malloc(sizeof(road));
  r->length = ROAD_LENGTH;
  for (int i = 0; i < NUM_CARS; i++) {
    r->cars[i].id = i;
    r->cars[i].lane = rand() % 3;
    r->cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
    r->cars[i].distance_to_next_car = rand() % ROAD_LENGTH;
  }
  return r;
}

// Destroy a road
void destroy_road(road *r) {
  free(r);
}

// Update the state of the road
void update_road(road *r) {
  for (int i = 0; i < NUM_CARS; i++) {
    // Update the car's speed
    if (rand() % 100 < ACCELERATE_PROBABILITY) {
      r->cars[i].speed++;
    } else if (rand() % 100 < BRAKE_PROBABILITY) {
      r->cars[i].speed--;
    }

    // Update the car's lane
    if (rand() % 100 < LANE_CHANGE_PROBABILITY) {
      r->cars[i].lane = rand() % 3;
    }

    // Update the car's distance to the next car
    if (i < NUM_CARS - 1) {
      r->cars[i].distance_to_next_car = r->cars[i + 1].distance_to_next_car - r->cars[i].speed;
    } else {
      r->cars[i].distance_to_next_car = ROAD_LENGTH;
    }
  }
}

// Print the state of the road
void print_road(road *r) {
  for (int i = 0; i < NUM_CARS; i++) {
    printf("Car %d: lane %d, speed %d, dist %d\n", r->cars[i].id,
           r->cars[i].lane, r->cars[i].speed, r->cars[i].distance_to_next_car);
  }
}

// The main function
int main() {
  // Create a new road
  road *r = create_road();

  // Update the state of the road 10 times
  for (int i = 0; i < 10; i++) {
    update_road(r);
  }

  // Print the state of the road
  print_road(r);

  // Destroy the road
  destroy_road(r);

  return 0;
}