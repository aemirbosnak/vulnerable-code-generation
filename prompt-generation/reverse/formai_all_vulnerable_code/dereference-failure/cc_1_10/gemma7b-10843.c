//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Cell {
  int x;
  int y;
  struct Cell* up;
  struct Cell* down;
  struct Cell* right;
  struct Cell* left;
} Cell;

Cell* CreateMaze() {
  Cell* cell = malloc(sizeof(Cell));
  cell->x = 0;
  cell->y = 0;
  cell->up = NULL;
  cell->down = NULL;
  cell->right = NULL;
  cell->left = NULL;

  return cell;
}

void GenerateMaze(Cell* cell) {
  srand(time(NULL));
  int r = rand() % 4;

  switch (r) {
    case 0:
      cell->up = CreateMaze();
      break;
    case 1:
      cell->right = CreateMaze();
      break;
    case 2:
      cell->down = CreateMaze();
      break;
    case 3:
      cell->left = CreateMaze();
      break;
  }
}

void PrintMaze(Cell* cell) {
  printf("(");
  for (int y = 0; y < MAZE_HEIGHT; y++) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
      if (cell->x == x && cell->y == y) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf(")\n");
}

int main() {
  Cell* maze = CreateMaze();
  GenerateMaze(maze);
  PrintMaze(maze);

  return 0;
}