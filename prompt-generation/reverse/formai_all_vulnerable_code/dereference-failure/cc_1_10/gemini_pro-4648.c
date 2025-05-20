//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the tower of Hanoi
void printTower(int numDisks, int *tower1, int *tower2, int *tower3) {
  printf("Tower 1: ");
  for (int i = 0; i < numDisks; i++) {
    printf("%d ", tower1[i]);
  }
  printf("\n");
  printf("Tower 2: ");
  for (int i = 0; i < numDisks; i++) {
    printf("%d ", tower2[i]);
  }
  printf("\n");
  printf("Tower 3: ");
  for (int i = 0; i < numDisks; i++) {
    printf("%d ", tower3[i]);
  }
  printf("\n");
  printf("\n");
}

// Function to move a disk from one tower to another
void moveDisk(int numDisks, int *tower1, int *tower2, int *tower3, int fromTower, int toTower) {
  // Check if the move is valid
  if (tower1[numDisks - 1] > tower2[numDisks - 1] && fromTower == 1 && toTower == 2) {
    printf("Invalid move: Cannot move a larger disk onto a smaller disk.\n");
    return;
  }
  if (tower1[numDisks - 1] > tower3[numDisks - 1] && fromTower == 1 && toTower == 3) {
    printf("Invalid move: Cannot move a larger disk onto a smaller disk.\n");
    return;
  }
  if (tower2[numDisks - 1] > tower3[numDisks - 1] && fromTower == 2 && toTower == 3) {
    printf("Invalid move: Cannot move a larger disk onto a smaller disk.\n");
    return;
  }

  // Move the disk
  tower2[numDisks - 1] = tower1[numDisks - 1];
  tower1[numDisks - 1] = 0;

  // Print the current state of the tower of Hanoi
  printTower(numDisks, tower1, tower2, tower3);
}

// Function to solve the tower of Hanoi problem
void solveTowerOfHanoi(int numDisks, int *tower1, int *tower2, int *tower3) {
  // Base case: only one disk
  if (numDisks == 1) {
    moveDisk(numDisks, tower1, tower2, tower3, 1, 3);
    return;
  }

  // Recursive case: more than one disk
  solveTowerOfHanoi(numDisks - 1, tower1, tower3, tower2);
  moveDisk(numDisks, tower1, tower2, tower3, 1, 3);
  solveTowerOfHanoi(numDisks - 1, tower3, tower2, tower1);
}

int main() {
  // Get the number of disks from the user
  int numDisks;
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);

  // Create three towers
  int *tower1 = malloc(numDisks * sizeof(int));
  int *tower2 = malloc(numDisks * sizeof(int));
  int *tower3 = malloc(numDisks * sizeof(int));

  // Initialize the towers
  for (int i = 0; i < numDisks; i++) {
    tower1[i] = numDisks - i;
    tower2[i] = 0;
    tower3[i] = 0;
  }

  // Print the initial state of the tower of Hanoi
  printTower(numDisks, tower1, tower2, tower3);

  // Solve the tower of Hanoi problem
  solveTowerOfHanoi(numDisks, tower1, tower2, tower3);

  return 0;
}