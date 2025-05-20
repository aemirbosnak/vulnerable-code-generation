//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

int isBoardFull(Node* head) {
  while (head) {
    if (head->x == -1 && head->y == -1) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}

int main() {
  Node* head = NULL;
  int i, j;

  // Initialize the board
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      head = createNode(i, j);
      head->x = -1;
      head->y = -1;
      head = head->next;
    }
  }

  // Play the game
  while (!isBoardFull(head)) {
    // Get the move from the user
    int moveX, moveY;

    // Make the move
    head = createNode(moveX, moveY);
    head->x = moveX;
    head->y = moveY;

    // Check if the user won or if the board is full
    if (isBoardFull(head)) {
      printf("Draw!\n");
    } else if (head->x == 0 && head->y == 0) {
      printf("Player 1 won!\n");
    } else if (head->x == 2 && head->y == 2) {
      printf("Player 2 won!\n");
    }
  }

  return 0;
}