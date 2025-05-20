//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int scare_factor;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int scare_factor) {
  Ghost* new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->room_num = room_num;
  new_ghost->scare_factor = scare_factor;
  new_ghost->next = NULL;
  return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room_num, int scare_factor) {
  Ghost* new_ghost = create_ghost(name, room_num, scare_factor);
  if (head == NULL) {
    head = new_ghost;
  } else {
    new_ghost->next = head;
    head = new_ghost;
  }
}

int main() {
  srand(time(NULL));

  Ghost* head = NULL;
  add_ghost(head, "Mr. Jones", 1, 8);
  add_ghost(head, "Ms. Smith", 2, 6);
  add_ghost(head, "Mr. Brown", 3, 7);
  add_ghost(head, "Mrs. Green", 4, 5);
  add_ghost(head, "The Phantom", 5, 10);

  int room_num = rand() % 5 + 1;

  Ghost* current_ghost = head;
  while (current_ghost) {
    if (current_ghost->room_num == room_num) {
      printf("Boo! You have encountered %s!\n", current_ghost->name);
      printf("Scare factor: %d\n", current_ghost->scare_factor);
      break;
    }
    current_ghost = current_ghost->next;
  }

  if (current_ghost == NULL) {
    printf("No ghosts found in that room.\n");
  }

  return 0;
}