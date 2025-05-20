//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

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

void addGhost(Ghost* head, char* name, int room, int state) {
  Ghost* newGhost = createGhost(name, room, state);
  if (head == NULL) {
    head = newGhost;
  } else {
    head->next = newGhost;
  }
}

void hauntHouse(Ghost* head) {
  time_t t = time(NULL);
  int i = 0;
  for (i = 0; i < MAX_GHOULS; i++) {
    sleep(t);
    t = time(NULL);
    Ghost* currentGhost = head;
    while (currentGhost) {
      switch (currentGhost->state) {
        case 0:
          printf("%s has awakened and is roaming the halls.\n", currentGhost->name);
          break;
        case 1:
          printf("%s is whispering secrets in your ear.\n", currentGhost->name);
          break;
        case 2:
          printf("%s is approaching you with a menacing grin.\n", currentGhost->name);
          break;
        case 3:
          printf("%s has vanished!\n", currentGhost->name);
          break;
      }
      currentGhost = currentGhost->next;
    }
  }
}

int main() {
  Ghost* head = NULL;
  addGhost(head, "Jack", 1, 0);
  addGhost(head, "Mary", 2, 1);
  addGhost(head, "Bob", 3, 2);
  addGhost(head, "Alice", 4, 3);

  hauntHouse(head);

  return 0;
}