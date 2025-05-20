//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
  int **board;
  int **visited;
  int **candidates;
  int size;
} Sudoku;

Sudoku *sudoku_init(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->visited = malloc(size * size * sizeof(int));
  s->candidates = malloc(size * size * sizeof(int));
  s->size = size;
  return s;
}

void sudoku_solve(Sudoku *s) {
  for (int i = 0; i < s->size * s->size; i++) {
    if (!s->visited[i] && s->candidates[i] > 0) {
      s->visited[i] = 1;
      for (int j = 0; j < s->size * s->size; j++) {
        if (s->board[i] == s->board[j] && s->visited[j] && j != i) {
          s->candidates[i] = 0;
        }
      }
      if (s->candidates[i] > 0) {
        s->board[i] = s->candidates[i];
        sudoku_solve(s);
        s->board[i] = 0;
      }
    }
  }
  if (s->board[0] == 0) {
    printf("Solution:\n");
    for (int i = 0; i < s->size; i++) {
      for (int j = 0; j < s->size; j++) {
        printf("%d ", s->board[i * s->size + j]);
      }
      printf("\n");
    }
  }
}

int main() {
  Sudoku *s = sudoku_init(SUDO_SIZE);
  sudoku_solve(s);
  return 0;
}