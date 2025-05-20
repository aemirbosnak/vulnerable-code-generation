//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
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
  // Horizontal win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  // Vertical win
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
      return 1;
    }
  }

  // Diagonal win
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  // Draw
  if (isBoardFull(board)) {
    return 2;
  }

  return 0;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  initializeBoard(board);

  int player = 1;
  int move = 0;

  while (!checkWin(board, player) && move < 9) {
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (board[x][y] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    board[x][y] = player;
    move++;
  }

  checkWin(board, player);

  return 0;
}