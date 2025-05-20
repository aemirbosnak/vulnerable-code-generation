//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int **visited;
  int **candidates;
} Sudoku;

Sudoku *sudoku_new() {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(MAX * MAX * sizeof(int));
  s->visited = malloc(MAX * MAX * sizeof(int));
  s->candidates = malloc(MAX * MAX * sizeof(int));

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      s->board[i][j] = 0;
      s->visited[i][j] = 0;
      s->candidates[i][j] = 9;
    }
  }

  return s;
}

void sudoku_solve(Sudoku *s) {
  if (sudoku_is_solved(s)) {
    return;
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (s->visited[i][j] == 0 && s->candidates[i][j] > 0) {
        s->board[i][j] = s->candidates[i][j];
        s->visited[i][j] = 1;

        sudoku_solve(s);

        s->board[i][j] = 0;
        s->visited[i][j] = 0;
      }
    }
  }
}

int sudoku_is_solved(Sudoku *s) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (s->board[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_new();
  sudoku_solve(s);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }

  return 0;
}