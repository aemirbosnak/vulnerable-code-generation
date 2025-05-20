//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
  char name[20];
  int x, y;
  struct waypoint* next;
} waypoint;

waypoint* createWaypoints(void) {
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
  newWaypoint->x = x;
  newWaypoint->y = y;
  newWaypoint->next = NULL;

  if (head->next == NULL) {
    head->next = newWaypoint;
  } else {
    head->next->next = newWaypoint;
  }
}

void printWaypoints(waypoint* head) {
  waypoint* current = head->next;
  while (current) {
    printf("%s (%d, %d)\n", current->name, current->x, current->y);
    current = current->next;
  }
}

int main() {
  waypoint* head = createWaypoints();
  addWaypoints(head, "Home", 10, 10);
  addWaypoints(head, "Work", 20, 20);
  addWaypoints(head, "School", 30, 30);

  printWaypoints(head);

  return 0;
}