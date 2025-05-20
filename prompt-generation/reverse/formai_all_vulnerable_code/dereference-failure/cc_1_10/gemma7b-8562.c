//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_SIZE 1024

typedef struct Cell {
  int water;
  struct Cell* up, *right, *down, *left;
} Cell;

void simulate(Cell* cell) {
  if (cell->water > 0) {
    cell->water--;
    if (cell->up) {
      cell->up->water++;
    }
    if (cell->right) {
      cell->right->water++;
    }
    if (cell->down) {
      cell->down->water++;
    }
    if (cell->left) {
      cell->left->water++;
    }
  }
}

int main() {
  srand(time(NULL));
  Cell* map[MAP_SIZE];
  for (int i = 0; i < MAP_SIZE; i++) {
    map[i] = malloc(sizeof(Cell));
    map[i]->water = rand() % 5;
    map[i]->up = NULL;
    map[i]->right = NULL;
    map[i]->down = NULL;
    map[i]->left = NULL;
  }

  for (int t = 0; t < 1000; t++) {
    for (int i = 0; i < MAP_SIZE; i++) {
      simulate(map[i]);
    }
  }

  for (int i = 0; i < MAP_SIZE; i++) {
    printf("%d ", map[i]->water);
  }
  printf("\n");

  return 0;
}