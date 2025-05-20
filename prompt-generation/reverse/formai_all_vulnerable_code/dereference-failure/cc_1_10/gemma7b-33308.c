//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_level;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float haunt_level) {
  Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->age = age;
  ghost->haunt_level = haunt_level;
  ghost->next = NULL;
  return ghost;
}

void addGhost(Ghost* head, char* name, int age, float haunt_level) {
  Ghost* newGhost = createGhost(name, age, haunt_level);
  if (head == NULL) {
    head = newGhost;
  } else {
    head->next = newGhost;
  }
}

void haunt(Ghost* head) {
  while (head) {
    printf("%s whispers: ", head->name);
    switch (head->age) {
      case 1:
        printf("I have a sweet dream of... the past.\n");
        break;
      case 2:
        printf("I am lonely. Come chat with me.\n");
        break;
      case 3:
        printf("I am angry. Get out of my house.\n");
        break;
      default:
        printf("I have nothing to say.\n");
    }
    head = head->next;
  }
}

int main() {
  srand(time(NULL));
  Ghost* head = NULL;
  addGhost(head, "John", 2, 0.8);
  addGhost(head, "Mary", 1, 0.6);
  addGhost(head, "Bob", 3, 0.9);
  addGhost(head, "Alice", 2, 0.7);
  addGhost(head, "Tom", 1, 0.5);

  haunt(head);

  return 0;
}