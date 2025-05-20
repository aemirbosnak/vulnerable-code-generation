//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NUMBER_OF_DRONES 10

typedef struct Drone {
  int x;
  int y;
  int z;
  char status;
  struct Drone *next;
} Drone;

Drone *drone_list = NULL;

void add_drone(int x, int y, int z, char status) {
  Drone *new_drone = malloc(sizeof(Drone));
  new_drone->x = x;
  new_drone->y = y;
  new_drone->z = z;
  new_drone->status = status;
  new_drone->next = drone_list;
  drone_list = new_drone;
}

void move_drone(char direction, int distance) {
  Drone *current_drone = drone_list;
  while (current_drone) {
    switch (direction) {
      case 'f':
        current_drone->x++;
        break;
      case 'b':
        current_drone->x--;
        break;
      case 'l':
        current_drone->y++;
        break;
      case 'r':
        current_drone->y--;
        break;
    }
    current_drone = current_drone->next;
  }
}

void change_drone_status(char new_status) {
  Drone *current_drone = drone_list;
  while (current_drone) {
    current_drone->status = new_status;
    current_drone = current_drone->next;
  }
}

int main() {
  add_drone(0, 0, 0, 'a');
  add_drone(1, 1, 1, 'b');
  add_drone(2, 2, 2, 'c');

  move_drone('f', 5);
  move_drone('r', 3);
  change_drone_status('d');

   Drone *current_drone = drone_list;
  while (current_drone) {
    printf("Drone: (%d, %d, %d), Status: %c\n", current_drone->x, current_drone->y, current_drone->z, current_drone->status);
    current_drone = current_drone->next;
  }

  return 0;
}