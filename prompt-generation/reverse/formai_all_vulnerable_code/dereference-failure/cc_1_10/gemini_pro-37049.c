//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char* value;
  struct Node* left;
  struct Node* right;
} Node;

Node* parse(char* input) {
  if (!input) {
    return NULL;
  }

  Node* root = malloc(sizeof(Node));
  root->value = strtok(input, " ");
  root->left = parse(strtok(NULL, " "));
  root->right = parse(strtok(NULL, " "));

  return root;
}

void print_tree(Node* root) {
  if (!root) {
    return;
  }

  printf("%s ", root->value);
  print_tree(root->left);
  print_tree(root->right);
}

void free_tree(Node* root) {
  if (!root) {
    return;
  }

  free(root->value);
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  char* input = "Hello World!";
  Node* root = parse(input);

  print_tree(root);
  printf("\n");

  free_tree(root);

  return 0;
}