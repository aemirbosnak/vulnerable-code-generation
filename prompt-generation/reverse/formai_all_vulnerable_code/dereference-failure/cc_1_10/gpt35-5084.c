//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
// A unique C Drone Remote Control example program in a distributed style
#include <stdio.h>
#include <stdlib.h>

// Defining the Drone struct
typedef struct {
  int id;
  char direction;
  int altitude;
} Drone;

// Defining the Remote struct
typedef struct {
  int id;
  char* location;
} Remote;

// Function to initialize Remote object
Remote* create_remote(int id, char* location) {
  Remote* remote = malloc(sizeof(Remote));
  remote->id = id;
  remote->location = location;
  return remote;
}

// Function to initialize Drone object
Drone* create_drone(int id) {
  Drone* drone = malloc(sizeof(Drone));
  drone->id = id;
  drone->direction = 'N';
  drone->altitude = 0;
  return drone;
}

// Function to control the Drone's altitude
void control_altitude(Drone* drone, int altitude) {
  drone->altitude = altitude;
}

// Function to control the Drone's direction
void control_direction(Drone* drone, char direction) {
  drone->direction = direction;
}

// Function to print the Drone's status
void print_status(Drone* drone) {
  printf("Drone %d is flying at %dft in the %c direction.\n", drone->id, drone->altitude, drone->direction);
}

int main() {
  // Creating two Remote objects
  Remote* remote1 = create_remote(1, "North");
  Remote* remote2 = create_remote(2, "South");

  // Creating two Drone objects
  Drone* drone1 = create_drone(1);
  Drone* drone2 = create_drone(2);

  // Controlling the first drone using remote1
  control_altitude(drone1, 100);
  control_direction(drone1, 'S');

  // Controlling the second drone using remote2
  control_altitude(drone2, 200);
  control_direction(drone2, 'W');

  // Printing the status of both Drones
  print_status(drone1);
  print_status(drone2);

  // Deallocating the memory to prevent memory leaks
  free(remote1);
  free(remote2);
  free(drone1);
  free(drone2);

  return 0;
}