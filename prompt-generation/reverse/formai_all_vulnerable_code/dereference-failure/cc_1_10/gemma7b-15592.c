//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
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
  Ghost *new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->age = age;
  new_ghost->haunt_rating = haunt_rating;
  new_ghost->next = NULL;

  if (ghost_list) {
    ghost_list->next = new_ghost;
  } else {
    ghost_list = new_ghost;
  }
}

void haunt_house() {
  time_t t = time(NULL);
  int i = 0;
  Ghost *current_ghost = ghost_list;

  while (current_ghost) {
    if (rand() % 100 < current_ghost->haunt_rating) {
      printf("%s has appeared! Prepare for a fright...\n", current_ghost->name);
      switch (rand() % 3) {
        case 0:
          printf("It's a scream!\n");
          break;
        case 1:
          printf("Boo!\n");
          break;
        case 2:
          printf("Get out of there!\n");
          break;
      }
    }
    current_ghost = current_ghost->next;
  }

  printf("The ghosts have retreated. You are safe for now...\n");
}

int main() {
  add_ghost("Sarah", 22, 80.0);
  add_ghost("Jack", 30, 60.0);
  add_ghost("Mary", 18, 70.0);
  add_ghost("John", 40, 50.0);

  haunt_house();

  return 0;
}