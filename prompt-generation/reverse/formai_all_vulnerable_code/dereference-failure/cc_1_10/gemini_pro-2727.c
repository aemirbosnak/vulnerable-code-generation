//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_DISKS 100

typedef struct {
  int num_disks;
  int *disks;
} Tower;

void print_tower(Tower tower) {
  for (int i = 0; i < tower.num_disks; i++) {
    printf("%d ", tower.disks[i]);
  }
  printf("\n");
}

void move_disk(Tower *tower_from, Tower *tower_to) {
  int disk = tower_from->disks[tower_from->num_disks - 1];
  tower_from->num_disks--;
  tower_to->disks[tower_to->num_disks++] = disk;
}

void tower_of_hanoi(Tower *tower_from, Tower *tower_to, Tower *tower_aux, int num_disks) {
  if (num_disks == 1) {
    move_disk(tower_from, tower_to);
    return;
  }

  tower_of_hanoi(tower_from, tower_aux, tower_to, num_disks - 1);
  move_disk(tower_from, tower_to);
  tower_of_hanoi(tower_aux, tower_to, tower_from, num_disks - 1);
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  if (num_disks > MAX_NUM_DISKS) {
    printf("Invalid number of disks. Must be less than or equal to %d.\n", MAX_NUM_DISKS);
    return 1;
  }

  Tower tower_from, tower_to, tower_aux;
  tower_from.num_disks = num_disks;
  tower_from.disks = malloc(sizeof(int) * num_disks);
  for (int i = 0; i < num_disks; i++) {
    tower_from.disks[i] = num_disks - i;
  }

  tower_to.num_disks = 0;
  tower_to.disks = malloc(sizeof(int) * num_disks);

  tower_aux.num_disks = 0;
  tower_aux.disks = malloc(sizeof(int) * num_disks);

  printf("Initial state:\n");
  print_tower(tower_from);
  print_tower(tower_to);
  print_tower(tower_aux);

  tower_of_hanoi(&tower_from, &tower_to, &tower_aux, num_disks);

  printf("Final state:\n");
  print_tower(tower_from);
  print_tower(tower_to);
  print_tower(tower_aux);

  free(tower_from.disks);
  free(tower_to.disks);
  free(tower_aux.disks);

  return 0;
}