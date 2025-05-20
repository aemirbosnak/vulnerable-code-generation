//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1024

struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
};

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

void huffmanCode(struct Node* node) {
  if (node) {
    printf("%c: ", node->character);
    for (struct Node* parent = node->left; parent; parent = parent->right) {
      printf("%c ", parent->character);
    }
    printf("\n");
    huffmanCode(node->left);
    huffmanCode(node->right);
  }
}

int main() {
  struct Node* root = insertNode(NULL, 'a', 5);
  insertNode(root, 'b', 3);
  insertNode(root, 'c', 2);
  insertNode(root, 'd', 4);
  insertNode(root, 'e', 6);

  huffmanCode(root);

  return 0;
}