//Gemma-7B DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define PLAYER_COUNT 2

typedef struct GameBoard {
  int **board;
  int turn;
  int winner;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }
  board->turn = 0;
  board->winner = -1;
}

void placeMarker(GameBoard *board, int x, int y) {
  if (board->board[x][y] == -1) {
    board->board[x][y] = board->turn;
  }
}

int checkWin(GameBoard *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != -1) {
      return board->board[0][i];
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[i][0] == board->board[i][1] && board->board[i][0] == board->board[i][2] && board->board[i][0] != -1) {
      return board->board[i][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != -1) {
    return board->board[0][0];
  }

  // No winner
  return -1;
}

int main() {
  GameBoard board;
  initializeGameBoard(&board);

  // Play the game
  placeMarker(&board, 1, 1);
  placeMarker(&board, 2, 0);
  placeMarker(&board, 1, 0);
  placeMarker(&board, 2, 1);
  placeMarker(&board, 1, 2);

  int winner = checkWin(&board);

  // Print the winner
  if (winner != -1) {
    printf("Winner: Player %d\n", winner);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}