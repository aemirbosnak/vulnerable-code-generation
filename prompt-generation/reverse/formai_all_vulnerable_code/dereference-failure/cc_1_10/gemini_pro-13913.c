//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct elevator {
  int current_floor;
  int destination_floor;
  struct node *up_queue;
  struct node *down_queue;
} elevator_t;

void elevator_init(elevator_t *elevator) {
  elevator->current_floor = 0;
  elevator->destination_floor = 0;
  elevator->up_queue = NULL;
  elevator->down_queue = NULL;
}

void elevator_add_request(elevator_t *elevator, int floor) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = floor;
  new_node->next = NULL;

  if (floor > elevator->current_floor) {
    if (elevator->up_queue == NULL) {
      elevator->up_queue = new_node;
    } else {
      node_t *last_node = elevator->up_queue;
      while (last_node->next != NULL) {
        last_node = last_node->next;
      }
      last_node->next = new_node;
    }
  } else {
    if (elevator->down_queue == NULL) {
      elevator->down_queue = new_node;
    } else {
      node_t *last_node = elevator->down_queue;
      while (last_node->next != NULL) {
        last_node = last_node->next;
      }
      last_node->next = new_node;
    }
  }
}

void elevator_step(elevator_t *elevator) {
  if (elevator->current_floor == elevator->destination_floor) {
    if (elevator->up_queue != NULL) {
      elevator->destination_floor = elevator->up_queue->data;
      elevator->up_queue = elevator->up_queue->next;
    } else if (elevator->down_queue != NULL) {
      elevator->destination_floor = elevator->down_queue->data;
      elevator->down_queue = elevator->down_queue->next;
    } else {
      elevator->destination_floor = 0;
    }
  }

  if (elevator->current_floor < elevator->destination_floor) {
    elevator->current_floor++;
  } else if (elevator->current_floor > elevator->destination_floor) {
    elevator->current_floor--;
  }
}

int main() {
  elevator_t elevator;
  elevator_init(&elevator);

  elevator_add_request(&elevator, 3);
  elevator_add_request(&elevator, 5);
  elevator_add_request(&elevator, 1);

  while (elevator.destination_floor != 0) {
    elevator_step(&elevator);
    printf("Current floor: %d\n", elevator.current_floor);
  }

  return 0;
}