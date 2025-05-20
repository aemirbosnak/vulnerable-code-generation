//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define the Tower of Hanoi problem
struct TowerOfHanoi {
  int numDisks;
  int numMoves;
  int **towers;
};

// Create a new Tower of Hanoi problem
struct TowerOfHanoi *createTowerOfHanoi(int numDisks) {
  struct TowerOfHanoi *tower = malloc(sizeof(struct TowerOfHanoi));
  tower->numDisks = numDisks;
  tower->numMoves = 0;
  tower->towers = malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    tower->towers[i] = malloc((numDisks + 1) * sizeof(int));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < numDisks + 1; j++) {
      tower->towers[i][j] = 0;
    }
  }
  for (int i = 0; i < numDisks; i++) {
    tower->towers[0][i] = numDisks - i;
  }
  return tower;
}

// Free the memory used by a Tower of Hanoi problem
void freeTowerOfHanoi(struct TowerOfHanoi *tower) {
  for (int i = 0; i < 3; i++) {
    free(tower->towers[i]);
  }
  free(tower->towers);
  free(tower);
}

// Print the current state of a Tower of Hanoi problem
void printTowerOfHanoi(struct TowerOfHanoi *tower) {
  for (int i = tower->numDisks - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", tower->towers[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

// Solve the Tower of Hanoi problem
void solveTowerOfHanoi(struct TowerOfHanoi *tower) {
  // Move the disks from the first tower to the second tower
  for (int i = 0; i < tower->numDisks; i++) {
    tower->towers[1][i] = tower->towers[0][i];
    tower->towers[0][i] = 0;
    tower->numMoves++;
    printTowerOfHanoi(tower);
  }
  // Move the disks from the second tower to the third tower
  for (int i = 0; i < tower->numDisks; i++) {
    tower->towers[2][i] = tower->towers[1][i];
    tower->towers[1][i] = 0;
    tower->numMoves++;
    printTowerOfHanoi(tower);
  }
  // Move the disks from the first tower to the third tower
  for (int i = 0; i < tower->numDisks; i++) {
    tower->towers[2][i] = tower->towers[0][i];
    tower->towers[0][i] = 0;
    tower->numMoves++;
    printTowerOfHanoi(tower);
  }
}

// Main function
int main() {
  // Create a new Tower of Hanoi problem
  struct TowerOfHanoi *tower = createTowerOfHanoi(3);
  // Print the initial state of the Tower of Hanoi problem
  printTowerOfHanoi(tower);
  // Solve the Tower of Hanoi problem
  solveTowerOfHanoi(tower);
  // Print the final state of the Tower of Hanoi problem
  printTowerOfHanoi(tower);
  // Free the memory used by the Tower of Hanoi problem
  freeTowerOfHanoi(tower);
  return 0;
}