//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 256

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char character;
  int frequency;
} Node;

Node* insert(Node* node, char character, int frequency) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->character = character;
    node->frequency = frequency;
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

  char* buffer = malloc(MAX_TREE_Nodes);
  huffman_encode(root, buffer);

  for (int i = 0; buffer[i] != '\0'; i++) {
    printf("%c: %d ", buffer[i], buffer[i+1]);
  }

  return 0;
}