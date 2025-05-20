//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GHOST_NUM 10

typedef struct Ghost {
  char name[20];
  int id;
  float x, y, z;
  struct Ghost *next;
} Ghost;

Ghost *head = NULL;

void addGhost(char *name, int id, float x, float y, float z) {
  Ghost *newGhost = (Ghost *)malloc(sizeof(Ghost));
  strcpy(newGhost->name, name);
  newGhost->id = id;
  newGhost->x = x;
  newGhost->y = y;
  newGhost->z = z;
  newGhost->next = NULL;

  if (head == NULL) {
    head = newGhost;
  } else {
    head->next = newGhost;
  }
}

void interactGhost(int ghostId) {
  Ghost *currentGhost = head;

  while (currentGhost) {
    if (currentGhost->id == ghostId) {
      printf("You see %s's ghostly glow.\n", currentGhost->name);
      printf("What do you want to do? (say, interact, leave): ");
      char input[20];
      scanf("%s", input);

      if (strcmp(input, "say") == 0) {
        printf("What do you want to say to %s? ", currentGhost->name);
        char message[200];
        scanf("%s", message);
        printf("%s says: %s\n", currentGhost->name, message);
      } else if (strcmp(input, "interact") == 0) {
        printf("What do you want to interact with? (e.g. hair, clothes, etc.) ");
        char interaction[20];
        scanf("%s", interaction);
        printf("You interact with %s's %s.\n", currentGhost->name, interaction);
      } else if (strcmp(input, "leave") == 0) {
        printf("You leave the haunted house.\n");
        exit(0);
      } else {
        printf("Invalid input.\n");
      }

      break;
    }

    currentGhost = currentGhost->next;
  }

  if (currentGhost == NULL) {
    printf("Ghost not found.\n");
  }
}

int main() {
  addGhost("Mr. Jones", 1, 0.0f, 0.0f, 0.0f);
  addGhost("Miss Smith", 2, 1.0f, 0.0f, 0.0f);
  addGhost("The Bloody Bride", 3, 0.0f, 1.0f, 0.0f);

  interactGhost(1);

  return 0;
}