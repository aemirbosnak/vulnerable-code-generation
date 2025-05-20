//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char character;
  int frequency;
} Node;

struct Node* insert(struct Node* node, char character, int frequency) {
  if (node == NULL) {
    node = (struct Node*)malloc(sizeof(struct Node));
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

void huffman_encode(struct Node* node, char* buffer) {
  if (node) {
    buffer[0] = '\0';
    huffman_encode(node->left, buffer);
    huffman_encode(node->right, buffer);
    sprintf(buffer, "%s%c", buffer, node->character);
  }
}

int main() {
  struct Node* root = insert(NULL, 'a', 5);
  insert(root, 'b', 3);
  insert(root, 'c', 2);
  insert(root, 'd', 4);
  insert(root, 'e', 3);

  char* buffer = (char*)malloc(1024);
  huffman_encode(root, buffer);

  printf("%s", buffer);

  return 0;
}