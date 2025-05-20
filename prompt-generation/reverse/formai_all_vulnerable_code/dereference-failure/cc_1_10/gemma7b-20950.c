//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
  char name[20];
  int x;
  int y;
  struct waypoint* next;
} waypoint;

 waypoint* createWaypoints() {
  waypoint* head = malloc(sizeof(waypoint));
  head->name[0] = '\0';
  head->x = 0;
  head->y = 0;
  head->next = NULL;
  return head;
}

void addWaypoints(waypoint* head, char* name, int x, int y) {
  waypoint* newWaypoint = malloc(sizeof(waypoint));
  newWaypoint->name[0] = '\0';
  strcpy(newWaypoint->name, name);
  newWaypoint->x = x;
  newWaypoint->y = y;
  newWaypoint->next = NULL;

  if (head->next == NULL) {
    head->next = newWaypoint;
  } else {
    waypoint* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newWaypoint;
  }
}

void printWaypoints(waypoint* head) {
  waypoint* current = head;
  while (current) {
    printf("%s (%d, %d)\n", current->name, current->x, current->y);
    current = current->next;
  }
}

int main() {
  waypoint* head = createWaypoints();
  addWaypoints(head, "Home", 10, 10);
  addWaypoints(head, "School", 20, 20);
  addWaypoints(head, "Work", 30, 30);

  printWaypoints(head);

  return 0;
}