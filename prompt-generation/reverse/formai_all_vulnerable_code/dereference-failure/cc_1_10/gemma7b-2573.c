//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x, y;
  struct Cell *up, *down, *right, *left;
} Cell;

void generateMaze(Cell **maze, int w, int h) {
  int i, j;
  *maze = (Cell *)malloc(w * h * sizeof(Cell));
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      (*maze)[i * w + j].x = j;
      (*maze)[i * w + j].y = i;
      (*maze)[i * w + j].up = NULL;
      (*maze)[i * w + j].down = NULL;
      (*maze)[i * w + j].right = NULL;
      (*maze)[i * w + j].left = NULL;
    }
  }

  srand(time(NULL));
  for (i = 0; i < w * h; i++) {
    int r = rand() % 4;
    switch (r) {
      case 0:
        (*maze)[i].up = (*maze)[i - 1].down;
        break;
      case 1:
        (*maze)[i].down = (*maze)[i + 1].up;
        break;
      case 2:
        (*maze)[i].right = (*maze)[i + 1].left;
        break;
      case 3:
        (*maze)[i].left = (*maze)[i - 1].right;
        break;
    }
  }
}

int main() {
  Cell *maze;
  generateMaze(&maze, WIDTH, HEIGHT);
  free(maze);
  return 0;
}