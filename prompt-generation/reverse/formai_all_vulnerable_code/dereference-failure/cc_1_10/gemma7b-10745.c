//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5

typedef struct Cell {
  int x, y;
  struct Cell* up, *down, *right, *left;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->up = NULL;
  cell->down = NULL;
  cell->right = NULL;
  cell->left = NULL;
  return cell;
}

void destroyCell(Cell* cell) {
  free(cell);
}

void printMap(Cell* cell) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      Cell* currentCell = cell->up->down->right->left;
      if (currentCell->x == x && currentCell->y == y) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  Cell* map = createCell(0, 0);
  map->up = createCell(0, 1);
  map->up->up = createCell(0, 2);
  map->up->up->up = createCell(0, 3);
  map->up->up->up->up = createCell(0, 4);

  map->down = createCell(0, 1);
  map->down->down = createCell(0, 2);
  map->down->down->down = createCell(0, 3);

  map->right = createCell(1, 0);
  map->right->right = createCell(2, 0);
  map->right->right->right = createCell(3, 0);

  map->left = createCell(-1, 0);
  map->left->left = createCell(-2, 0);
  map->left->left->left = createCell(-3, 0);

  printMap(map);

  destroyCell(map);

  return 0;
}