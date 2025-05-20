//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSPIRACY_THEORIES 10

typedef struct ConspiracyTheory {
  char *title;
  char *description;
  int suspicious_actors;
  struct ConspiracyTheory *next;
} ConspiracyTheory;

ConspiracyTheory *generate_conspiracy_theory() {
  ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));
  theory->title = malloc(100);
  theory->description = malloc(500);
  theory->suspicious_actors = rand() % MAX_CONSPIRACY_THEORIES;
  theory->next = NULL;

  return theory;
}

void print_conspiracy_theory(ConspiracyTheory *theory) {
  printf("Title: %s\n", theory->title);
  printf("Description: %s\n", theory->description);
  printf("Suspicious actors: %d\n", theory->suspicious_actors);
  printf("\n");
}

int main() {
  ConspiracyTheory *head = NULL;
  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    ConspiracyTheory *theory = generate_conspiracy_theory();
    theory->title = "The Secret Society of Asymmetrical Eyebrows";
    theory->description = "A band of eccentric scientists, shrouded in mystery, allegedly created a mind-control device to manipulate the world.";
    theory->suspicious_actors = 3;

    if (head == NULL) {
      head = theory;
    } else {
      theory->next = head;
      head = theory;
    }
  }

  print_conspiracy_theory(head);

  return 0;
}