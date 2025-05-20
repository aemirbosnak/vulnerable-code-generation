//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Tree {
  Node* root;
  int size;
};

void insert(struct Tree* tree, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (tree->root == NULL) {
    tree->root = newNode;
  } else {
    insert(tree, data);
  }
  tree->size++;
}

void traverse(struct Tree* tree) {
  Node* current = tree->root;
  while (current) {
    printf("%d ", current->data);
    traverse(tree);
  }
}

int main() {
  struct Tree* tree = malloc(sizeof(struct Tree));
  tree->root = NULL;
  tree->size = 0;

  insert(tree, 10);
  insert(tree, 20);
  insert(tree, 30);
  insert(tree, 40);
  insert(tree, 50);

  traverse(tree);

  return 0;
}