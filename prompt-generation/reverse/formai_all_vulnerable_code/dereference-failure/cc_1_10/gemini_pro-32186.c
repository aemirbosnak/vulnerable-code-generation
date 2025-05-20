//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drones
#define MAX_DRONES 10

// Define the structure of a drone
typedef struct drone {
  int id;
  char name[32];
  int x;
  int y;
  int z;
} drone;

// Define the structure of a remote control
typedef struct remote_control {
  int id;
  char name[32];
  int num_drones;
  drone *drones[MAX_DRONES];
} remote_control;

// Define the function to create a new drone
drone *create_drone(int id, char *name, int x, int y, int z) {
  drone *new_drone = (drone *)malloc(sizeof(drone));
  new_drone->id = id;
  strcpy(new_drone->name, name);
  new_drone->x = x;
  new_drone->y = y;
  new_drone->z = z;
  return new_drone;
}

// Define the function to create a new remote control
remote_control *create_remote_control(int id, char *name) {
  remote_control *new_remote_control = (remote_control *)malloc(sizeof(remote_control));
  new_remote_control->id = id;
  strcpy(new_remote_control->name, name);
  new_remote_control->num_drones = 0;
  return new_remote_control;
}

// Define the function to add a drone to a remote control
void add_drone_to_remote_control(remote_control *remote_control, drone *drone) {
  remote_control->drones[remote_control->num_drones] = drone;
  remote_control->num_drones++;
}

// Define the function to remove a drone from a remote control
void remove_drone_from_remote_control(remote_control *remote_control, drone *drone) {
  int i;
  for (i = 0; i < remote_control->num_drones; i++) {
    if (remote_control->drones[i] == drone) {
      remote_control->drones[i] = remote_control->drones[remote_control->num_drones - 1];
      remote_control->num_drones--;
      break;
    }
  }
}

// Define the function to print the details of a drone
void print_drone(drone *drone) {
  printf("Drone ID: %d\n", drone->id);
  printf("Drone Name: %s\n", drone->name);
  printf("Drone Position: (%d, %d, %d)\n", drone->x, drone->y, drone->z);
}

// Define the function to print the details of a remote control
void print_remote_control(remote_control *remote_control) {
  printf("Remote Control ID: %d\n", remote_control->id);
  printf("Remote Control Name: %s\n", remote_control->name);
  printf("Number of Drones: %d\n", remote_control->num_drones);
  for (int i = 0; i < remote_control->num_drones; i++) {
    printf("Drone %d:\n", i + 1);
    print_drone(remote_control->drones[i]);
    printf("\n");
  }
}

// Define the main function
int main() {
  // Create a new remote control
  remote_control *remote_control = create_remote_control(1, "My Remote Control");

  // Create a new drone
  drone *drone1 = create_drone(1, "Drone 1", 0, 0, 0);

  // Add the drone to the remote control
  add_drone_to_remote_control(remote_control, drone1);

  // Print the details of the remote control
  print_remote_control(remote_control);

  // Remove the drone from the remote control
  remove_drone_from_remote_control(remote_control, drone1);

  // Print the details of the remote control
  print_remote_control(remote_control);

  return 0;
}