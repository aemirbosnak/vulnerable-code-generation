//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  struct Ghost *next;
} Ghost;

Ghost *ghost_list = NULL;

void add_ghost(char *name, int age, float haunt_rating) {
  Ghost *new_ghost = (Ghost *)malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->age = age;
  new_ghost->haunt_rating = haunt_rating;
  new_ghost->next = NULL;

  if (ghost_list == NULL) {
    ghost_list = new_ghost;
  } else {
    Ghost *temp = ghost_list;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_ghost;
  }
}

void haunt_house() {
  time_t t;
  int i;
  for (t = 0; t < 3; t++) {
    for (i = 0; i < MAX_GHOSTS; i++) {
      Ghost *ghost = ghost_list;
      while (ghost) {
        printf("%s has been spotted! (Haunt Rating: %.2f)\n", ghost->name, ghost->haunt_rating);
        ghost = ghost->next;
      }
      sleep(1);
    }
  }
}

int main() {
  add_ghost("Mr. Jones", 25, 8.5);
  add_ghost("Ms. Smith", 30, 7.2);
  add_ghost("Mr. Brown", 40, 9.0);
  add_ghost("Mrs. Green", 50, 6.8);
  add_ghost("Mr. White", 60, 8.2);

  haunt_house();

  return 0;
}