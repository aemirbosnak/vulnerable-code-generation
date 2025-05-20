//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int turn;
} Board;

Board *init_board() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
  board->turn = 0;
  return board;
}

void place_mark(Board *board, int x, int y) {
  if (board->board[x][y] != 0) {
    return;
  }
  board->board[x][y] = board->turn;
}

int check_win(Board *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[0][r] == board->board[1][r] && board->board[0][r] == board->board[2][r] && board->board[0][r] != 0) {
      return board->board[0][r];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[c][0] == board->board[c][1] && board->board[c][0] == board->board[c][2] && board->board[c][0] != 0) {
      return board->board[c][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all cells are occupied and there is no winner, it's a draw
  return 0;
}

int main() {
  Board *board = init_board();

  // Play the game
  place_mark(board, 1, 1);
  place_mark(board, 2, 0);
  place_mark(board, 0, 0);
  place_mark(board, 1, 0);
  place_mark(board, 2, 2);
  place_mark(board, 0, 2);

  // Check if there is a winner or a draw
  int winner = check_win(board);

  // Print the winner or draw
  if (winner) {
    printf("Player %d won!", winner);
  } else {
    printf("It's a draw!");
  }

  return 0;
}