//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the vehicle structure
typedef struct {
  char name[20];
  int speed;
  float range;
} Vehicle;

// Declare the remote control structure
typedef struct {
  char name[20];
  Vehicle* vehicle;
  int battery;
} Remote;

// Some sample vehicles
Vehicle car = {"Car", 50, 100.0};
Vehicle drone = {"Drone", 30, 50.0};
Vehicle boat = {"Boat", 20, 75.0};

// Global remote control
Remote* remote;

// Initialize the remote control with a vehicle
void init_remote(Vehicle* v) {
  remote = malloc(sizeof(Remote));
  strcpy(remote->name, "My Remote");
  remote->vehicle = v;
  remote->battery = 100;
}

// Check if vehicle can be controlled
int can_control(int speed) {
  return (remote->battery > 0 && speed <= remote->vehicle->speed);
}

// Control the vehicle
void control_vehicle(int speed) {
  if (can_control(speed)) {
    printf("Vehicle controlled at speed %d\n", speed);
    remote->battery--;
  } else {
    printf("Vehicle cannot be controlled at speed %d\n", speed);
  }
}

int main() {
  // Initialize remote control with car
  init_remote(&car);

  // Control the car at different speeds
  control_vehicle(50); // should work
  control_vehicle(70); // should fail

  // Switch to drone
  remote->vehicle = &drone;

  // Control the drone at different speeds
  control_vehicle(20); // should work
  control_vehicle(40); // should fail

  // Switch to boat
  remote->vehicle = &boat;

  // Control the boat at different speeds
  control_vehicle(10); // should work
  control_vehicle(30); // should fail

  return 0;
}