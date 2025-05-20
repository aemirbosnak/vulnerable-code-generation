//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
  int x, y;
} point;

typedef struct {
  int width, height;
  int **cells;
} grid;

grid *create_grid(int width, int height) {
  grid *g = malloc(sizeof(grid));
  g->width = width;
  g->height = height;
  g->cells = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    g->cells[i] = malloc(sizeof(int) * width);
  }
  return g;
}

void destroy_grid(grid *g) {
  for (int i = 0; i < g->height; i++) {
    free(g->cells[i]);
  }
  free(g->cells);
  free(g);
}

void set_cell(grid *g, int x, int y, int state) {
  if (x < 0 || x >= g->width || y < 0 || y >= g->height) {
    return;
  }
  g->cells[y][x] = state;
}

int get_cell(grid *g, int x, int y) {
  if (x < 0 || x >= g->width || y < 0 || y >= g->height) {
    return 0;
  }
  return g->cells[y][x];
}

int count_neighbors(grid *g, int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      count += get_cell(g, x + j, y + i);
    }
  }
  return count;
}

void update_grid(grid *g) {
  grid *new_grid = create_grid(g->width, g->height);
  for (int i = 0; i < g->height; i++) {
    for (int j = 0; j < g->width; j++) {
      int count = count_neighbors(g, j, i);
      if (get_cell(g, j, i)) {
        if (count == 2 || count == 3) {
          set_cell(new_grid, j, i, 1);
        }
      } else {
        if (count == 3) {
          set_cell(new_grid, j, i, 1);
        }
      }
    }
  }
  destroy_grid(g);
  g = new_grid;
}

void print_grid(grid *g) {
  for (int i = 0; i < g->height; i++) {
    for (int j = 0; j < g->width; j++) {
      printf("%c", get_cell(g, j, i) ? '#' : ' ');
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  grid *g = create_grid(WIDTH, HEIGHT);

  // Set up initial pattern
  set_cell(g, 30, 10, 1);
  set_cell(g, 31, 10, 1);
  set_cell(g, 32, 10, 1);
  set_cell(g, 20, 20, 1);
  set_cell(g, 21, 20, 1);
  set_cell(g, 22, 20, 1);
  set_cell(g, 23, 20, 1);
  set_cell(g, 20, 21, 1);
  set_cell(g, 23, 21, 1);

  // Run the simulation
  for (int i = 0; i < 100; i++) {
    update_grid(g);
    print_grid(g);
  }

  destroy_grid(g);
  return 0;
}