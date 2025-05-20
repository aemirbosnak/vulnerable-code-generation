//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GORE 20
#define MAX_SOUND 10
#define MAX_MOVEMENT 5

typedef struct Ghost {
  char name[20];
  int sound, movement, gore;
  struct Ghost *next;
} Ghost;

Ghost *head = NULL;

void addGhost(char *name, int sound, int movement, int gore) {
  Ghost *newGhost = malloc(sizeof(Ghost));
  strcpy(newGhost->name, name);
  newGhost->sound = sound;
  newGhost->movement = movement;
  newGhost->gore = gore;
  newGhost->next = head;
  head = newGhost;
}

void haunt(int seconds) {
  time_t start = time(NULL);
  while (time(NULL) - start < seconds) {
    Ghost *ghost = head;
    while (ghost) {
      switch (ghost->movement) {
        case 0:
          printf("%s whispers secrets...\n", ghost->name);
          break;
        case 1:
          printf("%s creeps slowly...\n", ghost->name);
          break;
        case 2:
          printf("%s dashes frantically...\n", ghost->name);
          break;
      }
      switch (ghost->sound) {
        case 0:
          printf("%s's voice echoes...\n", ghost->name);
          break;
        case 1:
          printf("%s's footsteps crunch...\n", ghost->name);
          break;
        case 2:
          printf("%s's scream screams...\n", ghost->name);
          break;
      }
      switch (ghost->gore) {
        case 0:
          printf("%s's blood drips...\n", ghost->name);
          break;
        case 1:
          printf("%s's skin peels...\n", ghost->name);
          break;
        case 2:
          printf("%s's bones crack...\n", ghost->name);
          break;
      }
    }
  }
}

int main() {
  addGhost("The Phantom", 2, 1, 0);
  addGhost("The Blood Countess", 1, 0, 1);
  addGhost("The Screaming Mummy", 0, 2, 2);

  haunt(60);

  return 0;
}