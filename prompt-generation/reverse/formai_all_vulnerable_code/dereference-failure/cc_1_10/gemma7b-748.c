//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 1024

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char character;
  int frequency;
} Node;

void insertNode(Node** node, char character, int frequency) {
  if (*node == NULL) {
    *node = malloc(sizeof(Node));
  }

  (*node)->character = character;
  (*node)->frequency = frequency;
  (*node)->left = NULL;
  (*node)->right = NULL;
}

void huffmanCode(Node* node) {
  if (node) {
    huffmanCode(node->left);
    huffmanCode(node->right);

    printf("%c: ", node->character);
    for (int i = 0; i < node->frequency; i++) {
      printf("0");
    }
    printf("\n");
  }
}

int main() {
  Node* root = NULL;

  insertNode(&root, 'a', 5);
  insertNode(&root, 'b', 3);
  insertNode(&root, 'c', 2);
  insertNode(&root, 'd', 4);
  insertNode(&root, 'e', 6);

  huffmanCode(root);

  return 0;
}