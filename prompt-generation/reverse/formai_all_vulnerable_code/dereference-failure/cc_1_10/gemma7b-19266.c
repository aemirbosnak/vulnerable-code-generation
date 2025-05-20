//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* up, *left, *right, *down;
} Node;

Node** createPercolationGrid(int size) {
  Node** grid = (Node**)malloc(size * size * sizeof(Node));
  for (int i = 0; i < size * size; i++) {
    grid[i] = (Node*)malloc(sizeof(Node));
    grid[i]->x = -1;
    grid[i]->y = -1;
    grid[i]->up = NULL;
    grid[i]->left = NULL;
    grid[i]->right = NULL;
    grid[i]->down = NULL;
  }
  return grid;
}

void simulatePercolation(Node** grid, int size) {
  srand(time(NULL));
  for (int i = 0; i < size * size; i++) {
    if (grid[i]->x == -1 && grid[i]->y == -1) {
      int r = rand() % 2;
      if (r == 0) {
        grid[i]->x = 0;
        grid[i]->y = 0;
      } else {
        grid[i]->x = 1;
        grid[i]->y = 1;
      }
    }
  }
}

void printPercolationGrid(Node** grid, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", grid[i * size + j]->x);
    }
    printf("\n");
  }
}

int main() {
  int size = MAX_PERCOLATION_SIZE;
  Node** grid = createPercolationGrid(size);
  simulatePercolation(grid, size);
  printPercolationGrid(grid, size);
  return 0;
}