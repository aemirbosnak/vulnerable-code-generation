//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
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

int isBoardFull(Node* head) {
  while (head) {
    if (head->x == BOARD_SIZE - 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  Node* head = NULL;
  srand(time(NULL));

  // Player's move
  int move_x = rand() % BOARD_SIZE;
  int move_y = rand() % BOARD_SIZE;

  // AI's move
  int ai_x = rand() % BOARD_SIZE;
  int ai_y = rand() % BOARD_SIZE;

  // Place the moves
  head = createNode(move_x, move_y);
  head = createNode(ai_x, ai_y);

  // Check if the board is full
  if (isBoardFull(head)) {
    printf("Board is full!\n");
  } else {
    printf("Move: (%d, %d) - AI's move: (%d, %d)\n", move_x, move_y, ai_x, ai_y);
  }

  return 0;
}