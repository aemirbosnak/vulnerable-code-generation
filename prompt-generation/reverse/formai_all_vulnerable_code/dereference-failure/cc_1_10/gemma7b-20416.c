//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

struct Ghost {
  char name[20];
  int room;
  int type;
  int active;
  struct Ghost* next;
};

void createGhost(struct Ghost** head) {
  struct Ghost* newGhost = malloc(sizeof(struct Ghost));
  newGhost->active = 1;
  newGhost->next = NULL;

  // Set ghost name, room and type
  sprintf(newGhost->name, "Ghost %d", rand() % MAX_GHOULS);
  newGhost->room = rand() % 10;
  newGhost->type = rand() % 3;

  if (*head == NULL) {
    *head = newGhost;
  } else {
    (*head)->next = newGhost;
  }
}

void hauntHouse(struct Ghost* head) {
  while (head) {
    // Ghost moves around the house
    head->room = rand() % 10;

    // Ghost interacts with the player
    switch (head->type) {
      case 0:
        printf("You hear a whisper in your ear.\n");
        break;
      case 1:
        printf("You see a ghostly figure moving towards you.\n");
        break;
      case 2:
        printf("You smell a faint burning odor.\n");
        break;
    }

    head = head->next;
  }
}

int main() {
  struct Ghost* head = NULL;

  // Create a number of ghosts
  for (int i = 0; i < 10; i++) {
    createGhost(&head);
  }

  // Haunt the house
  hauntHouse(head);

  return 0;
}