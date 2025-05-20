//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct Floor {
  int floor_num;
  struct Floor* next;
} Floor;

Floor* insert_floor(Floor* head, int floor_num) {
  Floor* new_floor = malloc(sizeof(Floor));
  new_floor->floor_num = floor_num;
  new_floor->next = NULL;

  if (head == NULL) {
    head = new_floor;
  } else {
    Floor* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_floor;
  }

  return head;
}

void simulate_elevator(Floor* head) {
  int current_floor = 1;
  int destination_floor = 0;

  printf("Current floor: %d\n", current_floor);

  printf("Enter destination floor: ");
  scanf("%d", &destination_floor);

  while (current_floor != destination_floor) {
    int next_floor = rand() % MAX_FLOORS + 1;

    printf("Going to floor: %d\n", next_floor);
    current_floor = next_floor;

    printf("Current floor: %d\n", current_floor);
  }

  printf("Reached destination floor: %d\n", destination_floor);
}

int main() {
  Floor* head = insert_floor(NULL, 1);
  insert_floor(head, 2);
  insert_floor(head, 3);
  insert_floor(head, 4);

  simulate_elevator(head);

  return 0;
}