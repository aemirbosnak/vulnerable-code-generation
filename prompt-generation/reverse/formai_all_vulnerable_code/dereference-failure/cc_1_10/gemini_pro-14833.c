//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  int width;
  int height;
  char **cells;
} maze;

maze *create_maze(int width, int height) {
  maze *m = malloc(sizeof(maze));
  m->width = width;
  m->height = height;
  m->cells = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    m->cells[i] = malloc(sizeof(char) * width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      m->cells[i][j] = '#';
    }
  }

  return m;
}

void free_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    free(m->cells[i]);
  }
  free(m->cells);
  free(m);
}

void print_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    for (int j = 0; j < m->width; j++) {
      printf("%c", m->cells[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  maze *m = create_maze(MAZE_SIZE, MAZE_SIZE);

  // Generate the maze using a recursive backtracker algorithm
  point current = {0, 0};
  m->cells[current.y][current.x] = ' ';

  while (1) {
    // Get a list of possible next moves
    int num_possible_moves = 0;
    point possible_moves[4];
    if (current.y > 0 && m->cells[current.y - 1][current.x] == '#') {
      possible_moves[num_possible_moves++] = (point){current.x, current.y - 1};
    }
    if (current.x < m->width - 1 && m->cells[current.y][current.x + 1] == '#') {
      possible_moves[num_possible_moves++] = (point){current.x + 1, current.y};
    }
    if (current.y < m->height - 1 && m->cells[current.y + 1][current.x] == '#') {
      possible_moves[num_possible_moves++] = (point){current.x, current.y + 1};
    }
    if (current.x > 0 && m->cells[current.y][current.x - 1] == '#') {
      possible_moves[num_possible_moves++] = (point){current.x - 1, current.y};
    }

    // If there are no possible moves, we're done
    if (num_possible_moves == 0) {
      break;
    }

    // Choose a random move
    int chosen_move = rand() % num_possible_moves;
    current = possible_moves[chosen_move];

    // Mark the cell as visited
    m->cells[current.y][current.x] = ' ';
  }

  // Print the maze
  print_maze(m);

  // Free the maze
  free_maze(m);

  return 0;
}