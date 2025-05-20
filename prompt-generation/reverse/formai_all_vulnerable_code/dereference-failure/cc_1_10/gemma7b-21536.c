//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
  char name[20];
  int room;
  int health;
  int is_active;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].name[0] = '\0';
    ghosts[i].room = -1;
    ghosts[i].health = 100;
    ghosts[i].is_active = 0;
  }
}

void scareGhost(Ghost *ghost) {
  if (ghost->health > 0) {
    ghost->health -= 10;
    printf("You scared %s! They ran away!\n", ghost->name);
  } else {
    printf("You killed %s!\n", ghost->name);
  }
}

int main() {
  initializeGhosts();

  srand(time(NULL));

  for (int i = 0; i < MAX_GHOULS; i++) {
    ghosts[i].name[0] = 'A' + i;
    ghosts[i].room = rand() % 5;
    ghosts[i].is_active = 1;
  }

  printf("Welcome to the Haunted House of Doom!\n");
  printf("------------------------\n");

  for (int i = 0; i < MAX_GHOULS; i++) {
    if (ghosts[i].is_active) {
      printf("Ghost %s is lurking in room %d.\n", ghosts[i].name, ghosts[i].room);
    }
  }

  printf("\nPlease choose a room number: ");
  int room_number = atoi(fgets(NULL, 10, stdin));

  for (int i = 0; i < MAX_GHOULS; i++) {
    if (ghosts[i].is_active && ghosts[i].room == room_number) {
      scareGhost(&ghosts[i]);
    }
  }

  printf("Thank you for visiting the Haunted House of Doom!\n");
  return 0;
}