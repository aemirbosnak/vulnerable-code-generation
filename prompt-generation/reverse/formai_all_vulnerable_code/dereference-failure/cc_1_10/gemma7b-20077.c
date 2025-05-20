//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  struct Ghost* next;
} Ghost;

void add_ghost(Ghost** head, char* name, int age, float haunt_rating) {
  Ghost* new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->age = age;
  new_ghost->haunt_rating = haunt_rating;
  new_ghost->next = NULL;

  if (*head == NULL) {
    *head = new_ghost;
  } else {
    (*head)->next = new_ghost;
  }
}

void haunt_house(Ghost* head) {
  while (head) {
    printf("The ghostly voice of %s whispers secrets...\n", head->name);
    printf("You hear the chilling sound of %s's footsteps...\n", head->name);
    printf("A cold wind blows through the halls, carrying the scent of %s...\n", head->name);
    printf("Fear the presence of %s, a master of the macabre...\n", head->name);

    head = head->next;
  }
}

int main() {
  Ghost* head = NULL;

  add_ghost(&head, "Annabelle", 24, 4.8);
  add_ghost(&head, "The Babbling Ghost", 12, 3.2);
  add_ghost(&head, "The Crimson Countess", 42, 5.1);
  add_ghost(&head, "The Dancing Phantom", 18, 4.2);
  add_ghost(&head, "The spectral Bride", 22, 4.4);

  haunt_house(head);

  return 0;
}