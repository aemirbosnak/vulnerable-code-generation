//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

struct Ghost {
  char name[20];
  int age;
  float haunt_score;
  struct Ghost *next;
};

typedef struct Ghost Ghost;

void initialize_ghost_list(Ghost **head) {
  *head = NULL;
}

void add_ghost(Ghost **head, char name, int age, float haunt_score) {
  Ghost *new_ghost = malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->age = age;
  new_ghost->haunt_score = haunt_score;
  new_ghost->next = NULL;

  if (*head == NULL) {
    *head = new_ghost;
  } else {
    (*head)->next = new_ghost;
  }
}

void haunt_house(Ghost *head) {
  while (head) {
    printf("%s has arrived, saying: ", head->name);
    switch (rand() % 3) {
      case 0:
        printf("Boo!\n");
        break;
      case 1:
        printf("You're a mess! Get out of here!\n");
        break;
      case 2:
        printf("I'm coming for you!\n");
        break;
    }
    head = head->next;
  }
}

int main() {
  Ghost *head = NULL;
  initialize_ghost_list(&head);

  add_ghost(head, "Billy Bob", 20, 8.5);
  add_ghost(head, "Mary Sue", 18, 7.2);
  add_ghost(head, "Jack the Ripper", 30, 9.1);

  haunt_house(head);

  return 0;
}