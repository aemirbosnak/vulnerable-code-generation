//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 15

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PATH_CHAR ' '

typedef struct Maze {
  int **cells;
  int width;
  int height;
} Maze;

Maze *create_maze() {
  int i, j;
  Maze *maze = malloc(sizeof(Maze));
  maze->cells = malloc(sizeof(int *) * maze->height);
  for (i = 0; i < maze->height; i++) {
    maze->cells[i] = malloc(sizeof(int) * maze->width);
  }

  maze->width = MAZE_WIDTH;
  maze->height = MAZE_HEIGHT;

  for (i = 0; i < maze->height; i++) {
    for (j = 0; j < maze->width; j++) {
      maze->cells[i][j] = EMPTY_CHAR;
    }
  }

  return maze;
}

void draw_maze(Maze *maze) {
  int i, j;
  for (i = 0; i < maze->height; i++) {
    for (j = 0; j < maze->width; j++) {
      printf("%c ", maze->cells[i][j]);
    }
    printf("\n");
  }
}

int main() {
  time_t t;
  srand(time(&t));

  Maze *maze = create_maze();

  // Generate the maze
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (rand() % 2 == 0) {
        maze->cells[i][j] = WALL_CHAR;
      }
    }
  }

  // Draw the maze
  draw_maze(maze);

  return 0;
}