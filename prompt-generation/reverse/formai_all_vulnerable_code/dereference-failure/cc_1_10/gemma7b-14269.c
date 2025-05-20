//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **cells;
  int current_player;
  int game_state;
} Board;

Board *create_board() {
  Board *board = malloc(sizeof(Board));
  board->cells = malloc(sizeof(int *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->cells[i] = malloc(sizeof(int) * BOARD_SIZE);
  }
  board->current_player = 1;
  board->game_state = 0;
  return board;
}

void place_mark(Board *board, int row, int col) {
  if (board->cells[row][col] == 0) {
    board->cells[row][col] = board->current_player;
  }
}

int check_win(Board *board, int player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    if (board->cells[0][i] == player && board->cells[1][i] == player && board->cells[2][i] == player) {
      return 1;
    }

    // Check columns
    if (board->cells[i][0] == player && board->cells[i][1] == player && board->cells[i][2] == player) {
      return 1;
    }

    // Check diagonals
    if (board->cells[0][0] == player && board->cells[1][1] == player && board->cells[2][2] == player) {
      return 1;
    }
  }

  return 0;
}

int main() {
  Board *board = create_board();

  // Game loop
  while (!check_win(board, board->current_player) && board->game_state == 0) {
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    place_mark(board, row, col);

    board->current_player *= -1;
  }

  // Game over
  if (check_win(board, board->current_player)) {
    printf("Winner: Player %d\n", board->current_player);
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}