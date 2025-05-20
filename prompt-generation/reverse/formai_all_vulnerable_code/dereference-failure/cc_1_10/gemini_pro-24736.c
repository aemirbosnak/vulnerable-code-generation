//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The syntax tree for our surrealist language
struct surreal_syntax_tree {
  char *type;
  struct surreal_syntax_tree *left;
  struct surreal_syntax_tree *right;
};

// The parser for our surrealist language
struct surreal_syntax_tree *surreal_parser(char *code) {
  // Split the code into tokens
  char **tokens = malloc(sizeof(char *) * 100);
  int num_tokens = 0;
  char *token = strtok(code, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Build the syntax tree
  struct surreal_syntax_tree *root = malloc(sizeof(struct surreal_syntax_tree));
  root->type = strndup(tokens[0], 1);
  if (num_tokens > 1) {
    root->left = surreal_parser(tokens + 1);
  }
  if (num_tokens > 2) {
    root->right = surreal_parser(tokens + 2);
  }

  return root;
}

// The interpreter for our surrealist language
void surreal_interpreter(struct surreal_syntax_tree *tree) {
  // Print the type of the syntax tree
  printf("%s\n", tree->type);

  // Recursively interpret the left and right subtrees
  if (tree->left != NULL) {
    surreal_interpreter(tree->left);
  }
  if (tree->right != NULL) {
    surreal_interpreter(tree->right);
  }
}

// The main function
int main() {
  // Get the code from the user
  char *code = malloc(sizeof(char) * 100);
  printf("Enter your surrealist code: ");
  scanf("%s", code);

  // Parse the code
  struct surreal_syntax_tree *tree = surreal_parser(code);

  // Interpret the code
  surreal_interpreter(tree);

  return 0;
}