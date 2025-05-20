//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
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

 waypoint* createWaypoints(int numWaypoints) {
  waypoint* head = NULL;
  for (int i = 0; i < numWaypoints; i++) {
    waypoint* newWaypoint = malloc(sizeof(waypoint));
    newWaypoint->name[0] = '\0';
    newWaypoint->x = 0;
    newWaypoint->y = 0;
    newWaypoint->next = head;
    head = newWaypoint;
  }
  return head;
}

void simulateNavigation(waypoint* waypoints) {
  time_t start = time(NULL);
  int currentX = waypoints->x;
  int currentY = waypoints->y;
  printf("Current position: (%d, %d)\n", currentX, currentY);
  while (time(NULL) - start < 10) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        currentX++;
        break;
      case 1:
        currentY++;
        break;
      case 2:
        currentX--;
        break;
      case 3:
        currentY--;
        break;
    }
    printf("New position: (%d, %d)\n", currentX, currentY);
    sleep(1);
  }
}

int main() {
  waypoint* waypoints = createWaypoints(MAX_WAYPOINTS);
  simulateNavigation(waypoints);
  return 0;
}