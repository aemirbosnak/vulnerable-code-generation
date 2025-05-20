//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int type;
  char *value;
  struct Node *left;
  struct Node *right;
} Node;

Node *parse_expression(char *input) {
  if (*input == '(') {
    input++;  // skip '('
    Node *left = parse_expression(input);
    while (*input != ')') {
      if (*input == ' ') {
        input++;  // skip whitespace
        continue;
      }
      char op = *input++;  // get operator
      Node *right = parse_expression(input);
      Node *new_node = malloc(sizeof(Node));
      new_node->type = op;
      new_node->left = left;
      new_node->right = right;
      left = new_node;
    }
    input++;  // skip ')'
    return left;
  } else {
    int value = atoi(input);
    while (*input >= '0' && *input <= '9') {
      input++;  // skip digits
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->type = 'n';
    new_node->value = malloc(strlen(input) + 1);
    strcpy(new_node->value, input);
    return new_node;
  }
}

void print_expression(Node *node) {
  if (node->type == 'n') {
    printf("%s", node->value);
  } else {
    printf("(%c", node->type);
    print_expression(node->left);
    print_expression(node->right);
    printf(")");
  }
}

int main() {
  char input[] = "((1 + 2) * (3 - 4))";
  Node *expression = parse_expression(input);
  print_expression(expression);
  printf("\n");
  return 0;
}