//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a node in the syntax tree
typedef struct node {
  char *type;
  struct node *left;
  struct node *right;
} node;

// A function to create a new node
node *new_node(char *type) {
  node *n = malloc(sizeof(node));
  n->type = type;
  n->left = NULL;
  n->right = NULL;
  return n;
}

// A function to parse a string into a syntax tree
node *parse(char *s) {
  // Check if the string is empty
  if (*s == '\0') {
    return NULL;
  }

  // Check if the string is a single token
  if (strchr(s, ' ') == NULL) {
    return new_node(s);
  }

  // Split the string into two parts
  char *left = strtok(s, " ");
  char *right = strtok(NULL, " ");

  // Parse the left and right parts of the string
  node *left_node = parse(left);
  node *right_node = parse(right);

  // Create a new node for the operator
  node *n = new_node("operator");
  n->left = left_node;
  n->right = right_node;

  return n;
}

// A function to print the syntax tree
void print_tree(node *n) {
  // Check if the node is empty
  if (n == NULL) {
    return;
  }

  // Print the node's type
  printf("%s ", n->type);

  // Print the node's left and right children
  print_tree(n->left);
  print_tree(n->right);
}

// A function to free the syntax tree
void free_tree(node *n) {
  // Check if the node is empty
  if (n == NULL) {
    return;
  }

  // Free the node's left and right children
  free_tree(n->left);
  free_tree(n->right);

  // Free the node
  free(n);
}

// A function to test the parser
int main() {
  // Create a string to parse
  char *s = "1 + 2 * 3";

  // Parse the string into a syntax tree
  node *n = parse(s);

  // Print the syntax tree
  print_tree(n);

  // Free the syntax tree
  free_tree(n);

  return 0;
}