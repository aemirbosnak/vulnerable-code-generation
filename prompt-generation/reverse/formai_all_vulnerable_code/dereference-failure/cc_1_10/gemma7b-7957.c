//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

struct Ghost {
  char name[20];
  int room;
  int haunt_frequency;
  int scare_factor;
  struct Ghost *next;
};

struct Ghost *ghost_list = NULL;

void add_ghost(char *name, int room, int haunt_frequency, int scare_factor) {
  struct Ghost *new_ghost = (struct Ghost *)malloc(sizeof(struct Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->room = room;
  new_ghost->haunt_frequency = haunt_frequency;
  new_ghost->scare_factor = scare_factor;
  new_ghost->next = NULL;

  if (ghost_list == NULL) {
    ghost_list = new_ghost;
  } else {
    struct Ghost *current = ghost_list;
    while (current->next) {
      current = current->next;
    }
    current->next = new_ghost;
  }
}

void scare_ghost(struct Ghost *ghost) {
  int i = 0;
  for (i = 0; i < ghost->haunt_frequency; i++) {
    printf("%s has appeared and is scaring you!\n", ghost->name);
    sleep(ghost->scare_factor);
  }
}

int main() {
  srand(time(NULL));

  add_ghost("Mr. Jones", 1, 3, 5);
  add_ghost("Ms. Smith", 2, 2, 4);
  add_ghost("The Bloody Bride", 3, 4, 6);

  struct Ghost *current = ghost_list;
  while (current) {
    scare_ghost(current);
    current = current->next;
  }

  return 0;
}