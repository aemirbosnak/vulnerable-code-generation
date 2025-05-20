//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *value;
  struct node *left;
  struct node *right;
} node;

node *new_node(char *value) {
  node *new = malloc(sizeof(node));
  new->value = value;
  new->left = NULL;
  new->right = NULL;
  return new;
}

node *parse_expression(char *input) {
  char *token = strtok(input, " ");
  if (token == NULL) {
    return NULL;
  }
  if (strcmp(token, "+") == 0) {
    node *left = parse_expression(NULL);
    node *right = parse_expression(NULL);
    return new_node("+");
  } else if (strcmp(token, "-") == 0) {
    node *left = parse_expression(NULL);
    node *right = parse_expression(NULL);
    return new_node("-");
  } else if (strcmp(token, "*") == 0) {
    node *left = parse_expression(NULL);
    node *right = parse_expression(NULL);
    return new_node("*");
  } else if (strcmp(token, "/") == 0) {
    node *left = parse_expression(NULL);
    node *right = parse_expression(NULL);
    return new_node("/");
  } else {
    return new_node(token);
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%s ", root->value);
  print_tree(root->left);
  print_tree(root->right);
}

int main() {
  char *input = "1 + 2 * 3 - 4 / 5";
  node *root = parse_expression(input);
  print_tree(root);
  printf("\n");
  return 0;
}