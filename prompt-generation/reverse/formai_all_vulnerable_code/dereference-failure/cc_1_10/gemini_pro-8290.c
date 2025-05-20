//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 5

// Structure to represent a tower
typedef struct tower {
  int num_disks;
  int *disks;
} tower;

// Function to create a new tower
tower *create_tower(int num_disks) {
  tower *new_tower = (tower *)malloc(sizeof(tower));
  new_tower->num_disks = num_disks;
  new_tower->disks = (int *)malloc(sizeof(int) * num_disks);
  for (int i = 0; i < num_disks; i++) {
    new_tower->disks[i] = i + 1;
  }
  return new_tower;
}

// Function to print a tower
void print_tower(tower *t) {
  for (int i = t->num_disks - 1; i >= 0; i--) {
    printf("%d ", t->disks[i]);
  }
  printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(tower *from, tower *to) {
  int disk = from->disks[from->num_disks - 1];
  from->num_disks--;
  to->disks[to->num_disks++] = disk;
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(tower *towers, int num_disks, int from, int to, int via) {
  if (num_disks == 1) {
    move_disk(&towers[from], &towers[to]);
  } else {
    solve_tower_of_hanoi(towers, num_disks - 1, from, via, to);
    move_disk(&towers[from], &towers[to]);
    solve_tower_of_hanoi(towers, num_disks - 1, via, to, from);
  }
}

int main() {
  // Create the towers
  tower towers[NUM_TOWERS];
  for (int i = 0; i < NUM_TOWERS; i++) {
    towers[i] = *create_tower(NUM_DISKS);
  }

  // Print the initial state of the towers
  printf("Initial state:\n");
  for (int i = 0; i < NUM_TOWERS; i++) {
    print_tower(&towers[i]);
    printf("\n");
  }

  // Solve the Tower of Hanoi problem
  solve_tower_of_hanoi(towers, NUM_DISKS, 0, 2, 1);

  // Print the final state of the towers
  printf("Final state:\n");
  for (int i = 0; i < NUM_TOWERS; i++) {
    print_tower(&towers[i]);
    printf("\n");
  }

  return 0;
}