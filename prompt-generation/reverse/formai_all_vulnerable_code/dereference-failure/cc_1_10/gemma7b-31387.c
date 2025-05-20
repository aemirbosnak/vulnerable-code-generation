//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

typedef struct Node {
  struct Node* left;
  struct Node* right;
  int symbol;
  int frequency;
} Node;

struct Node* insertNode(struct Node* node, int symbol, int frequency) {
  if (node == NULL) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->symbol = symbol;
    node->frequency = frequency;
  } else if (symbol < node->symbol) {
    node->left = insertNode(node->left, symbol, frequency);
  } else if (symbol > node->symbol) {
    node->right = insertNode(node->right, symbol, frequency);
  } else {
    node->frequency++;
  }
  return node;
}

void huffmanEncode(struct Node* node, char* buffer, int index) {
  if (node->left == NULL && node->right == NULL) {
    buffer[index] = (node->symbol) + 1;
  } else {
    huffmanEncode(node->left, buffer, index);
    huffmanEncode(node->right, buffer, index);
  }
}

int main() {
  struct Node* root = NULL;
  root = insertNode(root, 1, 5);
  insertNode(root, 2, 3);
  insertNode(root, 3, 4);
  insertNode(root, 4, 2);
  insertNode(root, 5, 6);

  char buffer[1024];
  huffmanEncode(root, buffer, 0);

  printf("%s", buffer);

  return 0;
}