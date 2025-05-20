//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CARS 100
#define ROAD_SIZE 1000
#define MAX_SPEED 10

// Define the car struct
typedef struct car {
  int id;
  int position;
  int speed;
  pthread_t thread;
} Car;

// Define the road array
int road[ROAD_SIZE];

// Create a new car
Car* create_car(int id) {
  Car* car = malloc(sizeof(Car));
  car->id = id;
  car->position = 0;
  car->speed = rand() % MAX_SPEED + 1;
  return car;
}

// Drive the car
void* drive_car(void* arg) {
  Car* car = (Car*)arg;

  while (1) {
    // Check if the car is at the end of the road
    if (car->position >= ROAD_SIZE) {
      car->position = 0;
    }

    // Check if the car is too close to the car in front of it
    if (car->position > 0 && road[car->position - 1] > 0) {
      car->speed = road[car->position - 1] - 1;
    }

    // Move the car forward
    car->position += car->speed;

    // Update the road array
    road[car->position] = car->id;

    // Sleep for a bit
    usleep(1000);
  }

  return NULL;
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Create the cars
  Car* cars[NUM_CARS];
  for (int i = 0; i < NUM_CARS; i++) {
    cars[i] = create_car(i);
  }

  // Start the cars
  for (int i = 0; i < NUM_CARS; i++) {
    pthread_create(&cars[i]->thread, NULL, drive_car, cars[i]);
  }

  // Join the cars
  for (int i = 0; i < NUM_CARS; i++) {
    pthread_join(cars[i]->thread, NULL);
  }

  return 0;
}