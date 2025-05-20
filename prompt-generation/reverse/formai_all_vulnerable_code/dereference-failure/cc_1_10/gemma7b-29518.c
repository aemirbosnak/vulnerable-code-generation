//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void ConnectNodes(Node* a, Node* b) {
  a->next = b;
}

int CheckWin(Node* node) {
  // Horizontal win
  if (node->x == node->next->x && node->x == node->next->next->x) {
    return 1;
  }

  // Vertical win
  if (node->y == node->next->y && node->y == node->next->next->y) {
    return 1;
  }

  // Diagonal win
  if (node->x == node->next->next->x && node->y == node->next->next->y) {
    return 1;
  }

  // No win
  return 0;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the game board
  Node* board = CreateNode(0, 0);
  ConnectNodes(board, CreateNode(1, 0));
  ConnectNodes(board->next, CreateNode(2, 0));
  ConnectNodes(board->next->next, CreateNode(0, 1));
  ConnectNodes(board->next->next->next, CreateNode(1, 1));
  ConnectNodes(board->next->next->next->next, CreateNode(2, 1));
  ConnectNodes(board->next->next->next->next->next, CreateNode(0, 2));
  ConnectNodes(board->next->next->next->next->next->next, CreateNode(1, 2));
  ConnectNodes(board->next->next->next->next->next->next->next, CreateNode(2, 2));

  // Play the game
  int player = 1;
  while (!CheckWin(board) && board->next) {
    // Get the move
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;

    // Check if the move is valid
    if (board->x == x && board->y == y) {
      continue;
    }

    // Make the move
    Node* move = CreateNode(x, y);
    ConnectNodes(board, move);

    // Switch the player
    player *= -1;
  }

  // Print the winner or a draw
  if (CheckWin(board)) {
    printf("Player %d won!", player);
  } else {
    printf("It's a draw!");
  }

  return 0;
}