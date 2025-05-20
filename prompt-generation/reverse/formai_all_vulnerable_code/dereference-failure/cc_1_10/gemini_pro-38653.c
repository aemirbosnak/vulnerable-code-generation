//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define NUM_DISKS 3

typedef struct {
  int num_disks;
  int *disks;
} tower;

tower *create_tower(int num_disks) {
  tower *t = malloc(sizeof(tower));
  t->num_disks = num_disks;
  t->disks = malloc(sizeof(int) * num_disks);
  for (int i = 0; i < num_disks; i++) {
    t->disks[i] = i;
  }
  return t;
}

void destroy_tower(tower *t) {
  free(t->disks);
  free(t);
}

void move_disk(tower *from, tower *to) {
  int disk = from->disks[from->num_disks - 1];
  from->num_disks--;
  to->disks[to->num_disks] = disk;
  to->num_disks++;
}

void towers_of_hanoi(tower *from, tower *to, tower *aux, int num_disks) {
  if (num_disks == 1) {
    move_disk(from, to);
  } else {
    towers_of_hanoi(from, aux, to, num_disks - 1);
    move_disk(from, to);
    towers_of_hanoi(aux, to, from, num_disks - 1);
  }
}

int main() {
  tower *tower1 = create_tower(NUM_DISKS);
  tower *tower2 = create_tower(0);
  tower *tower3 = create_tower(0);

  towers_of_hanoi(tower1, tower2, tower3, NUM_DISKS);

  for (int i = 0; i < tower2->num_disks; i++) {
    printf("%d\n", tower2->disks[i]);
  }

  destroy_tower(tower1);
  destroy_tower(tower2);
  destroy_tower(tower3);

  return 0;
}