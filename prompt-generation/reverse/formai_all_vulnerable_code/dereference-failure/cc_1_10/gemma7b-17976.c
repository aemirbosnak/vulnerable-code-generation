//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elevator {
  int currentFloor;
  int targetFloor;
  int direction;
  int passengers;
  struct elevator *next;
} Elevator;

Elevator *head = NULL;

void addElevator(int floor, int passengers) {
  Elevator *newElevator = malloc(sizeof(Elevator));
  newElevator->currentFloor = floor;
  newElevator->targetFloor = floor;
  newElevator->direction = 0;
  newElevator->passengers = passengers;
  newElevator->next = NULL;

  if (head == NULL) {
    head = newElevator;
  } else {
    Elevator *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newElevator;
  }
}

void moveElevator() {
  if (head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 2) {
      printf("Elevator is moving... \n");
      sleep(1);
    }

    head->currentFloor++;
    head->direction = 1;

    if (head->currentFloor == head->targetFloor) {
      head->direction = 0;
      head->passengers--;
      printf("Elevator has reached target floor. \n");
    }
  }
}

int main() {
  addElevator(1, 5);
  addElevator(3, 2);
  addElevator(5, 3);

  moveElevator();

  return 0;
}