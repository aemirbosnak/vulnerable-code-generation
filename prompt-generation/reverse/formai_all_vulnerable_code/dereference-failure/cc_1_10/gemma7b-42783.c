//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_score;
  struct Ghost* next;
} Ghost;

Ghost* head = NULL;

void add_ghost(char* name, int age, float haunt_score) {
  Ghost* new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->age = age;
  new_ghost->haunt_score = haunt_score;
  new_ghost->next = NULL;

  if (head == NULL) {
    head = new_ghost;
  } else {
    head->next = new_ghost;
    head = new_ghost;
  }
}

void haunt_house() {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < MAX_GHOULS; i++) {
    Ghost* ghost = head;
    while (ghost) {
      int chance = rand() % 100;
      if (chance < ghost->haunt_score) {
        printf("%s has appeared!\n", ghost->name);
        printf("They are wandering the halls...\n");
      }
    }
  }
}

int main() {
  add_ghost("The Bloody Bride", 25, 80);
  add_ghost("The Screaming Child", 12, 70);
  add_ghost("The Hungry Ghost", 50, 60);

  haunt_house();

  return 0;
}