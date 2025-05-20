//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node** children;
} Node;

void insert(Node* node, int data) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->children = NULL;
  } else if (node->children == NULL) {
    node->children = (struct Node**)malloc(MAX * sizeof(struct Node));
    node->children[0] = (Node*)malloc(sizeof(Node));
    node->children[0]->data = data;
    node->children[0]->children = NULL;
  } else {
    int i = 0;
    for (i = 0; node->children[i] != NULL; i++) {
      if (node->children[i]->data == data) {
        return;
      }
    }
    node->children[i + 1] = (Node*)malloc(sizeof(Node));
    node->children[i + 1]->data = data;
    node->children[i + 1]->children = NULL;
  }
}

void traverse(Node* node) {
  printf("%d ", node->data);
  if (node->children) {
    for (int i = 0; node->children[i] != NULL; i++) {
      traverse(node->children[i]);
    }
  }
}

int main() {
  Node* root = NULL;
  insert(root, 10);
  insert(root, 20);
  insert(root, 30);
  insert(root, 40);
  insert(root, 50);

  traverse(root);

  return 0;
}