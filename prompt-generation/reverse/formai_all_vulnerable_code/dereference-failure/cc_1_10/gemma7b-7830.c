//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
  int move;
  struct Node* next;
} Node;

Node* createNode(int move) {
  Node* node = malloc(sizeof(Node));
  node->move = move;
  node->next = NULL;
  return node;
}

void insertNode(Node* node, int move) {
  Node* newNode = createNode(move);
  if (node == NULL) {
    node = newNode;
  } else {
    node->next = newNode;
    node = newNode;
  }
}

int main() {
  // Create a move list
  Node* moveList = NULL;

  // Generate moves
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    insertNode(moveList, i);
  }

  // Shuffle the move list
  srand(time(NULL));
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    int index = rand() % moveList->next->move;
    Node* tmpNode = moveList;
    moveList = moveList->next;
    insertNode(moveList, tmpNode->move);
    free(tmpNode);
  }

  // Print the shuffled move list
  for (Node* node = moveList; node; node++) {
    printf("%d ", node->move);
  }
  printf("\n");

  return 0;
}