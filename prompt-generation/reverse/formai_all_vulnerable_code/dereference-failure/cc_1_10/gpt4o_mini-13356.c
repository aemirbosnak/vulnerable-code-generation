//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
  int **grid;
  int size;
} Percolation;

Percolation* create_percolation(int size) {
  Percolation *p = (Percolation *)malloc(sizeof(Percolation));
  p->size = size;
  p->grid = (int **)malloc(size * sizeof(int *));
  
  for (int i = 0; i < size; i++) {
    p->grid[i] = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      p->grid[i][j] = BLOCKED;
    }
  }
  return p;
}

void free_percolation(Percolation *p) {
  for (int i = 0; i < p->size; i++) {
    free(p->grid[i]);
  }
  free(p->grid);
  free(p);
}

void open_site(Percolation *p, int row, int col) {
  if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
    p->grid[row][col] = OPEN;
  }
}

int is_open(Percolation *p, int row, int col) {
  if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
    return p->grid[row][col] == OPEN;
  }
  return 0;
}

int percolates(Percolation *p) {
  int *visited = (int *)calloc(p->size * p->size, sizeof(int));
  int stack_size = p->size * p->size;
  int *stack = (int *)malloc(stack_size * sizeof(int));
  int top = -1;

  for (int j = 0; j < p->size; j++) {
    if (p->grid[0][j] == OPEN) {
      stack[++top] = j;  // Push column index onto the stack
      visited[j] = 1;     // Mark as visited
    }
  }

  while (top >= 0) {
    int col = stack[top--];
    for (int row = 0; row < p->size; row++) {
      if (is_open(p, row, col)) {
        if (row == p->size - 1) {
          free(stack);
          free(visited);
          return 1;  // Found a path to the bottom
        }
        // Explore neighbors
        if (is_open(p, row + 1, col) && !visited[(row + 1) * p->size + col]) {
          visited[(row + 1) * p->size + col] = 1;
          stack[++top] = col;  // Push column index again
        }
        if (is_open(p, row, col - 1) && !visited[row * p->size + col - 1]) {
          visited[row * p->size + col - 1] = 1;
          stack[++top] = col - 1;  // Push left neighbor
        }
        if (is_open(p, row, col + 1) && !visited[row * p->size + col + 1]) {
          visited[row * p->size + col + 1] = 1;
          stack[++top] = col + 1;  // Push right neighbor
        }
      }
    }
  }

  free(stack);
  free(visited);
  return 0;
}

void display_grid(Percolation *p) {
  for (int i = 0; i < p->size; i++) {
    for (int j = 0; j < p->size; j++) {
      printf("%d ", p->grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  int size = 10; // Set grid size
  Percolation *p = create_percolation(size);

  // Randomly open some sites
  for (int i = 0; i < size * size / 2; i++) {
    int r = rand() % size;
    int c = rand() % size;
    open_site(p, r, c);
  }

  printf("Initial grid state:\n");
  display_grid(p);

  if (percolates(p)) {
    printf("The system percolates!\n");
  } else {
    printf("The system does not percolate.\n");
  }

  free_percolation(p);
  return 0;
}