//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACY_THEORIES 10

typedef struct ConspiracyTheory {
  char *title;
  char *description;
  int evidence_points;
  struct ConspiracyTheory *next;
} ConspiracyTheory;

ConspiracyTheory *conspiracy_theory_head = NULL;

void add_conspiracy_theory(char *title, char *description, int evidence_points) {
  ConspiracyTheory *new_theory = malloc(sizeof(ConspiracyTheory));
  new_theory->title = strdup(title);
  new_theory->description = strdup(description);
  new_theory->evidence_points = evidence_points;
  new_theory->next = NULL;

  if (conspiracy_theory_head == NULL) {
    conspiracy_theory_head = new_theory;
  } else {
    ConspiracyTheory *current_theory = conspiracy_theory_head;
    while (current_theory->next) {
      current_theory = current_theory->next;
    }
    current_theory->next = new_theory;
  }
}

void print_conspiracy_theories() {
  ConspiracyTheory *current_theory = conspiracy_theory_head;
  while (current_theory) {
    printf("%s: %s\n", current_theory->title, current_theory->description);
  }
}

int main() {
  add_conspiracy_theory("The Nixon Tapes", "The Nixon tapes reveal a secret meeting between President Nixon and his advisors about the Vietnam War.", 5);
  add_conspiracy_theory("The Roswell Incident", "The Roswell Incident is a conspiracy theory about the wreckage of a UFO over Roswell, New Mexico.", 3);
  add_conspiracy_theory("The Illuminati", "The Illuminati is a secret society that controls the world.", 2);

  print_conspiracy_theories();

  return 0;
}