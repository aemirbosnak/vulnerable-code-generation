//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
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
    if (head->x == -1) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}

int main() {
  Node* head = NULL;
  srand(time(NULL));

  // Player's turn to place their mark
  int playerMove = rand() % 2;

  // AI's turn to place their mark
  int aiMove = (playerMove == 0) ? 1 : 0;

  // Place the player's mark
  head = createNode(aiMove, playerMove);

  // Check if the board is full
  if (isBoardFull(head) == 0) {
    // AI's turn to place their mark
    aiMove = (playerMove == 0) ? 2 : 1;
    head = createNode(aiMove, aiMove);
  }

  // Check if the player has won
  if (isBoardFull(head) == 1) {
    // Player has won
    printf("You have won!");
  } else {
    // It's a draw
    printf("It's a draw!");
  }

  return 0;
}