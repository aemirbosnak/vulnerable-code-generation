//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
  char name[20];
  int age;
  float fear_factor;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float fear_factor) {
  Ghost* ghost = malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->age = age;
  ghost->fear_factor = fear_factor;
  ghost->next = NULL;
  return ghost;
}

void addGhost(Ghost* head, char* name, int age, float fear_factor) {
  Ghost* newGhost = createGhost(name, age, fear_factor);
  if (head == NULL) {
    head = newGhost;
  } else {
    head->next = newGhost;
  }
}

int main() {
  srand(time(NULL));

  Ghost* head = NULL;
  addGhost(head, "Alice", 20, 8.5);
  addGhost(head, "Bob", 30, 7.2);
  addGhost(head, "Charlie", 40, 9.0);

  // Spook the guests
  for (int i = 0; i < MAX_GHOSTS; i++) {
    Ghost* ghost = head;
    while (ghost) {
      printf("%s is screaming!\n", ghost->name);
      sleep(rand() % 2);
      ghost = ghost->next;
    }
  }

  return 0;
}