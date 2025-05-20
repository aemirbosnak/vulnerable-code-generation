//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
  char name[20];
  int floor;
  struct Passenger* next;
} Passenger;

void simulate_elevator(Passenger* head) {
  time_t t = time(NULL);
  int currentFloor = 1;
  int destinationFloor = rand() % NUM_FLOORS + 1;

  // Move the elevator to the destination floor
  while (currentFloor != destinationFloor) {
    printf("Elevator moving to floor %d...\n", currentFloor);
    sleep(t);
    currentFloor++;
  }

  // Passengers get off at their destination floor
  while (head) {
    if (head->floor == destinationFloor) {
      printf("%s has exited the elevator on floor %d.\n", head->name, destinationFloor);
      free(head);
      head = head->next;
    } else {
      head = head->next;
    }
  }

  // Elevator reaches the top floor
  if (currentFloor == NUM_FLOORS) {
    printf("Elevator at top floor.\n");
  }
}

int main() {
  Passenger* head = NULL;

  // Create some passengers
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, "Passenger " + i);
    newPassenger->floor = rand() % NUM_FLOORS + 1;
    newPassenger->next = head;
    head = newPassenger;
  }

  // Simulate the elevator
  simulate_elevator(head);

  return 0;
}