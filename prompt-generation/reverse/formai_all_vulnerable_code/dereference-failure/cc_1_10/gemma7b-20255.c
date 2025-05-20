//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void makeMove(Node** board, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*board == NULL) {
    *board = newNode;
  } else {
    (*board)->next = newNode;
  }
}

int checkWin(Node* board) {
  // Check rows
  for (int i = 0; i < MAX_SIZE; i++) {
    if (board->x == board->next->x && board->x == board->next->next->x) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < MAX_SIZE; i++) {
    if (board->y == board->next->y && board->y == board->next->next->y) {
      return 1;
    }
  }

  // Check diagonals
  if (board->x == board->next->y && board->x == board->next->next->x) {
    return 1;
  }

  // If no win, return 0
  return 0;
}

int main() {
  // Initialize the game board
  Node* board = NULL;

  // Player 1 moves
  makeMove(&board, 0, 0);
  makeMove(&board, 1, 1);
  makeMove(&board, 0, 2);

  // Player 2 moves
  makeMove(&board, 2, 0);

  // Check if Player 1 won
  if (checkWin(board) == 1) {
    printf("Player 1 won!");
  }

  // If no winner, it's a draw
  else {
    printf("It's a draw!");
  }

  return 0;
}