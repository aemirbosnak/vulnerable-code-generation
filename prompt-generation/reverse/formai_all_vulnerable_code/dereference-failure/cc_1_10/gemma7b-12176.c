//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 256

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char symbol;
  int frequency;
} Node;

void insert(Node* node, char symbol, int frequency) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->symbol = symbol;
    node->frequency = frequency;
  } else if (frequency < node->frequency) {
    insert(node->left, symbol, frequency);
  } else {
    insert(node->right, symbol, frequency);
  }
}

void huffman_encode(Node* node, char* buffer) {
  if (node) {
    buffer[0] = '\0';
    huffman_encode(node->left, buffer);
    huffman_encode(node->right, buffer);
    sprintf(buffer, "%s%c", buffer, node->symbol);
  }
}

int main() {
  Node* root = NULL;
  insert(root, 'a', 5);
  insert(root, 'b', 3);
  insert(root, 'c', 2);
  insert(root, 'd', 4);
  insert(root, 'e', 4);

  char* buffer = (char*)malloc(1024);
  huffman_encode(root, buffer);
  printf("%s", buffer);

  free(buffer);
  return 0;
}