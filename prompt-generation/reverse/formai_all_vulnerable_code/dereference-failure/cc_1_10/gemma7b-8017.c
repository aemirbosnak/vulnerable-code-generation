//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
  int solved;
} Sudoku;

Sudoku *sudoku_new(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++) {
    s->board[i] = malloc(sizeof(int) * size);
  }
  s->size = size;
  s->solved = 0;
  return s;
}

void sudoku_free(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    free(s->board[i]);
  }
  free(s->board);
  free(s);
}

int sudoku_rand(Sudoku *s) {
  if (s->solved) {
    return 0;
  }
  int r = rand() % (s->size * s->size);
  int x = r / s->size;
  int y = r % s->size;
  if (s->board[x][y] == 0) {
    return 1;
  } else {
    return 0;
  }
}

void sudoku_solve(Sudoku *s) {
  while (sudoku_rand(s)) {
    int x = rand() % s->size;
    int y = rand() % s->size;
    int num = rand() % s->size + 1;
    if (s->board[x][y] == num) {
      s->board[x][y] = 0;
    } else {
      s->board[x][y] = num;
    }
  }
  s->solved = 1;
}

int main() {
  Sudoku *s = sudoku_new(SUDO_SIZE);
  sudoku_solve(s);
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }
  sudoku_free(s);
  return 0;
}