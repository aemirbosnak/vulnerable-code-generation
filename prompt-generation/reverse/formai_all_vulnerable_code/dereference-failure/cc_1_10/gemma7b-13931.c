//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
} Node;

void insert(Node* node, char character, int frequency) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
  } else if (character < node->character) {
    insert(node->left, character, frequency);
  } else {
    insert(node->right, character, frequency);
  }
}

void huffman_encode(Node* node, char* buffer) {
  if (node) {
    huffman_encode(node->left, buffer);
    huffman_encode(node->right, buffer);

    buffer[node->character] = node->frequency;
  }
}

int main() {
  Node* root = NULL;
  char* buffer = NULL;

  insert(root, 'a', 5);
  insert(root, 'b', 3);
  insert(root, 'c', 4);
  insert(root, 'd', 2);

  buffer = malloc(10);

  huffman_encode(root, buffer);

  for (int i = 0; i < 10; i++) {
    printf("%c ", buffer[i]);
  }

  return 0;
}