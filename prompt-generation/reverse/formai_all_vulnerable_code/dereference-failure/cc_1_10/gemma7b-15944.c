//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 9

typedef struct Move {
  int row, col, player;
} Move;

Move makeMove(int **board, int player) {
  Move move;
  move.row = rand() % 3;
  move.col = rand() % 3;
  while (board[move.row][move.col] != 0) {
    move.row = rand() % 3;
    move.col = rand() % 3;
  }
  move.player = player;
  board[move.row][move.col] = player;
  return move;
}

int checkWin(int **board, int player) {
  // Check rows
  for (int r = 0; r < 3; r++) {
    if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < 3; c++) {
    if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player) {
    return 1;
  }

  // If all moves are made and there is no winner, it's a draw
  return 0;
}

int main() {
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int player = 1;
  int moveCount = 0;

  // Play until there is a winner or a draw
  while (!checkWin(board, player) && moveCount < MAX_MOVES) {
    Move move = makeMove(board, player);
    moveCount++;
    player = (player == 1) ? 2 : 1;
  }

  // Print the winner or draw
  if (checkWin(board, player) == 1) {
    printf("Player %d won!", player);
  } else if (moveCount == MAX_MOVES) {
    printf("It's a draw!");
  }

  return 0;
}