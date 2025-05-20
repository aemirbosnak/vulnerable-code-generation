//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void initializeBoard(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void drawBoard(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int isBoardFull(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(int** board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
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
  int** board = NULL;
  initializeBoard(&board);

  int player = 1;
  int gameWon = 0;

  // Game loop
  while (!gameWon && !isBoardFull(board)) {
    drawBoard(board);

    int moveX, moveY;
    printf("Enter move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    if (board[moveX][moveY] != 0) {
      printf("Error: move already made.\n");
      continue;
    }

    board[moveX][moveY] = player;

    gameWon = checkWin(board, player);

    if (gameWon) {
      drawBoard(board);
      printf("Game won by player %d!\n", player);
    } else {
      player = (player == 1) ? 2 : 1;
    }
  }

  if (isBoardFull(board)) {
    drawBoard(board);
    printf("It's a draw!\n");
  }

  return 0;
}