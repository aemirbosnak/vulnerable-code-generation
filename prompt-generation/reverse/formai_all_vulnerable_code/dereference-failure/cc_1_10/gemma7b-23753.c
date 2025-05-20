//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
  int **board;
  int **visited;
  int **candidates;
} Sudoku;

Sudoku* sudoku_new() {
  Sudoku* s = malloc(sizeof(Sudoku));
  s->board = malloc(sizeof(int*) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
  }
  s->visited = malloc(sizeof(int*) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
  }
  s->candidates = malloc(sizeof(int*) * SUDO_SIZE);
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
  }
  return s;
}

void sudoku_free(Sudoku* s) {
  for (int i = 0; i < SUDO_SIZE; i++) {
    free(s->board[i]);
  }
  free(s->board);
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

void sudoku_solve(Sudoku* s) {
  if (sudoku_is_solved(s)) {
    return;
  }
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      if (s->visited[i][j] || s->board[i][j] != 0) {
        continue;
      }
      for (int k = 1; k <= SUDO_SIZE; k++) {
        if (sudoku_is_valid(s, i, j, k)) {
          s->board[i][j] = k;
          s->candidates[i][j] = k;
          sudoku_solve(s);
          s->board[i][j] = 0;
          s->candidates[i][j] = 0;
        }
      }
    }
  }
}

int sudoku_is_solved(Sudoku* s) {
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      if (s->board[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int sudoku_is_valid(Sudoku* s, int i, int j, int k) {
  if (s->visited[i][j] || s->board[i][j] != 0) {
    return 0;
  }
  for (int l = 0; l < SUDO_SIZE; l++) {
    if (s->board[l][j] == k) {
      return 0;
    }
  }
  for (int m = 0; m < SUDO_SIZE; m++) {
    if (s->board[i][m] == k) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Sudoku* s = sudoku_new();
  sudoku_solve(s);
  sudoku_free(s);
  return 0;
}