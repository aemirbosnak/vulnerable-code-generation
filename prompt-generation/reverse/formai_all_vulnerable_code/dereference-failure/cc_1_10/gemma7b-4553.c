//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOULS 10

typedef struct Ghost {
  char name[20];
  int room_num;
  int scare_factor;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room_num, int scare_factor) {
  Ghost* ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->room_num = room_num;
  ghost->scare_factor = scare_factor;
  ghost->next = NULL;
  return ghost;
}

void scare(Ghost* ghost) {
  srand(time(NULL));
  int scare_level = rand() % ghost->scare_factor + 1;
  switch (scare_level) {
    case 1:
      printf("%s whispers your name in your ear...\n", ghost->name);
      break;
    case 2:
      printf("%s throws a feather at you...\n", ghost->name);
      break;
    case 3:
      printf("%s grabs you and drags you down the hall...\n", ghost->name);
      break;
  }
}

int main() {
  Ghost* head = createGhost("The Bloody Bride", 3, 5);
  createGhost("The Ragged Corpse", 5, 3);
  createGhost("The Disembodied Hand", 7, 2);

  while (1) {
    printf("Enter a room number: ");
    int room_num;
    scanf("%d", &room_num);

    Ghost* current_ghost = head;
    while (current_ghost) {
      if (current_ghost->room_num == room_num) {
        scare(current_ghost);
        break;
      }
      current_ghost = current_ghost->next;
    }

    if (current_ghost == NULL) {
      printf("No ghost found.\n");
    }
  }

  return 0;
}