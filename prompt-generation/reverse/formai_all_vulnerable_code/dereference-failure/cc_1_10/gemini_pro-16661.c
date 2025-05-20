//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *type;
  struct Node *left;
  struct Node *right;
} Node;

Node *parse(char *str) {
  if (!str || !*str) {
    return NULL;
  }

  char *type = strtok(str, " ");
  if (!type) {
    return NULL;
  }

  Node *node = malloc(sizeof(Node));
  if (!node) {
    return NULL;
  }

  node->type = strdup(type);
  node->left = parse(strtok(NULL, " "));
  node->right = parse(strtok(NULL, " "));

  return node;
}

void print(Node *node) {
  if (!node) {
    return;
  }

  printf("%s ", node->type);
  print(node->left);
  print(node->right);
}

void freeNode(Node *node) {
  if (!node) {
    return;
  }

  free(node->type);
  freeNode(node->left);
  freeNode(node->right);
  free(node);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    return 1;
  }

  Node *tree = parse(argv[1]);
  if (!tree) {
    printf("Error: Invalid expression\n");
    return 1;
  }

  print(tree);
  printf("\n");

  freeNode(tree);

  return 0;
}