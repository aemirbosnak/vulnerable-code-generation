//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOWERS 3
#define MAX_DISKS 10

typedef struct {
  int num_disks;
  int disks[MAX_DISKS];
} tower;

void print_towers(tower towers[MAX_TOWERS]) {
  for (int i = 0; i < MAX_TOWERS; i++) {
    printf("Tower %d: ", i + 1);
    for (int j = 0; j < towers[i].num_disks; j++) {
      printf("%d ", towers[i].disks[j]);
    }
    printf("\n");
  }
}

void move_disk(tower towers[MAX_TOWERS], int from, int to) {
  towers[to].disks[towers[to].num_disks++] = towers[from].disks[--towers[from].num_disks];
}

void tower_of_hanoi(tower towers[MAX_TOWERS], int n, int from, int to, int via) {
  if (n == 1) {
    move_disk(towers, from, to);
  } else {
    tower_of_hanoi(towers, n - 1, from, via, to);
    move_disk(towers, from, to);
    tower_of_hanoi(towers, n - 1, via, to, from);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <num_disks>\n", argv[0]);
    return 1;
  }

  int num_disks = atoi(argv[1]);
  if (num_disks <= 0 || num_disks > MAX_DISKS) {
    printf("Invalid number of disks: %d\n", num_disks);
    return 1;
  }

  tower towers[MAX_TOWERS] = {
    {0, {}},
    {0, {}},
    {0, {}},
  };

  for (int i = num_disks; i > 0; i--) {
    towers[0].disks[towers[0].num_disks++] = i;
  }

  printf("Initial state:\n");
  print_towers(towers);

  tower_of_hanoi(towers, num_disks, 0, 2, 1);

  printf("Final state:\n");
  print_towers(towers);

  return 0;
}