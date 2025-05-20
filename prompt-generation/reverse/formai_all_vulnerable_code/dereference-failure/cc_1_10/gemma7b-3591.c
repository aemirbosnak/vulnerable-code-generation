//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
  char name[20];
  int floor;
  struct Passenger* next;
} Passenger;

Passenger* createPassenger(char* name, int floor) {
  Passenger* newPassenger = malloc(sizeof(Passenger));
  strcpy(newPassenger->name, name);
  newPassenger->floor = floor;
  newPassenger->next = NULL;

  return newPassenger;
}

void simulateElevator(Passenger* passengers) {
  int currentFloor = 1;
  time_t t = time(NULL);

  while (passengers) {
    if (passengers->floor == currentFloor) {
      printf("%s has reached floor %d at %ld.\n", passengers->name, currentFloor, t);
      passengers = passengers->next;
    } else if (currentFloor < passengers->floor) {
      currentFloor++;
      printf("The elevator is moving up to floor %d.\n", currentFloor);
    } else {
      currentFloor--;
      printf("The elevator is moving down to floor %d.\n", currentFloor);
    }

    t = time(NULL);
  }

  printf("The elevator has reached the top floor.\n");
}

int main() {
  Passenger* passengers = createPassenger("John Doe", 3);
  passengers = createPassenger("Jane Doe", 2);
  passengers = createPassenger("Peter Pan", 4);

  simulateElevator(passengers);

  return 0;
}