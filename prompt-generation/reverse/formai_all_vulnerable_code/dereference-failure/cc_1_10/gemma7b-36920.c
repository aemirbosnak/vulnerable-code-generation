//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node {
  struct Node* left;
  struct Node* right;
  char data;
} Node;

void insert(Node* node, char data) {
  if (node == NULL) {
    node = malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
  } else if (data < node->data) {
    insert(node->left, data);
  } else {
    insert(node->right, data);
  }
}

void huffman_encode(Node* node, char* buffer, int index) {
  if (node != NULL) {
    huffman_encode(node->left, buffer, index);
    huffman_encode(node->right, buffer, index);

    buffer[index++] = node->data;
    buffer[index++] = (node->left) ? '1' : '0';
    buffer[index++] = (node->right) ? '1' : '0';
  }
}

int main() {
  Node* root = NULL;
  insert(root, 'a');
  insert(root, 'b');
  insert(root, 'c');
  insert(root, 'd');
  insert(root, 'e');

  char buffer[1024];
  int index = 0;
  huffman_encode(root, buffer, index);

  printf("%s", buffer);

  return 0;
}