//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char symbol;
  int frequency;
} Node;

void insertNode(Node* node, char symbol, int frequency) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->symbol = symbol;
    node->frequency = frequency;
  } else if (frequency < node->frequency) {
    insertNode(node->left, symbol, frequency);
  } else {
    insertNode(node->right, symbol, frequency);
  }
}

void huffmanEncode(Node* node, char* buffer, int index) {
  if (node) {
    buffer[index] = node->symbol;
    index++;
    huffmanEncode(node->left, buffer, index);
    huffmanEncode(node->right, buffer, index);
  }
}

int main() {
  Node* root = NULL;
  insertNode(root, 'a', 5);
  insertNode(root, 'b', 3);
  insertNode(root, 'c', 2);
  insertNode(root, 'd', 4);
  insertNode(root, 'e', 3);

  char* buffer = malloc(1024);
  huffmanEncode(root, buffer, 0);

  printf("%s", buffer);

  free(buffer);
  return 0;
}