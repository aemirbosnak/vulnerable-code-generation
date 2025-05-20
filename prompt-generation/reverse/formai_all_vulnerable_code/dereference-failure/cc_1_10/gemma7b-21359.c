//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

int main() {
  int i, j, player, move, board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  Node* head = NULL;

  // Initialize the board
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }

  // Create the move list
  head = createNode(0, 0);

  // Game loop
  while (1) {
    // Get the player's move
    printf("Enter your move (x, y): ");
    scanf("%d %d", &move, &move);

    // Check if the move is valid
    if (board[move][move] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    // Place the player's mark on the board
    board[move][move] = player;

    // Add the move to the move list
    Node* newNode = createNode(move, move);
    newNode->next = head;
    head = newNode;

    // Check if the player has won
    if (checkWin(board, player) == 1) {
      printf("You won!\n");
      break;
    }

    // If the board is full, it's a draw
    if (isBoardFull(board) == 1) {
      printf("It's a draw.\n");
      break;
    }

    // Switch to the next player
    player *= -1;
  }

  // Print the move list
  printf("Move list:\n");
  for (Node* node = head; node; node = node->next) {
    printf("(%d, %d)\n", node->x, node->y);
  }

  return 0;
}

int checkWin(int** board, int player) {
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

int isBoardFull(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}