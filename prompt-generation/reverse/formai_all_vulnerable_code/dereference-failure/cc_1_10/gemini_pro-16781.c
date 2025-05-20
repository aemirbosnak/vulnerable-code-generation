//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the maze
typedef struct cell {
  int x, y;
  int walls[4]; // 0: north, 1: east, 2: south, 3: west
} cell;

// Structure to represent the maze
typedef struct maze {
  cell **cells;
  int width, height;
} maze;

// Create a new maze
maze *create_maze(int width, int height) {
  maze *m = malloc(sizeof(maze));
  m->width = width;
  m->height = height;
  m->cells = malloc(height * sizeof(cell *));
  for (int i = 0; i < height; i++) {
    m->cells[i] = malloc(width * sizeof(cell));
  }
  return m;
}

// Destroy a maze
void destroy_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    free(m->cells[i]);
  }
  free(m->cells);
  free(m);
}

// Set a wall in a cell
void set_wall(cell *c, int wall, int value) {
  c->walls[wall] = value;
}

// Get a wall in a cell
int get_wall(cell *c, int wall) {
  return c->walls[wall];
}

// Print a maze
void print_maze(maze *m) {
  for (int i = 0; i < m->height; i++) {
    for (int j = 0; j < m->width; j++) {
      cell *c = &m->cells[i][j];
      printf("+%c%c%c%c", get_wall(c, 0) ? '-' : ' ',
             get_wall(c, 1) ? '|' : ' ', get_wall(c, 2) ? '-' : ' ',
             get_wall(c, 3) ? '|' : ' ');
    }
    printf("+\n");
  }
}

// Generate a maze using the recursive backtracker algorithm
void generate_maze(maze *m) {
  srand(time(NULL));
  for (int i = 0; i < m->height; i++) {
    for (int j = 0; j < m->width; j++) {
      cell *c = &m->cells[i][j];
      for (int k = 0; k < 4; k++) {
        c->walls[k] = 1;
      }
    }
  }
  int stack_size = m->width * m->height;
  int *stack = malloc(stack_size * sizeof(int));
  int top = -1;
  int x = rand() % m->width;
  int y = rand() % m->height;
  while (top != -1) {
    cell *c = &m->cells[y][x];
    int unvisited_neighbors = 0;
    for (int k = 0; k < 4; k++) {
      int nx = x + (k % 2 == 0 ? k - 1 : 0);
      int ny = y + (k % 2 == 1 ? k - 2 : 0);
      if (nx >= 0 && nx < m->width && ny >= 0 && ny < m->height && m->cells[ny][nx].walls[k] == 1) {
        unvisited_neighbors++;
      }
    }
    if (unvisited_neighbors > 0) {
      int k = rand() % unvisited_neighbors;
      for (int j = 0; j < 4; j++) {
        int nx = x + (j % 2 == 0 ? j - 1 : 0);
        int ny = y + (j % 2 == 1 ? j - 2 : 0);
        if (nx >= 0 && nx < m->width && ny >= 0 && ny < m->height && m->cells[ny][nx].walls[j] == 1) {
          if (k == 0) {
            m->cells[y][x].walls[j] = 0;
            m->cells[ny][nx].walls[j ^ 2] = 0;
            x = nx;
            y = ny;
            top++;
            stack[top] = y * m->width + x;
          }
          k--;
        }
      }
    } else {
      x = stack[top] % m->width;
      y = stack[top] / m->width;
      top--;
    }
  }
  free(stack);
}

// Solve a maze using the depth-first search algorithm
int solve_maze(maze *m, int x, int y) {
  if (x == m->width - 1 && y == m->height - 1) {
    return 1;
  }
  if (m->cells[y][x].walls[0] == 0 && solve_maze(m, x, y - 1)) {
    return 1;
  }
  if (m->cells[y][x].walls[1] == 0 && solve_maze(m, x + 1, y)) {
    return 1;
  }
  if (m->cells[y][x].walls[2] == 0 && solve_maze(m, x, y + 1)) {
    return 1;
  }
  if (m->cells[y][x].walls[3] == 0 && solve_maze(m, x - 1, y)) {
    return 1;
  }
  return 0;
}

int main() {
  int width = 10;
  int height = 10;
  maze *m = create_maze(width, height);
  generate_maze(m);
  print_maze(m);
  if (solve_maze(m, 0, 0)) {
    printf("Maze solved!\n");
  } else {
    printf("Maze unsolvable!\n");
  }
  destroy_maze(m);
  return 0;
}