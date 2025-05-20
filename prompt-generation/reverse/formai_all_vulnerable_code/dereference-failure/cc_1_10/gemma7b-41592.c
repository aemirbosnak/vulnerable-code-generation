//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct Ship {
  char name[MAX_SIZE];
  int size;
  int crew;
  double x;
  double y;
  double z;
  double heading;
  double speed;
  struct Ship* next;
} Ship;

void create_ship(Ship** head, char* name, int size, int crew) {
  Ship* new_ship = malloc(sizeof(Ship));
  strcpy(new_ship->name, name);
  new_ship->size = size;
  new_ship->crew = crew;
  new_ship->x = 0.0;
  new_ship->y = 0.0;
  new_ship->z = 0.0;
  new_ship->heading = 0.0;
  new_ship->speed = 0.0;
  new_ship->next = NULL;

  if (*head == NULL) {
    *head = new_ship;
  } else {
    ((*head)->next = new_ship);
    *head = new_ship;
  }
}

void print_ship(Ship* ship) {
  printf("Name: %s\n", ship->name);
  printf("Size: %d\n", ship->size);
  printf("Crew: %d\n", ship->crew);
  printf("Position: (%f, %f, %f)\n", ship->x, ship->y, ship->z);
  printf("Heading: %.2f\n", ship->heading);
  printf("Speed: %.2f\n", ship->speed);
  printf("\n");
}

int main() {
  Ship* head = NULL;

  create_ship(&head, "The Enterprise", 100, 10);
  create_ship(&head, "The Hobbit", 50, 5);
  create_ship(&head, "The Millenium Falcon", 25, 2);

  print_ship(head);

  return 0;
}