//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int is_active;
  struct Ghost *next;
} Ghost;

Ghost *create_ghost(char *name, int room_num) {
  Ghost *ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->room_num = room_num;
  ghost->is_active = 1;
  ghost->next = NULL;
  return ghost;
}

void add_ghost(Ghost **head, char *name, int room_num) {
  Ghost *new_ghost = create_ghost(name, room_num);
  if (*head == NULL) {
    *head = new_ghost;
  } else {
    (*head)->next = new_ghost;
  }
}

void haunt_house(Ghost *head) {
  while (head) {
    int room_num = head->room_num;
    if (head->is_active) {
      printf("The ghostly presence of %s has been detected in room %d.\n", head->name, room_num);
    }
    head = head->next;
  }
}

int main() {
  srand(time(NULL));
  Ghost *head = NULL;

  // Create a few ghosts
  add_ghost(&head, "Mr. Jones", 1);
  add_ghost(&head, "Mrs. Smith", 2);
  add_ghost(&head, "Mr. Brown", 3);
  add_ghost(&head, "Ms. Green", 4);
  add_ghost(&head, "Mr. Gray", 5);

  // Haunt the house
  haunt_house(head);

  return 0;
}