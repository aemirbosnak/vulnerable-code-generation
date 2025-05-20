//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

typedef struct Cell {
  int alive;
  struct Cell** neighbors;
} Cell;

void initialize_game(Cell** board) {
  for (int r = 0; r < MAX_CELLS; r++) {
    board[r] = malloc(MAX_CELLS * sizeof(Cell));
    for (int c = 0; c < MAX_CELLS; c++) {
      board[r][c].alive = 0;
      board[r][c].neighbors = NULL;
    }
  }
}

void set_cell_alive(Cell** board, int r, int c) {
  board[r][c].alive = 1;
}

void calculate_neighborhood(Cell** board, int r, int c) {
  int num_alive = 0;
  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      if (r + dr >= 0 && r + dr < MAX_CELLS && c + dc >= 0 && c + dc < MAX_CELLS) {
        if (board[r + dr][c + dc].alive) {
          num_alive++;
        }
      }
    }
  }
  board[r][c].alive = num_alive == 2 || num_alive == 3;
}

void simulate_game(Cell** board) {
  for (int r = 0; r < MAX_CELLS; r++) {
    for (int c = 0; c < MAX_CELLS; c++) {
      calculate_neighborhood(board, r, c);
    }
  }
}

int main() {
  Cell** board = NULL;
  initialize_game(&board);
  set_cell_alive(board, 2, 2);
  set_cell_alive(board, 3, 2);
  simulate_game(board);
  for (int r = 0; r < MAX_CELLS; r++) {
    for (int c = 0; c < MAX_CELLS; c++) {
      if (board[r][c].alive) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  return 0;
}