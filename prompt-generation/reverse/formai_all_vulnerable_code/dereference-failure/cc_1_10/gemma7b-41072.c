//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void initBoard(int **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = 0;
    }
  }
}

int isBoardFull(int **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(int **board, int player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}

int main() {
  int **board = (int**)malloc(BOARD_SIZE * sizeof(int*));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
  }

  initBoard(board);

  int player = 1;
  int gameWon = 0;

  while (!gameWon && !isBoardFull(board)) {
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (board[x][y] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    board[x][y] = player;

    gameWon = checkWin(board, player);

    if (gameWon) {
      printf("You won!");
    } else {
      player = (player == 1) ? 2 : 1;
    }
  }

  if (gameWon) {
    printf("You won!");
  } else {
    printf("It's a draw.");
  }

  free(board);

  return 0;
}