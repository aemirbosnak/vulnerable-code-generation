//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1024

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char character;
  int frequency;
} Node;

void insert(Node* node, char character, int frequency) {
  if (node == NULL) {
    node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->character = character;
    node->frequency = frequency;
  } else if (character < node->character) {
    insert(node->left, character, frequency);
  } else {
    insert(node->right, character, frequency);
  }
}

void huffman_encode(Node* node, char* buffer) {
  if (node) {
    buffer[0] = '\0';
    huffman_encode(node->left, buffer);
    huffman_encode(node->right, buffer);
    sprintf(buffer, "%c%s", node->character, buffer);
  }
}

int main() {
  Node* root = NULL;
  insert(root, 'a', 5);
  insert(root, 'b', 3);
  insert(root, 'c', 2);
  insert(root, 'd', 4);
  insert(root, 'e', 3);

  char* buffer = malloc(MAX_TREE_SIZE);
  huffman_encode(root, buffer);

  printf("%s", buffer);

  return 0;
}