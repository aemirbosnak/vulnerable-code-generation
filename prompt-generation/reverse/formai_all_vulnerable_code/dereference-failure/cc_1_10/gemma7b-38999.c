//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
  int row;
  int col;
  char state;
} Cell;

void initializeBoard(Cell **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c].row = r;
      board[r][c].col = c;
      board[r][c].state = ' ';
    }
  }
}

int isBoardFull(Cell **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c].state == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(Cell **board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0].state == board[r][1].state && board[r][0].state == board[r][2].state && board[r][0].state != ' ') {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c].state == board[1][c].state && board[0][c].state == board[2][c].state && board[0][c].state != ' ') {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0].state == board[1][1].state && board[0][0].state == board[2][2].state && board[0][0].state != ' ') {
    return 1;
  }

  // If all cells are full, it's a draw
  if (isBoardFull(board)) {
    return 2;
  }

  return 0;
}

int main() {
  Cell **board = (Cell **)malloc(sizeof(Cell *) * BOARD_SIZE);
  initializeBoard(board);

  int player1 = 1;
  int player2 = 2;
  char currentPlayer = 'X';

  while (!checkWin(board) && !isBoardFull(board)) {
    // Get the move
    int row, col;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &col);

    // Validate the move
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Place the mark
    board[row][col].state = currentPlayer;

    // Switch the player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  // Check if there was a win or a draw
  if (checkWin(board) == 1) {
    printf("Congratulations! You won!");
  } else if (checkWin(board) == 2) {
    printf("It's a draw!");
  } else {
    printf("Invalid move. Game over!");
  }

  return 0;
}