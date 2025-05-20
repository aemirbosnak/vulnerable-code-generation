//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PESS_PER_FLOOR 5

typedef struct Passenger {
  char name[20];
  int floor;
  struct Passenger* next;
} Passenger;

Passenger* insertPassenger(Passenger* head, char* name, int floor) {
  Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
  strcpy(newPassenger->name, name);
  newPassenger->floor = floor;
  newPassenger->next = NULL;

  if (head == NULL) {
    head = newPassenger;
  } else {
    Passenger* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newPassenger;
  }

  return head;
}

void simulateElevator(Passenger* head) {
  int currentFloor = 1;
  while (head) {
    if (head->floor == currentFloor) {
      printf("%s has reached floor %d.\n", head->name, currentFloor);
    }
    currentFloor++;
    head = head->next;
  }

  printf("All passengers have reached their respective floors.\n");
}

int main() {
  Passenger* head = NULL;
  insertPassenger(head, "John Doe", 5);
  insertPassenger(head, "Jane Doe", 3);
  insertPassenger(head, "Peter Pan", 7);
  insertPassenger(head, "Mary Poppins", 2);
  insertPassenger(head, "Batman", 9);

  simulateElevator(head);

  return 0;
}