//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int health;
  struct Ghost *next;
} Ghost;

Ghost *createGhost(char *name, int room_num, int health) {
  Ghost *ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->room_num = room_num;
  ghost->health = health;
  ghost->next = NULL;
  return ghost;
}

void hauntHouse(Ghost *ghosts) {
  for (Ghost *ghost = ghosts; ghost; ghost = ghost->next) {
    printf("%s has entered the room!\n", ghost->name);
    switch (ghost->room_num) {
      case 1:
        printf("They are in the living room.\n");
        break;
      case 2:
        printf("They are in the kitchen.\n");
        break;
      case 3:
        printf("They are in the bedroom.\n");
        break;
      default:
        printf("They are in an unknown room.\n");
        break;
    }
    printf("Their health is at %d%.\n", ghost->health);
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Ghost *ghosts = createGhost("Alice", 1, 100);
  ghosts = createGhost("Bob", 2, 80);
  ghosts = createGhost("Charlie", 3, 60);
  ghosts = createGhost("Dave", 1, 40);
  ghosts = createGhost("Eve", 2, 20);

  hauntHouse(ghosts);

  return 0;
}