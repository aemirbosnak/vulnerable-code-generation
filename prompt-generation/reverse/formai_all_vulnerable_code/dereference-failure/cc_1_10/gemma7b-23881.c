//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* newNode(int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void placeMove(Node* board, int x, int y) {
  board->x = x;
  board->y = y;
  board->next = newNode(x, y);
}

int checkWin(Node* board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->x == board->next->x && board->x == board->next->next->x) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->y == board->next->y && board->y == board->next->next->y) {
      return 1;
    }
  }

  // Check diagonals
  if (board->x == board->next->y && board->x == board->next->next->x) {
    return 1;
  }

  // If all checks fail, return 0
  return 0;
}

int main() {
  // Create a board
  Node* board = newNode(0, 0);

  // Play the game
  int gameWon = 0;
  while (!gameWon) {
    // Get the player's move
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Place the move
    placeMove(board, x, y);

    // Check if the player won
    gameWon = checkWin(board);

    // If the player won, print the winner
    if (gameWon) {
      printf("Congratulations! You won!");
    }
  }

  return 0;
}