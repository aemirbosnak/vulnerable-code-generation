//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
} Node;

struct Node* insertNode(struct Node* node, char character, int frequency) {
  if (node == NULL) {
    node = malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
  } else if (character < node->character) {
    node->left = insertNode(node->left, character, frequency);
  } else {
    node->right = insertNode(node->right, character, frequency);
  }

  return node;
}

void huffmanEncode(struct Node* node, char* buffer, int index) {
  if (node) {
    buffer[index] = node->character;
    index++;

    huffmanEncode(node->left, buffer, index);
    huffmanEncode(node->right, buffer, index);
  }
}

int main() {
  struct Node* root = insertNode(NULL, 'a', 5);
  insertNode(root, 'b', 3);
  insertNode(root, 'c', 2);
  insertNode(root, 'd', 4);
  insertNode(root, 'e', 6);

  char* buffer = malloc(100);

  huffmanEncode(root, buffer, 0);

  printf("%s", buffer);

  return 0;
}