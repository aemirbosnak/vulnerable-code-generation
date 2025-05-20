//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Turing
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int winner;
} Board;

void init_board(Board *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }
  board->current_player = 1;
  board->winner = 0;
}

void place_mark(Board *board, int row, int col) {
  if (board->board[row][col] != 0) {
    return;
  }
  board->board[row][col] = board->current_player;
  board->current_player *= -1;
}

int check_win(Board *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
      return board->board[r][0];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
      return board->board[0][c];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // No winner
  return 0;
}

int main() {
  Board board;
  init_board(&board);

  // Play the game
  place_mark(&board, 1, 1);
  place_mark(&board, 2, 0);
  place_mark(&board, 0, 2);
  place_mark(&board, 1, 2);
  place_mark(&board, 2, 2);

  // Check if there is a winner
  int winner = check_win(&board);

  // Print the winner
  if (winner != 0) {
    printf("The winner is player %d.\n", winner);
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}