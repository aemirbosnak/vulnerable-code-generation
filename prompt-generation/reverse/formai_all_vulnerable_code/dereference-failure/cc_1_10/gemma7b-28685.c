//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float haunt_rating) {
  Ghost* newGhost = malloc(sizeof(Ghost));
  strcpy(newGhost->name, name);
  newGhost->age = age;
  newGhost->haunt_rating = haunt_rating;
  newGhost->next = NULL;
  return newGhost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
  if (head == NULL) {
    head = newGhost;
  } else {
    newGhost->next = head;
    head = newGhost;
  }
}

void haunt(Ghost* head) {
  while (head) {
    printf("%s is haunting you!\n", head->name);
    sleep(head->haunt_rating);
    head = head->next;
  }
}

int main() {
  srand(time(NULL));

  Ghost* head = NULL;
  for (int i = 0; i < MAX_GHOULS; i++) {
    addGhost(head, createGhost("Ghost", rand() % 100, rand() % 5));
  }

  haunt(head);

  return 0;
}