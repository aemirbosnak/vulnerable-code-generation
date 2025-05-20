//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THEORIES 5

typedef struct theory {
  char *name;
  char *description;
  int evidence_points;
  struct theory *next;
} theory_t;

theory_t *create_theory(char *name, char *description, int evidence_points) {
  theory_t *new_theory = malloc(sizeof(theory_t));
  new_theory->name = strdup(name);
  new_theory->description = strdup(description);
  new_theory->evidence_points = evidence_points;
  new_theory->next = NULL;
  return new_theory;
}

void add_theory(theory_t **head, char *name, char *description, int evidence_points) {
  theory_t *new_theory = create_theory(name, description, evidence_points);
  if (*head == NULL) {
    *head = new_theory;
  } else {
    (*head)->next = new_theory;
  }
}

void print_theories(theory_t *head) {
  while (head) {
    printf("**Theory:** %s\n", head->name);
    printf("**Description:** %s\n", head->description);
    printf("**Evidence Points:** %d\n", head->evidence_points);
    printf("\n");
    head = head->next;
  }
}

int main() {
  theory_t *head = NULL;

  // Create a bunch of theories
  add_theory(&head, "The government is secretly spying on you.", "They have a fleet of drones that can track your every move.", 8);
  add_theory(&head, "Aliens are secretly visiting Earth.", "They have been seen flying around the globe.", 6);
  add_theory(&head, "The Illuminati is controlling the world.", "They are a secret society of wealthy and powerful individuals.", 7);
  add_theory(&head, "The earth is flat.", "It's not a sphere, it's a big disc.", 5);
  add_theory(&head, "The pyramids were built by aliens.", "They are too large to be built by humans.", 9);

  // Print all the theories
  print_theories(head);

  return 0;
}