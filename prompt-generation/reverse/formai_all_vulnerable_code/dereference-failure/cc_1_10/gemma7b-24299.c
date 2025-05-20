//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

void initializeBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void displayBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void placeMove(int **board, int player) {
  int moveValid = 0;
  Node* head = NULL;
  while (!moveValid) {
    printf("Enter your move (e.g. 0-2, 0-2): ");
    int x, y;
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
      printf("Invalid move. Please try again.\n");
    } else if (board[x][y] != 0) {
      printf("That spot is already taken. Please try again.\n");
    } else {
      moveValid = 1;
      board[x][y] = player;
      head = malloc(sizeof(Node));
      head->x = x;
      head->y = y;
      head->next = NULL;
    }
  }
  return;
}

int checkWin(int **board, int player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return 1;
    }
  }

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  return 0;
}

int main() {
  int **board = NULL;
  initializeBoard(board);

  int player = 1;
  int gameWon = 0;

  while (!gameWon) {
    placeMove(board, player);
    displayBoard(board);

    if (checkWin(board, player) == 1) {
      gameWon = 1;
      printf("You won!");
    } else if (checkWin(board, player) == 0) {
      gameWon = 1;
      printf("The computer won!");
    } else if (board[0][0] == board[1][1] == board[2][2] == 0) {
      gameWon = 1;
      printf("It's a draw!");
    }
    player *= -1;
  }

  return 0;
}