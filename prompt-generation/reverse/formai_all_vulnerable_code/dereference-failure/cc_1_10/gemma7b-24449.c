//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
  char name[20];
  int x;
  int y;
  struct waypoint* next;
} waypoint;

waypoint* waypoint_list = NULL;

void add_waypoint(char* name, int x, int y) {
  waypoint* new_waypoint = (waypoint*)malloc(sizeof(waypoint));
  strcpy(new_waypoint->name, name);
  new_waypoint->x = x;
  new_waypoint->y = y;
  new_waypoint->next = waypoint_list;
  waypoint_list = new_waypoint;
}

void find_nearest_waypoint(int x, int y) {
  waypoint* current_waypoint = waypoint_list;
  int min_distance = 1000000;
  char* nearest_waypoint_name = NULL;

  while (current_waypoint) {
    int distance = abs(current_waypoint->x - x) + abs(current_waypoint->y - y);
    if (distance < min_distance) {
      min_distance = distance;
      nearest_waypoint_name = current_waypoint->name;
    }
    current_waypoint = current_waypoint->next;
  }

  if (nearest_waypoint_name) {
    printf("The nearest waypoint is: %s\n", nearest_waypoint_name);
  } else {
    printf("No waypoints found.\n");
  }
}

int main() {
  add_waypoint("Home", 10, 10);
  add_waypoint("Work", 20, 20);
  add_waypoint("School", 30, 30);

  find_nearest_waypoint(15, 15);

  return 0;
}