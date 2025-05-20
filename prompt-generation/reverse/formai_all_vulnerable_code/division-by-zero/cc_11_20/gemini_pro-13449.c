//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VEHICLES 100
#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_LANES 3
#define MIN_LANES 1

typedef struct vehicle {
  int id;
  int lane;
  int speed;
  int distance_to_next_car;
} vehicle;

int main() {
  // Get user input for the simulation parameters
  int num_vehicles, num_lanes, time_steps;
  printf("Enter the number of vehicles (1-%d): ", MAX_VEHICLES);
  scanf("%d", &num_vehicles);
  printf("Enter the number of lanes (1-%d): ", MAX_LANES);
  scanf("%d", &num_lanes);
  printf("Enter the number of time steps: ");
  scanf("%d", &time_steps);

  // Initialize the simulation state
  vehicle vehicles[MAX_VEHICLES];
  for (int i = 0; i < num_vehicles; i++) {
    vehicles[i].id = i;
    vehicles[i].lane = rand() % num_lanes + 1;
    vehicles[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    vehicles[i].distance_to_next_car = rand() % 100 + 1;
  }

  // Run the simulation for the specified number of time steps
  for (int t = 0; t < time_steps; t++) {
    // Update the state of each vehicle
    for (int i = 0; i < num_vehicles; i++) {
      // Check if the vehicle can accelerate
      if (vehicles[i].speed < MAX_SPEED && vehicles[i].distance_to_next_car > vehicles[i].speed) {
        vehicles[i].speed++;
      }

      // Check if the vehicle can decelerate
      if (vehicles[i].speed > MIN_SPEED && vehicles[i].distance_to_next_car < vehicles[i].speed) {
        vehicles[i].speed--;
      }

      // Check if the vehicle can change lanes
      if (vehicles[i].lane > MIN_LANES && vehicles[i].distance_to_next_car > vehicles[i].speed) {
        vehicles[i].lane--;
      } else if (vehicles[i].lane < MAX_LANES && vehicles[i].distance_to_next_car > vehicles[i].speed) {
        vehicles[i].lane++;
      }

      // Move the vehicle forward
      vehicles[i].distance_to_next_car -= vehicles[i].speed;
    }

    // Display the current state of the simulation
    printf("\nTime step %d\n", t + 1);
    for (int i = 0; i < num_lanes; i++) {
      printf("Lane %d: ", i + 1);
      for (int j = 0; j < num_vehicles; j++) {
        if (vehicles[j].lane == i + 1) {
          printf("V%d(%d) ", vehicles[j].id, vehicles[j].speed);
        }
      }
      printf("\n");
    }
  }

  return 0;
}