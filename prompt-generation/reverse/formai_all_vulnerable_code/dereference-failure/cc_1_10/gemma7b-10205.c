//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
  int move;
  struct Node** children;
  struct Node* parent;
} Node;

Node** createNode() {
  Node** node = malloc(sizeof(Node*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    node[i] = NULL;
  }
  return node;
}

void makeMove(Node* node, int move) {
  if (node->children[move] != NULL) {
    return;
  }
  node->children[move] = createNode();
  node->children[move]->move = move;
  node->children[move]->parent = node;
}

int evaluateBoard(Node* node) {
  if (node->children[0] == NULL && node->children[1] == NULL && node->children[2] == NULL) {
    return 0;
  }
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (node->children[i]->move == node->children[0]->move && node->children[i]->move == node->children[1]->move && node->children[i]->move == node->children[2]->move) {
      return 1;
    }
  }
  return -1;
}

int main() {
  Node* root = createNode();
  makeMove(root, 0);
  makeMove(root, 2);
  makeMove(root, 1);
  makeMove(root, 0);
  makeMove(root, 2);
  makeMove(root, 1);
  int result = evaluateBoard(root);
  if (result == 1) {
    printf("Player 1 won!");
  } else if (result == -1) {
    printf("No winner");
  } else {
    printf("Player 2 won!");
  }
  return 0;
}