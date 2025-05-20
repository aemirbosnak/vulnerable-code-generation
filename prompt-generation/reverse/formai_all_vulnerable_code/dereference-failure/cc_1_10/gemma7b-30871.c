//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_Boulders 10
#define MAX_PILES 5

typedef struct Boulder {
  int x, y, is_active;
} Boulder;

typedef struct Pile {
  int num_boulders;
  Boulder boulders[MAX_Boulders];
} Pile;

void initialize_boulders(Pile *p) {
  p->num_boulders = 0;
  for (int i = 0; i < MAX_Boulders; i++) {
    p->boulders[i].x = -1;
    p->boulders[i].y = -1;
    p->boulders[i].is_active = 0;
  }
}

void add_boulder(Pile *p, int x, int y) {
  p->boulders[p->num_boulders].x = x;
  p->boulders[p->num_boulders].y = y;
  p->boulders[p->num_boulders].is_active = 1;
  p->num_boulders++;
}

int main() {
  Pile *p = malloc(sizeof(Pile));
  initialize_boulders(p);

  add_boulder(p, 0, 0);
  add_boulder(p, 1, 0);
  add_boulder(p, 2, 0);
  add_boulder(p, 3, 0);

  for (int i = 0; i < p->num_boulders; i++) {
    if (p->boulders[i].is_active) {
      printf("Boulder at (%d, %d)\n", p->boulders[i].x, p->boulders[i].y);
    }
  }

  free(p);

  return 0;
}