//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the number of disks
#define NUM_DISKS 4

// Define the three towers
#define TOWER_A 1
#define TOWER_B 2
#define TOWER_C 3

// Define the global variables
int num_moves = 0;

// Function to print the current state of the towers
void print_towers(int towers[3][NUM_DISKS]) {
  for (int i = 0; i < NUM_DISKS; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", towers[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int towers[3][NUM_DISKS], int from_tower, int to_tower) {
  // Get the index of the top disk on the from tower
  int from_index = 0;
  while (towers[from_tower][from_index] == 0) {
    from_index++;
  }

  // Get the index of the top disk on the to tower
  int to_index = 0;
  while (towers[to_tower][to_index] == 0) {
    to_index++;
  }

  // Move the disk from the from tower to the to tower
  towers[to_tower][to_index] = towers[from_tower][from_index];
  towers[from_tower][from_index] = 0;

  // Increment the number of moves
  num_moves++;

  // Print the current state of the towers
  printf("Move %d:\n", num_moves);
  print_towers(towers);
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int towers[3][NUM_DISKS], int num_disks, int from_tower, int to_tower, int via_tower) {
  // Base case: if there are no disks, then do nothing
  if (num_disks == 0) {
    return;
  }

  // Recursive case: move the top n-1 disks from the from tower to the via tower
  solve_tower_of_hanoi(towers, num_disks - 1, from_tower, via_tower, to_tower);

  // Move the nth disk from the from tower to the to tower
  move_disk(towers, from_tower, to_tower);

  // Recursive case: move the top n-1 disks from the via tower to the to tower
  solve_tower_of_hanoi(towers, num_disks - 1, via_tower, to_tower, from_tower);
}

int main() {
  // Initialize the towers
  int towers[3][NUM_DISKS] = {
    {3, 2, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };

  // Print the initial state of the towers
  printf("Initial state of the towers:\n");
  print_towers(towers);

  // Solve the Tower of Hanoi problem
  solve_tower_of_hanoi(towers, NUM_DISKS, TOWER_A, TOWER_C, TOWER_B);

  // Print the final state of the towers
  printf("Final state of the towers:\n");
  print_towers(towers);

  // Print the number of moves
  printf("Number of moves: %d\n", num_moves);

  return 0;
}