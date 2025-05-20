//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
  int floor;
  struct Passenger* next;
} Passenger;

void simulate_elevator(int floors, int passengers) {
  Passenger* head = NULL;

  // Create passengers
  for (int i = 0; i < passengers; i++) {
    Passenger* new_passenger = malloc(sizeof(Passenger));
    new_passenger->floor = rand() % floors;
    new_passenger->next = head;
    head = new_passenger;
  }

  // Simulate elevator movement
  int current_floor = 0;
  while (!head || current_floor == head->floor) {
    // Randomly move up or down
    int direction = rand() % 2;
    if (direction == 0) {
      current_floor++;
    } else {
      current_floor--;
    }

    // Passengers get off at their floor
    Passenger* passenger = head;
    while (passenger) {
      if (current_floor == passenger->floor) {
        printf("Passenger %d gets off at floor %d.\n", passenger->floor, passenger->floor);
        free(passenger);
        passenger = head;
      } else {
        passenger = passenger->next;
      }
    }

    // Wait for a while
    sleep(1);
  }

  // Elevator reaches final floor
  printf("Elevator arrives at floor %d.\n", current_floor);
}

int main() {
  simulate_elevator(MAX_FLOORS, MAX_PASSENGERS);
  return 0;
}