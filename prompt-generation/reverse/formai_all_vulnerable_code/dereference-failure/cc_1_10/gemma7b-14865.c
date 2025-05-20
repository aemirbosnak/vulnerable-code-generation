//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct Cell {
  int x, y;
  char type;
  struct Cell* north, *south, *east, *west;
} Cell;

Cell* CreateCell(int x, int y) {
  Cell* cell = malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->type = ' ';
  cell->north = NULL;
  cell->south = NULL;
  cell->east = NULL;
  cell->west = NULL;
  return cell;
}

void ConnectCells(Cell* cell1, Cell* cell2) {
  cell1->north = cell2;
  cell2->south = cell1;
  cell1->east = cell2;
  cell2->west = cell1;
}

void GenerateMap() {
  srand(time(NULL));
  int x, y;
  for (x = 0; x < MAP_WIDTH; x++) {
    for (y = 0; y < MAP_HEIGHT; y++) {
      Cell* cell = CreateCell(x, y);
      cell->type = ' ';
      if (rand() % 20 == 0) {
        cell->type = 'O';
      }
    }
  }
}

void PrintMap(Cell* cell) {
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      Cell* currentCell = cell->north->south->east->west;
      if (currentCell->x == x && currentCell->y == y) {
        printf("%c ", currentCell->type);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  GenerateMap();
  PrintMap(CreateCell(0, 0));
  return 0;
}