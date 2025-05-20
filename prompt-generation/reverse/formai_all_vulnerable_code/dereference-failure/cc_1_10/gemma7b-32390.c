//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 3
#define MAX_DISCS 10

typedef struct Disc {
  int number;
  struct Disc* next;
} Disc;

typedef struct Pile {
  Disc* top;
  int num_discs;
} Pile;

void move_disc(Pile* from, Pile* to) {
  Disc* disc = from->top;
  from->top = disc->next;
  disc->next = to->top;
  to->top = disc;
  to->num_discs++;
  from->num_discs--;
}

void hanoi(int n, Pile* source, Pile* auxiliary, Pile* destination) {
  if (n == 0) {
    return;
  }
  hanoi(n - 1, source, destination, auxiliary);
  move_disc(source, destination);
  hanoi(1, auxiliary, source, destination);
}

int main() {
  Pile* source = malloc(sizeof(Pile));
  source->top = NULL;
  source->num_discs = 0;

  Pile* auxiliary = malloc(sizeof(Pile));
  auxiliary->top = NULL;
  auxiliary->num_discs = 0;

  Pile* destination = malloc(sizeof(Pile));
  destination->top = NULL;
  destination->num_discs = 0;

  hanoi(MAX_DISCS, source, auxiliary, destination);

  return 0;
}