//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
  char name[20];
  int room;
  int state;
  struct Ghost *next;
} Ghost;

Ghost *ghost_head = NULL;

void add_ghost(char *name, int room, int state) {
  Ghost *new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->room = room;
  new_ghost->state = state;
  new_ghost->next = NULL;

  if (ghost_head == NULL) {
    ghost_head = new_ghost;
  } else {
    Ghost *temp = ghost_head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_ghost;
  }
}

void haunt(int room) {
  Ghost *current = ghost_head;
  while (current) {
    if (current->room == room) {
      switch (current->state) {
        case 0:
          printf("You hear a soft whisper in the hallway.\n");
          break;
        case 1:
          printf("A cold wind blows through the halls, extinguishing your candle.\n");
          break;
        case 2:
          printf("A ghostly figure appears before you, its eyes burning with rage.\n");
          break;
      }
    }
    current = current->next;
  }
}

int main() {
  srand(time(NULL));

  add_ghost("The Bloody Countess", 1, 2);
  add_ghost("The Whispering Ghost", 3, 0);
  add_ghost("The Cold Wind Ghost", 4, 1);

  haunt(2);

  return 0;
}