//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int next_move;
  int winner;
} Board;

Board *init_board() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(sizeof(int *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
  }

  board->next_move = 0;
  board->winner = -1;

  return board;
}

void place_move(Board *board, int x, int y) {
  if (board->board[x][y] != 0) {
    return;
  }

  board->board[x][y] = board->next_move;
  board->next_move++;
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

  // No winner
  return -1;
}

int main() {
  Board *board = init_board();

  // Play the game
  place_move(board, 1, 1);
  place_move(board, 0, 0);
  place_move(board, 2, 2);
  place_move(board, 1, 0);
  place_move(board, 0, 2);

  // Check for winner
  int winner = check_win(board);

  // Print the winner
  if (winner != -1) {
    printf("Winner: Player %d\n", winner);
  } else {
    printf("Draw\n");
  }

  return 0;
}