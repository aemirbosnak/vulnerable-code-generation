//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void initializeBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void placeMark(int **board, int x, int y, int player) {
  board[x][y] = player;
}

int isBoardFull(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(int **board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
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
  int **board = NULL;
  board = (int**)malloc(BOARD_SIZE * sizeof(int*));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
  }

  initializeBoard(board);

  int player = 1;
  int gameWon = 0;

  while (!gameWon && !isBoardFull(board)) {
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    placeMark(board, x, y, player);

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
    printf("It's a draw!");
  }

  free(board);

  return 0;
}