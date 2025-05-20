//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printBoard(int **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

void makeMove(int **board, int player) {
  int move = rand() % 9;
  while (board[move / BOARD_SIZE][move % BOARD_SIZE] != 0) {
    move = rand() % 9;
  }
  board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
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

  // If all moves are made and there is no winner, it's a draw
  return 0;
}

int main() {
  int **board = (int**)malloc(BOARD_SIZE * sizeof(int*));
  for (int r = 0; r < BOARD_SIZE; r++) {
    board[r] = (int*)malloc(BOARD_SIZE * sizeof(int));
  }

  int player = 1;
  for (int i = 0; i < 9; i++) {
    makeMove(board, player);
    printBoard(board);

    if (checkWin(board, player) == 1) {
      printf("Player %d won!", player);
      break;
    } else if (checkWin(board, player) == 0) {
      printf("It's a draw!");
      break;
    }

    player = (player == 1) ? 2 : 1;
  }

  free(board);

  return 0;
}