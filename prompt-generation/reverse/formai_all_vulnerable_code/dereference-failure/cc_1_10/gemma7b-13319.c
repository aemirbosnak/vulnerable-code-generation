//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int turn;
  int winner;
} Board;

void initializeBoard(Board *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }

  board->turn = 0;
  board->winner = 0;
}

int isBoardFull(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->board[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int hasPlayerWon(Board *board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
    return 1;
  } else if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
    return 1;
  }

  return 0;
}

void makeMove(Board *board, int player) {
  int move = rand() % 9;

  while (board->board[move / BOARD_SIZE][move % BOARD_SIZE] != 0) {
    move = rand() % 9;
  }

  board->board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
  board->turn++;
}

int main() {
  Board board;
  initializeBoard(&board);

  // Play until someone wins or the board is full
  while (!hasPlayerWon(&board, 1) && !isBoardFull(&board)) {
    makeMove(&board, 1);
    makeMove(&board, 2);
  }

  // Print the winner or draw
  if (hasPlayerWon(&board, 1)) {
    printf("Player 1 won!");
  } else if (isBoardFull(&board)) {
    printf("It's a draw!");
  } else {
    printf("An error occurred!");
  }

  return 0;
}