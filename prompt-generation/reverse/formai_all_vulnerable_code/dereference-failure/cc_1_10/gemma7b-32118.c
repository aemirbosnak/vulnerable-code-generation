//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int presence;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int presence) {
  Ghost* new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->room_num = room_num;
  new_ghost->presence = presence;
  new_ghost->next = NULL;
  return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room_num, int presence) {
  Ghost* new_ghost = create_ghost(name, room_num, presence);
  if (head == NULL) {
    head = new_ghost;
  } else {
    head->next = new_ghost;
  }
}

void scare(Ghost* head) {
  srand(time(NULL));
  for (head = head; head; head = head->next) {
    if (head->presence && rand() % MAX_GHOULS == 0) {
      printf("%s has appeared in room %d!\n", head->name, head->room_num);
    }
  }
}

int main() {
  Ghost* head = NULL;
  add_ghost(head, "Jack", 1, 1);
  add_ghost(head, "Mary", 2, 1);
  add_ghost(head, "Bob", 3, 0);
  add_ghost(head, "Alice", 4, 1);

  scare(head);

  return 0;
}