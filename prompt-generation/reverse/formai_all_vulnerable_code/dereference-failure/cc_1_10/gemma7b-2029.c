//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
  int **data;
  int **visited;
  int **candidates;
} Sudoku;

Sudoku *sudoku_create() {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->data = malloc(sizeof(int *) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->data[i] = malloc(sizeof(int) * SUDO_SIZE);
  }
  s->visited = malloc(sizeof(int *) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
  }
  s->candidates = malloc(sizeof(int *) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
  }

  return s;
}

void sudoku_destroy(Sudoku *s) {
  for (int i = 0; i < SUDO_SIZE; i++) {
    free(s->data[i]);
  }
  free(s->data);

  for (int i = 0; i < SUDO_SIZE; i++) {
    free(s->visited[i]);
  }
  free(s->visited);

  for (int i = 0; i < SUDO_SIZE; i++) {
    free(s->candidates[i]);
  }
  free(s->candidates);

  free(s);
}

void sudoku_solve(Sudoku *s) {
  if (sudoku_is_solved(s)) {
    return;
  }

  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      if (s->visited[i][j] == 0 && s->candidates[i][j] != 0) {
        s->data[i][j] = s->candidates[i][j];
        s->visited[i][j] = 1;

        sudoku_solve(s);

        s->data[i][j] = 0;
        s->visited[i][j] = 0;
      }
    }
  }

  return;
}

int sudoku_is_solved(Sudoku *s) {
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      if (s->data[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_create();

  // Generate a sudoku puzzle
  s->data[0][0] = 5;
  s->data[0][1] = 3;
  s->data[0][2] = 0;
  s->data[0][3] = 0;
  s->data[0][4] = 0;
  s->data[0][5] = 0;
  s->data[0][6] = 0;
  s->data[0][7] = 0;
  s->data[0][8] = 0;

  s->data[1][0] = 6;
  s->data[1][1] = 0;
  s->data[1][2] = 0;
  s->data[1][3] = 0;
  s->data[1][4] = 0;
  s->data[1][5] = 0;
  s->data[1][6] = 0;
  s->data[1][7] = 0;
  s->data[1][8] = 0;

  s->data[2][0] = 0;
  s->data[2][1] = 0;
  s->data[2][2] = 0;
  s->data[2][3] = 0;
  s->data[2][4] = 0;
  s->data[2][5] = 0;
  s->data[2][6] = 0;
  s->data[2][7] = 0;
  s->data[2][8] = 0;

  sudoku_solve(s);

  // Print the solution
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      printf("%d ", s->data[i][j]);
    }
    printf("\n");
  }

  sudoku_destroy(s);

  return 0;
}