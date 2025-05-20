//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int age, float haunt_rating) {
  Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->age = age;
  ghost->haunt_rating = haunt_rating;
  ghost->next = NULL;
  return ghost;
}

void add_ghost(Ghost* head, char* name, int age, float haunt_rating) {
  Ghost* new_ghost = create_ghost(name, age, haunt_rating);
  if (head == NULL) {
    head = new_ghost;
  } else {
    head->next = new_ghost;
  }
}

void scare(Ghost* ghost) {
  printf("%s has appeared! Prepare for a scare...\n", ghost->name);
  switch (ghost->age) {
    case 18:
      printf("Boo!\n");
      break;
    case 21:
      printf("Get out of here!\n");
      break;
    default:
      printf("Run away!\n");
  }
}

int main() {
  srand(time(NULL));
  Ghost* head = NULL;
  add_ghost(head, "Mary", 20, 8.5);
  add_ghost(head, "Jack", 18, 7.2);
  add_ghost(head, "Alice", 19, 9.0);

  scare(head->next);
  scare(head);

  return 0;
}