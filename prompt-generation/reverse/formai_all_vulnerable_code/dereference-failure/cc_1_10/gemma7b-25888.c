//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 10

typedef struct Drone {
  char name[20];
  int battery_level;
  double x, y, z;
  struct Drone* next;
} Drone;

Drone* drone_list = NULL;

void add_drone(char* name, int battery_level, double x, double y, double z) {
  Drone* new_drone = (Drone*)malloc(sizeof(Drone));
  strcpy(new_drone->name, name);
  new_drone->battery_level = battery_level;
  new_drone->x = x;
  new_drone->y = y;
  new_drone->z = z;
  new_drone->next = drone_list;
  drone_list = new_drone;
}

void fly_drone(char* name, double dx, double dy, double dz) {
  Drone* current_drone = drone_list;
  while (current_drone) {
    if (strcmp(current_drone->name, name) == 0) {
      current_drone->x += dx;
      current_drone->y += dy;
      current_drone->z += dz;
      printf("Drone %s is flying to (%f, %f, %f).\n", name, current_drone->x, current_drone->y, current_drone->z);
      return;
    }
    current_drone = current_drone->next;
  }

  printf("Drone %s not found.\n", name);
}

int main() {
  add_drone("Foo", 100, 0, 0, 0);
  add_drone("Bar", 80, 10, 0, 0);
  add_drone("Baz", 60, 20, 0, 0);

  fly_drone("Foo", 5, 3, 2);
  fly_drone("Bar", -2, 1, 4);
  fly_drone("Non-existent", 1, 2, 3);

  return 0;
}