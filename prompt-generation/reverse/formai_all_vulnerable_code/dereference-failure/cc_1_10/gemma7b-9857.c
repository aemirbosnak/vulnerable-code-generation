//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
  char name[20];
  int room_num;
  int type;
  struct Ghost *next;
} Ghost;

Ghost *create_ghost(char *name, int room_num, int type) {
  Ghost *ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->room_num = room_num;
  ghost->type = type;
  ghost->next = NULL;
  return ghost;
}

void add_ghost(Ghost *head, char *name, int room_num, int type) {
  Ghost *new_ghost = create_ghost(name, room_num, type);
  if (head == NULL) {
    head = new_ghost;
  } else {
    new_ghost->next = head;
    head = new_ghost;
  }
}

int main() {
  srand(time(NULL));
  Ghost *head = NULL;

  // Create a list of ghosts
  add_ghost(head, "John Doe", 1, 1);
  add_ghost(head, "Jane Doe", 2, 2);
  add_ghost(head, "Billy Bob", 3, 1);
  add_ghost(head, "Mary Smith", 4, 2);

  // Traverse the list of ghosts
  Ghost *current_ghost = head;
  while (current_ghost) {
    printf("Name: %s\n", current_ghost->name);
    printf("Room Number: %d\n", current_ghost->room_num);
    printf("Type: %d\n", current_ghost->type);
    printf("\n");
    current_ghost = current_ghost->next;
  }

  return 0;
}