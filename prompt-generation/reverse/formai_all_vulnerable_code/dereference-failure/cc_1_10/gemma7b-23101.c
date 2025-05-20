//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
  int **visited;
  int **candidates;
} Sudoku;

Sudoku *sudoku_init(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(sizeof(int *) * size);
  s->size = size;
  s->visited = malloc(sizeof(int *) * size);
  s->candidates = malloc(sizeof(int *) * size);

  for (int i = 0; i < size; i++) {
    s->board[i] = malloc(sizeof(int) * size);
    s->visited[i] = malloc(sizeof(int) * size);
    s->candidates[i] = malloc(sizeof(int) * size);
  }

  return s;
}

void sudoku_solve(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0 && !s->visited[i][j]) {
        for (int k = 0; k < s->size; k++) {
          if (s->candidates[i][k] && !s->visited[k][j]) {
            s->visited[i][j] = 1;
            s->board[i][j] = s->candidates[i][k];
            sudoku_solve(s);
            s->board[i][j] = 0;
            s->visited[i][j] = 0;
          }
        }
      }
    }
  }

  if (s->board[0][0] == s->size * s->size) {
    printf("Solution:\n");
    for (int i = 0; i < s->size; i++) {
      for (int j = 0; j < s->size; j++) {
        printf("%d ", s->board[i][j]);
      }
      printf("\n");
    }
  }
}

int main() {
  Sudoku *s = sudoku_init(9);

  s->board[0][0] = 5;
  s->board[0][1] = 3;
  s->board[0][2] = 0;
  s->board[1][0] = 6;
  s->board[1][1] = 0;
  s->board[1][2] = 0;
  s->board[2][0] = 0;
  s->board[2][1] = 0;
  s->board[2][2] = 0;

  sudoku_solve(s);

  return 0;
}