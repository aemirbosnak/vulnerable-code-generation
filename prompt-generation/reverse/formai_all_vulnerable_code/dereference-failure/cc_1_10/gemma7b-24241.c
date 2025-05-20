//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int room;
  int state;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room, int state) {
  Ghost* ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->room = room;
  ghost->state = state;
  ghost->next = NULL;
  return ghost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
  if (head == NULL) {
    head = newGhost;
  } else {
    head->next = newGhost;
    head = newGhost;
  }
}

void haunt(Ghost* head) {
  while (head) {
    printf("%s is haunting the %dth room...\n", head->name, head->room);
    switch (head->state) {
      case 0:
        printf("They are slumbering.\n");
        break;
      case 1:
        printf("They are roaming.\n");
        break;
      case 2:
        printf("They are plotting.\n");
        break;
      default:
        printf("They are unknown.\n");
        break;
    }
    head = head->next;
  }
}

int main() {
  srand(time(NULL));
  Ghost* head = createGhost("Mr. Bartholomew", 1, 1);
  addGhost(head, createGhost("Miss Amelia", 2, 0));
  addGhost(head, createGhost("Mr. Edward", 3, 2));
  haunt(head);
  return 0;
}