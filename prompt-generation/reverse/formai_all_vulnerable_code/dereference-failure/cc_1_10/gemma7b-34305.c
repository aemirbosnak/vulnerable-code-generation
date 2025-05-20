//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WAYPOINTS 10

typedef struct waypoint {
  char name[20];
  int x, y;
  struct waypoint* next;
} waypoint;

waypoint* waypoint_create(char* name, int x, int y) {
  waypoint* wp = (waypoint*)malloc(sizeof(waypoint));
  strcpy(wp->name, name);
  wp->x = x;
  wp->y = y;
  wp->next = NULL;
  return wp;
}

void waypoint_add(waypoint* head, waypoint* new_wp) {
  if (head == NULL) {
    head = new_wp;
  } else {
    head->next = new_wp;
    head = new_wp;
  }
}

void navigation(waypoint* head) {
  waypoint* current = head;
  while (current) {
    printf("Current position: (%d, %d)\n", current->x, current->y);
    printf("Next waypoint: %s\n", current->next->name);
    current = current->next;
  }
}

int main() {
  waypoint* head = waypoint_create("Start", 0, 0);
  waypoint_add(head, waypoint_create("East", 10, 0));
  waypoint_add(head, waypoint_create("South", 10, -10));
  waypoint_add(head, waypoint_create("West", 0, -10));
  waypoint_add(head, waypoint_create("North", -10, 0));

  navigation(head);

  return 0;
}