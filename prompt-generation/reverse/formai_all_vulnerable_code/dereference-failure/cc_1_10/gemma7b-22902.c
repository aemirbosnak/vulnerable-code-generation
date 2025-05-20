//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct GameBoard {
  char board[BOARD_SIZE][BOARD_SIZE];
  char currentPlayer;
  int gameStatus;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
  board->currentPlayer = PLAYER_X;
  board->gameStatus = 0;
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board->board[r][c] = ' ';
    }
  }
}

int checkWin(GameBoard *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != ' ') {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != ' ') {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
    return 1;
  }

  // If all cells are occupied and no winner, it's a draw
  return 2;
}

void playGame(GameBoard *board) {
  int moveMade = 0;
  while (board->gameStatus == 0) {
    int row, column;
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &column);

    // Validate move
    if (board->board[row][column] != ' ' || row < 1 || row > BOARD_SIZE || column < 1 || column > BOARD_SIZE) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make move
    board->board[row][column] = board->currentPlayer;
    moveMade = 1;

    // Check if there is a winner or draw
    if (checkWin(board) == 1) {
      board->gameStatus = 1;
      printf("Winner: %c!\n", board->currentPlayer);
    } else if (moveMade == 9) {
      board->gameStatus = 2;
      printf("It's a draw!\n");
    } else {
      board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
  }
}

int main() {
  GameBoard board;
  initializeGameBoard(&board);
  playGame(&board);

  return 0;
}