//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTROLS 10

typedef struct Controller {
  int pin;
  char name[20];
  struct Controller* next;
} Controller;

Controller* head = NULL;

void addController(char* name, int pin) {
  Controller* newController = malloc(sizeof(Controller));
  newController->pin = pin;
  strcpy(newController->name, name);
  newController->next = NULL;

  if (head == NULL) {
    head = newController;
  } else {
    Controller* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newController;
  }
}

void controlDrone(char* controllerName, int action) {
  Controller* currentController = head;
  while (currentController) {
    if (strcmp(currentController->name, controllerName) == 0) {
      // Actions based on controller name and action
      switch (action) {
        case 1:
          printf("Drone moves forward.\n");
          break;
        case 2:
          printf("Drone moves right.\n");
          break;
        case 3:
          printf("Drone moves back.\n");
          break;
        case 4:
          printf("Drone moves left.\n");
          break;
        default:
          printf("Invalid action.\n");
          break;
      }
      return;
    }
    currentController = currentController->next;
  }

  printf("Controller not found.\n");
}

int main() {
  addController("Main Controller", 1);
  addController("Secondary Controller", 2);

  controlDrone("Main Controller", 1);
  controlDrone("Secondary Controller", 2);

  return 0;
}