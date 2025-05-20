//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20
#define MAX_WATER 10

typedef struct PercolationBoard {
  int **board;
  int water_level;
  int num_rows;
  int num_cols;
} PercolationBoard;

PercolationBoard *create_percolation_board(int num_rows, int num_cols) {
  PercolationBoard *board = malloc(sizeof(PercolationBoard));
  board->board = malloc(num_rows * num_cols * sizeof(int));
  board->water_level = 0;
  board->num_rows = num_rows;
  board->num_cols = num_cols;
  return board;
}

void fill_board(PercolationBoard *board) {
  for (int r = 0; r < board->num_rows; r++) {
    for (int c = 0; c < board->num_cols; c++) {
      board->board[r][c] = rand() % MAX_WATER;
    }
  }
}

void simulate_percolation(PercolationBoard *board) {
  for (int r = 0; r < board->num_rows; r++) {
    for (int c = 0; c < board->num_cols; c++) {
      if (board->board[r][c] > board->water_level) {
        board->board[r][c] = board->water_level;
      }
    }
  }
}

void print_board(PercolationBoard *board) {
  for (int r = 0; r < board->num_rows; r++) {
    for (int c = 0; c < board->num_cols; c++) {
      printf("%d ", board->board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  PercolationBoard *board = create_percolation_board(DIM, DIM);
  fill_board(board);
  simulate_percolation(board);
  print_board(board);

  free(board->board);
  free(board);

  return 0;
}