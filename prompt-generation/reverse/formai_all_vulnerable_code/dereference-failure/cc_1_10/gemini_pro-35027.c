//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the number of disks
#define NUM_DISKS 5

// Define the three towers
#define A 'A'
#define B 'B'
#define C 'C'

// Function to print the current state of the towers
void print_towers(char towers[3][NUM_DISKS]) {
  for (int i = 0; i < NUM_DISKS; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", towers[j][i]);
    }
    printf("\n");
  }
}

// Function to move a disk from one tower to another
void move_disk(char towers[3][NUM_DISKS], char from, char to) {
  // Find the index of the top disk on the 'from' tower
  int from_index = 0;
  while (towers[from - A][from_index] == ' ') {
    from_index++;
  }

  // Find the index of the top disk on the 'to' tower
  int to_index = 0;
  while (towers[to - A][to_index] == ' ') {
    to_index++;
  }

  // Move the disk from the 'from' tower to the 'to' tower
  towers[to - A][to_index] = towers[from - A][from_index];
  towers[from - A][from_index] = ' ';
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(char towers[3][NUM_DISKS], int n, char from, char to, char aux) {
  // Base case: If there is only one disk, move it from the 'from' tower to the 'to' tower
  if (n == 1) {
    move_disk(towers, from, to);
    return;
  }

  // Recursive case: Move n-1 disks from the 'from' tower to the 'aux' tower
  tower_of_hanoi(towers, n - 1, from, aux, to);

  // Move the remaining disk from the 'from' tower to the 'to' tower
  move_disk(towers, from, to);

  // Move n-1 disks from the 'aux' tower to the 'to' tower
  tower_of_hanoi(towers, n - 1, aux, to, from);
}

int main() {
  // Initialize the three towers
  char towers[3][NUM_DISKS];
  for (int i = 0; i < NUM_DISKS; i++) {
    for (int j = 0; j < 3; j++) {
      towers[j][i] = ' ';
    }
  }
  towers[A - A][0] = '1';
  towers[A - A][1] = '2';
  towers[A - A][2] = '3';
  towers[A - A][3] = '4';
  towers[A - A][4] = '5';

  // Print the initial state of the towers
  printf("Initial state of the towers:\n");
  print_towers(towers);

  // Solve the Tower of Hanoi problem
  tower_of_hanoi(towers, NUM_DISKS, A, C, B);

  // Print the final state of the towers
  printf("\nFinal state of the towers:\n");
  print_towers(towers);

  return 0;
}