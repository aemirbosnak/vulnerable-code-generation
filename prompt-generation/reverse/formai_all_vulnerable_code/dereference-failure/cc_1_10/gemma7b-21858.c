//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void initializeBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY_SPOT;
    }
  }
}

int isBoardFull(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY_SPOT) {
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

void makeMove(int **board, int player) {
  int move = rand() % 9;

  while (board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY_SPOT) {
    move = rand() % 9;
  }

  board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
}

int main() {
  int **board;
  initializeBoard(&board);

  int player = PLAYER_X;
  int gameWon = 0;

  while (!gameWon && !isBoardFull(board)) {
    makeMove(board, player);

    if (checkWin(board, player) == 1) {
      gameWon = 1;
    }

    player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  if (gameWon) {
    printf("You won!");
  } else {
    printf("It's a draw!");
  }

  return 0;
}