//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GORE 20

typedef struct Ghost Ghost;

struct Ghost {
  char name[20];
  int type;
  float x, y, z;
  int health;
  Ghost* next;
};

void spawnGhost(Ghost** head) {
  time_t t = time(NULL);
  srand(t);

  Ghost* newGhost = malloc(sizeof(Ghost));
  newGhost->name[0] = '\0';
  newGhost->type = rand() % MAX_GORE;
  newGhost->x = rand() % 1000;
  newGhost->y = rand() % 1000;
  newGhost->z = rand() % 1000;
  newGhost->health = 100;
  newGhost->next = NULL;

  if (*head == NULL) {
    *head = newGhost;
  } else {
    (*head)->next = newGhost;
  }
}

void hauntHouse(Ghost** head) {
  Ghost* currentGhost = *head;

  while (currentGhost) {
    printf("Ghost: %s\n", currentGhost->name);
    printf("Type: %d\n", currentGhost->type);
    printf("Location: (%d, %d, %d)\n", currentGhost->x, currentGhost->y, currentGhost->z);
    printf("Health: %d\n", currentGhost->health);
    printf("\n");

    currentGhost = currentGhost->next;
  }
}

int main() {
  Ghost* head = NULL;

  spawnGhost(&head);
  spawnGhost(&head);
  spawnGhost(&head);

  hauntHouse(&head);

  return 0;
}