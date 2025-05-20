//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of cars that can be in the simulation
#define MAX_CARS 100

// Define the maximum speed of a car
#define MAX_SPEED 100

// Define the maximum distance between two cars
#define MAX_DISTANCE 100

// Define the minimum distance between two cars
#define MIN_DISTANCE 10

// Define the probability of a car changing lanes
#define LANE_CHANGE_PROBABILITY 0.1

// Define the probability of a car braking
#define BRAKE_PROBABILITY 0.05

// Define the probability of a car accelerating
#define ACCELERATE_PROBABILITY 0.1

// Define the structure of a car
typedef struct car {
  int id;              // The ID of the car
  int speed;            // The speed of the car
  int distance;         // The distance between the car and the car in front of it
  int lane;             // The lane the car is in
  struct car *next;      // The next car in the simulation
} car;

// Initialize the simulation
void init_simulation(car **head) {
  // Create a new car and set its properties
  car *new_car = malloc(sizeof(car));
  new_car->id = 0;
  new_car->speed = 0;
  new_car->distance = 0;
  new_car->lane = 0;
  new_car->next = NULL;

  // Add the new car to the head of the simulation
  *head = new_car;
}

// Update the simulation
void update_simulation(car **head) {
  car *current_car = *head;

  // Loop through each car in the simulation
  while (current_car != NULL) {
    // Update the car's speed
    current_car->speed += (rand() % 3) - 1;

    // Update the car's distance
    current_car->distance += current_car->speed;

    // Update the car's lane
    if (rand() % 100 < LANE_CHANGE_PROBABILITY) {
      if (current_car->lane > 0) {
        current_car->lane--;
      } else if (current_car->lane < 2) {
        current_car->lane++;
      }
    }

    // Update the car's next car
    current_car = current_car->next;
  }
}

// Draw the simulation
void draw_simulation(car *head) {
  car *current_car = head;

  // Loop through each car in the simulation
  while (current_car != NULL) {
    // Draw the car
    printf("Car %d: speed=%d, distance=%d, lane=%d\n", current_car->id, current_car->speed, current_car->distance, current_car->lane);

    // Update the car's next car
    current_car = current_car->next;
  }
}

// Free the simulation
void free_simulation(car *head) {
  car *current_car = head;

  // Loop through each car in the simulation
  while (current_car != NULL) {
    // Free the car
    free(current_car);

    // Update the car's next car
    current_car = current_car->next;
  }
}

// Main function
int main() {
  // Initialize the simulation
  car *head = NULL;
  init_simulation(&head);

  // Update the simulation
  for (int i = 0; i < 100; i++) {
    update_simulation(&head);
  }

  // Draw the simulation
  draw_simulation(head);

  // Free the simulation
  free_simulation(head);

  return 0;
}