//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the elevator states
#define IDLE 0
#define UP 1
#define DOWN 2

// Define the number of floors
#define NUM_FLOORS 10

// Define the maximum number of passengers
#define MAX_PASSENGERS 10

// Define the elevator structure
typedef struct {
  int state;
  int current_floor;
  int destination_floor;
  int num_passengers;
  int passengers[MAX_PASSENGERS];
} elevator_t;

// Create a new elevator
elevator_t* elevator_new() {
  elevator_t* elevator = malloc(sizeof(elevator_t));
  elevator->state = IDLE;
  elevator->current_floor = 0;
  elevator->destination_floor = 0;
  elevator->num_passengers = 0;
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    elevator->passengers[i] = -1;
  }
  return elevator;
}

// Destroy an elevator
void elevator_destroy(elevator_t* elevator) {
  free(elevator);
}

// Add a passenger to the elevator
void elevator_add_passenger(elevator_t* elevator, int passenger) {
  if (elevator->num_passengers == MAX_PASSENGERS) {
    printf("Elevator is full!\n");
    return;
  }
  elevator->passengers[elevator->num_passengers] = passenger;
  elevator->num_passengers++;
}

// Remove a passenger from the elevator
void elevator_remove_passenger(elevator_t* elevator, int passenger) {
  for (int i = 0; i < elevator->num_passengers; i++) {
    if (elevator->passengers[i] == passenger) {
      elevator->passengers[i] = -1;
      elevator->num_passengers--;
      break;
    }
  }
}

// Move the elevator up one floor
void elevator_move_up(elevator_t* elevator) {
  if (elevator->current_floor == NUM_FLOORS - 1) {
    printf("Elevator is already at the top floor!\n");
    return;
  }
  elevator->current_floor++;
}

// Move the elevator down one floor
void elevator_move_down(elevator_t* elevator) {
  if (elevator->current_floor == 0) {
    printf("Elevator is already at the bottom floor!\n");
    return;
  }
  elevator->current_floor--;
}

// Update the elevator's state
void elevator_update_state(elevator_t* elevator) {
  if (elevator->current_floor == elevator->destination_floor) {
    elevator->state = IDLE;
    for (int i = 0; i < elevator->num_passengers; i++) {
      if (elevator->passengers[i] != -1) {
        printf("Passenger %d has arrived at floor %d.\n", elevator->passengers[i], elevator->current_floor);
        elevator_remove_passenger(elevator, elevator->passengers[i]);
      }
    }
  } else if (elevator->current_floor < elevator->destination_floor) {
    elevator->state = UP;
  } else {
    elevator->state = DOWN;
  }
}

// Run the elevator simulation
void elevator_run(elevator_t* elevator) {
  while (1) {
    // Update the elevator's state
    elevator_update_state(elevator);

    // Move the elevator
    switch (elevator->state) {
      case UP:
        elevator_move_up(elevator);
        break;
      case DOWN:
        elevator_move_down(elevator);
        break;
      case IDLE:
        // Check for passengers waiting on the current floor
        for (int i = 0; i < NUM_FLOORS; i++) {
          if (i != elevator->current_floor) {
            int num_passengers_waiting = rand() % 5;
            for (int j = 0; j < num_passengers_waiting; j++) {
              elevator_add_passenger(elevator, i);
            }
          }
        }

        // Set the elevator's destination floor
        if (elevator->num_passengers > 0) {
          int destination_floor = rand() % NUM_FLOORS;
          while (destination_floor == elevator->current_floor) {
            destination_floor = rand() % NUM_FLOORS;
          }
          elevator->destination_floor = destination_floor;
        }
        break;
    }

    // Sleep for a while
    usleep(100000);
  }
}

// Main function
int main() {
  // Create a new elevator
  elevator_t* elevator = elevator_new();

  // Run the elevator simulation
  elevator_run(elevator);

  // Destroy the elevator
  elevator_destroy(elevator);

  return 0;
}