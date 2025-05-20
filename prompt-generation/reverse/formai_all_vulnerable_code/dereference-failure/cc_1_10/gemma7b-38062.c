//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
  char character;
  int frequency;
  struct Node* left;
  struct Node* right;
} Node;

void insert(Node** root, char character, int frequency) {
  if (*root == NULL) {
    *root = malloc(sizeof(Node));
    (*root)->character = character;
    (*root)->frequency = frequency;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else {
    insert((*root)->left, character, frequency);
    if ((*root)->left == NULL) {
      (*root)->right = malloc(sizeof(Node));
      ((*root)->right)->character = character;
      ((*root)->right)->frequency = frequency;
      ((*root)->right)->left = NULL;
      ((*root)->right)->right = NULL;
    }
  }
}

void huffman_encode(Node* root, char* buffer, int* index) {
  if (root) {
    huffman_encode(root->left, buffer, index);
    huffman_encode(root->right, buffer, index);
    buffer[*index] = root->character;
    (*index)++;
  }
}

int main() {
  Node* root = NULL;
  insert(&root, 'a', 5);
  insert(&root, 'b', 3);
  insert(&root, 'c', 2);
  insert(&root, 'd', 4);
  insert(&root, 'e', 3);

  char buffer[1024];
  int index = 0;

  huffman_encode(root, buffer, &index);

  printf("Encoded message: ");
  for (int i = 0; buffer[i] != '\0'; i++) {
    printf("%c ", buffer[i]);
  }

  printf("\n");

  return 0;
}