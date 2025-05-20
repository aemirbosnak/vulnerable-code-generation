//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 10

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

Elevator* createElevator() {
  Elevator* elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->passengers = NULL;
  elevator->next = NULL;
  return elevator;
}

void addPassenger(Elevator* elevator, Passenger* passenger) {
  passenger->next = elevator->passengers;
  elevator->passengers = passenger;
}

void moveElevator(Elevator* elevator, int destination) {
  while (elevator->currentFloor != destination) {
    int nextFloor = elevator->currentFloor < destination ? elevator->currentFloor + 1 : elevator->currentFloor - 1;
    elevator->currentFloor = nextFloor;
    sleep(1);
  }
  elevator->currentFloor = destination;
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Elevator* elevator = createElevator();

  for (int i = 0; i < MAX_PASSENGERS; i++) {
    Passenger* passenger = malloc(sizeof(Passenger));
    passenger->name[0] = 'a' + i;
    passenger->floor = rand() % NUM_FLOORS + 1;
    addPassenger(elevator, passenger);
  }

  moveElevator(elevator, rand() % NUM_FLOORS + 1);

  for (Passenger* passenger = elevator->passengers; passenger; passenger = passenger->next) {
    printf("%s is at floor %d\n", passenger->name, passenger->floor);
  }

  return 0;
}