//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  int location_x;
  int location_y;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float haunt_rating, int location_x, int location_y) {
  Ghost* ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->age = age;
  ghost->haunt_rating = haunt_rating;
  ghost->location_x = location_x;
  ghost->location_y = location_y;
  ghost->next = NULL;
  return ghost;
}

void addGhost(Ghost* head, char* name, int age, float haunt_rating, int location_x, int location_y) {
  Ghost* newGhost = createGhost(name, age, haunt_rating, location_x, location_y);
  if (head == NULL) {
    head = newGhost;
  } else {
    newGhost->next = head;
    head = newGhost;
  }
}

void haunt(Ghost* head) {
  while (head) {
    printf("%s has appeared! Prepare for a fright...\n", head->name);
    sleep(rand() % 5);
    printf("The spirit of %s has vanished.\n", head->name);
    sleep(rand() % 5);
  }
}

int main() {
  srand(time(NULL));
  Ghost* head = NULL;

  addGhost(head, "Mary", 25, 4.8, 10, 15);
  addGhost(head, "John", 30, 3.2, 12, 20);
  addGhost(head, "Alice", 20, 2.5, 14, 10);
  addGhost(head, "Bob", 40, 4.2, 16, 12);
  addGhost(head, "Tom", 35, 3.6, 18, 22);

  haunt(head);

  return 0;
}