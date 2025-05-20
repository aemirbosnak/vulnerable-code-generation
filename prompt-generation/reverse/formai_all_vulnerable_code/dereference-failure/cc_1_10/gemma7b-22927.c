//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

typedef struct Cell {
  int x, y;
  int state;
} Cell;

void createMaze(Cell **maze, int w, int h) {
  int i, j;
  *maze = (Cell *)malloc(w * h * sizeof(Cell));
  for (i = 0; i < w * h; i++) {
    (*maze)[i].x = -1;
    (*maze)[i].y = -1;
    (*maze)[i].state = EMPTY;
  }

  for (i = 0; i < w; i++) {
    for (j = 0; j < h; j++) {
      if (i == 0 || j == 0) {
        (*maze)[i * w + j].state = WALL;
      }
    }
  }

  srand(time(NULL));
  for (i = 0; i < w * h; i++) {
    if ((*maze)[i].state == EMPTY) {
      (*maze)[i].state = WALL;
    }
  }
}

void drawMaze(Cell *maze, int w, int h) {
  int i, j;
  for (i = 0; i < w; i++) {
    for (j = 0; j < h; j++) {
      if (maze[i * w + j].state == WALL) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  Cell *maze;
  createMaze(&maze, WIDTH, HEIGHT);
  drawMaze(maze, WIDTH, HEIGHT);
  free(maze);

  return 0;
}