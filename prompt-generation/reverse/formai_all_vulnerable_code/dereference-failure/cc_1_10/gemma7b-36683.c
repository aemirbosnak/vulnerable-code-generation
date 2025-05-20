//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void printBoard(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int checkWin(int** board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
    return 1;
  }

  // If all cells are filled and there is no winner, it's a draw
  return 0;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int player = 1;
  int gameWon = 0;

  // Seed the random number generator
  srand(time(NULL));

  // Play until someone wins or there is a draw
  while (!gameWon) {
    // Get the player's move
    int moveX = rand() % BOARD_SIZE;
    int moveY = rand() % BOARD_SIZE;

    // Check if the move is valid
    if (board[moveX][moveY] == 0) {
      // Make the move
      board[moveX][moveY] = player;

      // Check if the player has won
      gameWon = checkWin(board);

      // If the player has won, print the board and announce the winner
      if (gameWon) {
        printBoard(board);
        printf("Winner: Player %d!\n", player);
      }

      // Increment the player's turn
      player *= -1;
    }
  }

  // If the game is a draw, print the board and announce the draw
  if (!gameWon) {
    printBoard(board);
    printf("Draw!\n");
  }

  return 0;
}