//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 1024

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

void huffmanEncode(struct Node* node, char* buffer) {
  if (node) {
    huffmanEncode(node->left, buffer);
    huffmanEncode(node->right, buffer);

    buffer[node->character] = node->frequency;
  }
}

int main() {
  struct Node* root = insertNode(NULL, 'a', 5);
  insertNode(root, 'b', 3);
  insertNode(root, 'c', 2);
  insertNode(root, 'd', 4);
  insertNode(root, 'e', 6);

  char buffer[MAX_TREE_SIZE] = "";

  huffmanEncode(root, buffer);

  printf("Huffman encoded: ");
  for (int i = 0; buffer[i] != '\0'; i++) {
    printf("%c ", buffer[i]);
  }

  printf("\n");

  return 0;
}