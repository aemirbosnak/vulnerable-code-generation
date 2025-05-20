//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3

typedef struct tower {
  int num_disks;
  int *disks;
} tower;

void towers_of_hanoi(int num_disks, tower *towers) {
  // Move the disks from the first tower to the third tower using the second tower as an intermediary.

  // Base case: If there are no disks, do nothing.
  if (num_disks == 0) {
    return;
  }

  // Recursive case: Move the top disk from the first tower to the second tower.
  towers_of_hanoi(num_disks - 1, towers);

  // Move the bottom disk from the first tower to the third tower.
  towers[2].disks[towers[2].num_disks++] = towers[0].disks[--towers[0].num_disks];

  // Recursive case: Move the remaining disks from the second tower to the third tower.
  towers_of_hanoi(num_disks - 1, towers);
}

void print_towers(tower *towers) {
  // Print the current state of the towers.

  for (int i = 0; i < NUM_TOWERS; i++) {
    printf("Tower %d: ", i);
    for (int j = 0; j < towers[i].num_disks; j++) {
      printf("%d ", towers[i].disks[j]);
    }
    printf("\n");
  }
}

int main() {
  // Create the towers.

  tower towers[NUM_TOWERS];
  for (int i = 0; i < NUM_TOWERS; i++) {
    towers[i].num_disks = 0;
    towers[i].disks = malloc(sizeof(int) * 10);
  }

  // Initialize the first tower with disks.

  for (int i = 0; i < 10; i++) {
    towers[0].disks[towers[0].num_disks++] = i;
  }

  // Print the initial state of the towers.

  print_towers(towers);

  // Solve the Towers of Hanoi problem.

  towers_of_hanoi(10, towers);

  // Print the final state of the towers.

  print_towers(towers);

  // Free the memory allocated for the towers.

  for (int i = 0; i < NUM_TOWERS; i++) {
    free(towers[i].disks);
  }

  return 0;
}