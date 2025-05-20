//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WAYPOINTS 10
#define WAYPOINT_NAME_LENGTH 20

typedef struct Waypoint {
  char name[WAYPOINT_NAME_LENGTH];
  int x;
  int y;
  struct Waypoint* next;
} Waypoint;

void add_waypoint(Waypoint** head, char* name, int x, int y) {
  Waypoint* new_waypoint = malloc(sizeof(Waypoint));
  strcpy(new_waypoint->name, name);
  new_waypoint->x = x;
  new_waypoint->y = y;
  new_waypoint->next = NULL;

  if (*head == NULL) {
    *head = new_waypoint;
  } else {
    (*head)->next = new_waypoint;
  }
}

void navigate(Waypoint* head) {
  time_t start_time = time(NULL);
  int current_x = 0;
  int current_y = 0;
  int destination_x = head->x;
  int destination_y = head->y;

  while (current_x != destination_x || current_y != destination_y) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        current_x++;
        break;
      case 1:
        current_y++;
        break;
      case 2:
        current_x--;
        break;
      case 3:
        current_y--;
        break;
    }

    printf("Current position: (%d, %d)\n", current_x, current_y);
    sleep(1);
  }

  time_t end_time = time(NULL);
  printf("Time taken: %ld seconds\n", end_time - start_time);
}

int main() {
  Waypoint* head = NULL;
  add_waypoint(&head, "Start", 0, 0);
  add_waypoint(&head, "Destination", 10, 10);

  navigate(head);

  return 0;
}