//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Knight {
  char name[50];
  struct Knight *left, *right;
} Knight;

Knight *insertKnight(Knight *node, char *name) {
  if (node == NULL) {
    node = (Knight *)malloc(sizeof(Knight));
    node->name[0] = '\0';
    node->left = NULL;
    node->right = NULL;
  }

  if (strcmp(name, node->name) < 0) {
    insertKnight(node->left, name);
  } else {
    insertKnight(node->right, name);
  }

  return node;
}

void traverseKnight(Knight *node) {
  printf("%s ", node->name);

  if (node->left) {
    traverseKnight(node->left);
  }

  if (node->right) {
    traverseKnight(node->right);
  }
}

int main() {
  Knight *root = NULL;
  insertKnight(root, "Sir Robin");
  insertKnight(root, "Sir William");
  insertKnight(root, "Sir Thomas");
  insertKnight(root, "Sir Gareth");
  insertKnight(root, "Sir John");

  traverseKnight(root);

  return 0;
}