//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: optimized
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

void simulate_elevator(int floors, int passengers) {
  // Create a linked list of passengers
  Passenger* head = NULL;
  for (int i = 0; i < passengers; i++) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, "Passenger " + i);
    new_passenger->floor = rand() % floors;
    new_passenger->next = head;
    head = new_passenger;
  }

  // Simulate the elevator moving between floors
  int current_floor = 1;
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 5) {
    // Get the next destination floor
    int next_floor = head->floor;
    while (next_floor == current_floor) {
      next_floor = rand() % floors;
    }

    // Move the elevator to the next floor
    current_floor = next_floor;

    // Print the elevator's current floor
    printf("The elevator is on floor %d.\n", current_floor);

    // Sleep for a random amount of time
    sleep(rand() % 2);
  }

  // Free the memory of the passengers
  Passenger* passenger = head;
  while (passenger) {
    Passenger* next_passenger = passenger->next;
    free(passenger);
    passenger = next_passenger;
  }
}

int main() {
  simulate_elevator(MAX_FLOORS, MAX_PASSENGERS);

  return 0;
}