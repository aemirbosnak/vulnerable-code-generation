//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the elevator's states
#define UP 1
#define DOWN -1
#define IDLE 0

// Define the number of floors
#define NUM_FLOORS 10

// Define the maximum number of passengers
#define MAX_PASSENGERS 5

// Define the type of passenger requests
typedef struct {
  int floor;
  int direction;
} passenger_request;

// Define the elevator struct
typedef struct {
  int current_floor;
  int state;
  passenger_request* requests[NUM_FLOORS];
} elevator;

// Create a new elevator
elevator* create_elevator() {
  elevator* e = malloc(sizeof(elevator));
  e->current_floor = 1;
  e->state = IDLE;
  for (int i = 0; i < NUM_FLOORS; i++) {
    e->requests[i] = NULL;
  }
  return e;
}

// Add a passenger request to the elevator
void add_request(elevator* e, passenger_request* request) {
  e->requests[request->floor] = request;
}

// Remove a passenger request from the elevator
void remove_request(elevator* e, passenger_request* request) {
  e->requests[request->floor] = NULL;
}

// Step the elevator
void step_elevator(elevator* e) {
  // Check if there are any requests on the current floor
  if (e->requests[e->current_floor] != NULL) {
    // If there are, add them to the elevator
    add_request(e, e->requests[e->current_floor]);
    remove_request(e, e->requests[e->current_floor]);
  }

  // Check if the elevator is at the top or bottom floor
  if (e->current_floor == 1 || e->current_floor == NUM_FLOORS) {
    // If it is, reverse direction
    e->state = -e->state;
  }

  // Move the elevator
  e->current_floor += e->state;
}

// Print the elevator's status
void print_elevator(elevator* e) {
  printf("Elevator is on floor %d\n", e->current_floor);
  printf("Elevator state: %s\n", e->state == UP ? "UP" : (e->state == DOWN ? "DOWN" : "IDLE"));
  printf("Passengers waiting:\n");
  for (int i = 1; i <= NUM_FLOORS; i++) {
    if (e->requests[i] != NULL) {
      printf("  - Floor %d, %s\n", i, e->requests[i]->direction == UP ? "UP" : "DOWN");
    }
  }
}

// Main function
int main() {
  // Create a new elevator
  elevator* e = create_elevator();

  // Add some random passenger requests
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int floor = rand() % NUM_FLOORS + 1;
    int direction = rand() % 2 == 0 ? UP : DOWN;
    passenger_request* request = malloc(sizeof(passenger_request));
    request->floor = floor;
    request->direction = direction;
    add_request(e, request);
  }

  // Step the elevator until there are no more requests
  while (e->requests[e->current_floor] != NULL || e->state != IDLE) {
    step_elevator(e);
    print_elevator(e);
  }

  return 0;
}