//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the Vehicle
typedef struct {
  int speed;
  int direction;
  int battery_level;
} Vehicle;

// Define functions for the Vehicle
void set_speed(Vehicle* v, int new_speed) {
  v->speed = new_speed;
}

void set_direction(Vehicle* v, int new_direction) {
  v->direction = new_direction;
}

void set_battery_level(Vehicle* v, int new_battery_level) {
  v->battery_level = new_battery_level;
}

void print_vehicle(Vehicle* v) {
  printf("Vehicle status - Speed: %d, Direction: %d, Battery Level: %d\n", v->speed, v->direction, v->battery_level);
}

// Define a struct for the Remote Control
typedef struct {
  void (*set_speed)(Vehicle*, int); // function pointer to set_speed
  void (*set_direction)(Vehicle*, int); // function pointer to set_direction
  Vehicle* vehicle;
} RemoteControl;

// Define functions for the Remote Control
void set_vehicle_speed(RemoteControl* rc, int new_speed) {
  rc->set_speed(rc->vehicle, new_speed);
}

void set_vehicle_direction(RemoteControl* rc, int new_direction) {
  rc->set_direction(rc->vehicle, new_direction);
}

// Define a function to create a new Remote Control
RemoteControl* create_remote_control(void (*set_speed)(Vehicle*, int), void (*set_direction)(Vehicle*, int), Vehicle* v) {
  RemoteControl* rc = malloc(sizeof(RemoteControl));
  rc->set_speed = set_speed;
  rc->set_direction = set_direction;
  rc->vehicle = v;
  return rc;
}

int main() {
  // Create a Vehicle
  Vehicle* v = malloc(sizeof(Vehicle));
  v->speed = 0;
  v->direction = 0;
  v->battery_level = 100;

  // Create a Remote Control for the Vehicle
  RemoteControl* rc = create_remote_control(set_speed, set_direction, v);

  // Print the status of the Vehicle
  print_vehicle(v);

  // Set the speed and direction of the Vehicle using the Remote Control
  set_vehicle_speed(rc, 20);
  set_vehicle_direction(rc, 45);

  // Print the updated status of the Vehicle
  print_vehicle(v);

  // Free the Vehicle and Remote Control memory
  free(v);
  free(rc);
  
  return 0;
}