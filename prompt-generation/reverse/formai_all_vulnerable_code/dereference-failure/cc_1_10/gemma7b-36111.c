//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
} Node;

Node* insert(Node* node, char character, int frequency) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
  } else if (character < node->character) {
    node->left = insert(node->left, character, frequency);
  } else {
    node->right = insert(node->right, character, frequency);
  }

  return node;
}

void huffman_encode(Node* node, char* buffer) {
  if (node) {
    huffman_encode(node->left, buffer);
    huffman_encode(node->right, buffer);

    buffer[node->character] = node->frequency;
  }
}

int main() {
  Node* root = insert(NULL, 'a', 5);
  insert(root, 'b', 3);
  insert(root, 'c', 2);
  insert(root, 'd', 4);

  char buffer[1000];
  huffman_encode(root, buffer);

  printf("%s", buffer);

  return 0;
}