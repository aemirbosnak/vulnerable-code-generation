//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
  char name[20];
  int floor;
  struct Passenger* next;
} Passenger;

typedef struct Elevator {
  int currentFloor;
  Passenger* passengers;
  struct Elevator* next;
} Elevator;

void moveElevator(Elevator* elevator) {
  int targetFloor;

  printf("Enter target floor (1-%d): ", MAX_FLOORS);
  scanf("%d", &targetFloor);

  while (elevator->currentFloor != targetFloor) {
    if (elevator->currentFloor < targetFloor) {
      elevator->currentFloor++;
      printf("Elevator moving up...\n");
    } else if (elevator->currentFloor > targetFloor) {
      elevator->currentFloor--;
      printf("Elevator moving down...\n");
    }
    sleep(1);
  }

  printf("Elevator arrived at floor %d.\n", targetFloor);
}

int main() {
  time_t t;
  int i, passengers = 0;
  Elevator* elevator = NULL;

  t = time(NULL);
  srand(t);

  // Create elevator
  elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->passengers = NULL;
  elevator->next = NULL;

  // Create passengers
  for (i = 0; i < MAX_PASSENGERS; i++) {
    Passenger* passenger = malloc(sizeof(Passenger));
    passenger->name[0] = 'A' + i;
    passenger->floor = rand() % MAX_FLOORS + 1;
    passenger->next = elevator->passengers;
    elevator->passengers = passenger;
  }

  // Move elevator
  moveElevator(elevator);

  // Free memory
  free(elevator);
  free(elevator->passengers);

  return 0;
}