//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
  int symbol;
  struct Node* left;
  struct Node* right;
} Node;

Node* insertNode(Node* node, int symbol) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;
  } else if (symbol < node->symbol) {
    node->left = insertNode(node->left, symbol);
  } else {
    node->right = insertNode(node->right, symbol);
  }

  return node;
}

void huffmanEncode(Node* node, char* buffer, int index) {
  if (node == NULL) {
    return;
  }

  buffer[index] = node->symbol;
  index++;

  huffmanEncode(node->left, buffer, index);
  huffmanEncode(node->right, buffer, index);
}

int main() {
  Node* root = insertNode(NULL, 10);
  insertNode(root, 20);
  insertNode(root, 30);
  insertNode(root, 40);
  insertNode(root, 50);
  insertNode(root, 60);

  char* buffer = (char*)malloc(1024);

  huffmanEncode(root, buffer, 0);

  printf("Encoded data: ");
  for (int i = 0; buffer[i] != '\0'; i++) {
    printf("%c ", buffer[i]);
  }

  printf("\n");

  return 0;
}