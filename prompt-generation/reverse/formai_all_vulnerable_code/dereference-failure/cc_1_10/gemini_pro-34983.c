//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A simple syntax tree node
typedef struct node {
  int type;
  union {
    int value;
    struct node *left, *right;
  };
} node;

// Parse an expression
node *parse_expr(char *str) {
  node *n = malloc(sizeof(node));
  if (str[0] >= '0' && str[0] <= '9') {
    n->type = 0;
    n->value = atoi(str);
  } else {
    n->type = 1;
    n->left = parse_expr(str + 1);
    n->right = parse_expr(str + 2);
  }
  return n;
}

// Evaluate an expression
int eval_expr(node *n) {
  if (n->type == 0) {
    return n->value;
  } else {
    switch (n->left->type) {
      case 0:
        return n->left->value + eval_expr(n->right);
      case 1:
        return n->left->value - eval_expr(n->right);
      default:
        return 0;
    }
  }
}

// Print an expression
void print_expr(node *n) {
  if (n->type == 0) {
    printf("%d", n->value);
  } else {
    printf("(%c", n->left->type ? '-' : '+');
    print_expr(n->left);
    printf(" %c", n->right->type ? '-' : '+');
    print_expr(n->right);
    printf(")");
  }
}

int main() {
  char *expr = "1+2-3";
  node *n = parse_expr(expr);
  print_expr(n);
  printf(" = %d\n", eval_expr(n));
  return 0;
}