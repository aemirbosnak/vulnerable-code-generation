//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 64

typedef struct Node {
  int move;
  struct Node* next;
} Node;

Node* createNode(int move) {
  Node* newNode = malloc(sizeof(Node));
  newNode->move = move;
  newNode->next = NULL;
  return newNode;
}

int main() {
  time_t start, end;
  start = time(NULL);

  // Board representation
  int board[BOARD_SIZE] = {0};

  // Game logic
  int move = 0;
  Node* moves = NULL;
  while (board[move] != 1) {
    // Generate move
    move = rand() % BOARD_SIZE;

    // Create new move node
    Node* newNode = createNode(move);

    // Add move node to list
    if (moves) {
      newNode->next = moves;
    } else {
      moves = newNode;
    }

    // Make move on board
    board[move] = 1;
  }

  end = time(NULL);
  printf("Time taken: %ld seconds\n", end - start);

  // Print move list
  Node* current = moves;
  while (current) {
    printf("Move: %d\n", current->move);
    current = current->next;
  }

  return 0;
}