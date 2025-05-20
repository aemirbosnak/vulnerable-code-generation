//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int size;
  struct Sudoku *next;
} Sudoku;

Sudoku *Sudoku_create(int size) {
  Sudoku *sudoku = malloc(sizeof(Sudoku));
  sudoku->board = malloc(size * size * sizeof(int));
  sudoku->size = size;
  sudoku->next = NULL;

  for (int i = 0; i < size * size; i++) {
    sudoku->board[i] = 0;
  }

  return sudoku;
}

void Sudoku_solve(Sudoku *sudoku) {
  if (sudoku->board[0][0] != 0) {
    return;
  }

  for (int r = 0; r < sudoku->size; r++) {
    for (int c = 0; c < sudoku->size; c++) {
      if (sudoku->board[r][c] == 0) {
        for (int n = 1; n <= sudoku->size; n++) {
          if (sudoku->board[r][n] == 0 && sudoku->board[n][c] == 0 && sudoku->board[r][n] == 0) {
            sudoku->board[r][c] = n;
            Sudoku_solve(sudoku);
            sudoku->board[r][c] = 0;
          }
        }
      }
    }
  }

  return;
}

int main() {
  Sudoku *sudoku = Sudoku_create(9);

  // Generate a sudoku puzzle
  sudoku->board[0][0] = 5;
  sudoku->board[0][1] = 3;
  sudoku->board[0][2] = 0;
  sudoku->board[1][0] = 6;
  sudoku->board[1][1] = 0;
  sudoku->board[1][2] = 0;
  sudoku->board[2][0] = 0;
  sudoku->board[2][1] = 9;
  sudoku->board[2][2] = 0;

  Sudoku_solve(sudoku);

  // Print the solution
  for (int r = 0; r < sudoku->size; r++) {
    for (int c = 0; c < sudoku->size; c++) {
      printf("%d ", sudoku->board[r][c]);
    }
    printf("\n");
  }

  return 0;
}