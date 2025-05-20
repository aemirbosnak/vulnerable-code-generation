//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

// Define a custom data structure for storing arithmetic expressions.
typedef struct Expression {
  char operator;
  struct Expression *left;
  struct Expression *right;
} Expression;

// Create a new expression node.
Expression *new_expression(char operator, Expression *left, Expression *right) {
  Expression *expr = malloc(sizeof(Expression));
  expr->operator = operator;
  expr->left = left;
  expr->right = right;
  return expr;
}

// Evaluate an arithmetic expression.
int evaluate(Expression *expr) {
  switch (expr->operator) {
    case '+':
      return evaluate(expr->left) + evaluate(expr->right);
    case '-':
      return evaluate(expr->left) - evaluate(expr->right);
    case '*':
      return evaluate(expr->left) * evaluate(expr->right);
    case '/':
      return evaluate(expr->left) / evaluate(expr->right);
    default:
      return atoi(expr->operator);
  }
}

// Print an arithmetic expression in infix notation.
void print_infix(Expression *expr) {
  if (expr->left) {
    printf("(");
    print_infix(expr->left);
    printf(") ");
  }
  printf("%c ", expr->operator);
  if (expr->right) {
    printf("(");
    print_infix(expr->right);
    printf(")");
  }
}

// Print an arithmetic expression in postfix notation.
void print_postfix(Expression *expr) {
  if (expr->left) {
    print_postfix(expr->left);
  }
  if (expr->right) {
    print_postfix(expr->right);
  }
  printf("%c ", expr->operator);
}

// Print an arithmetic expression in prefix notation.
void print_prefix(Expression *expr) {
  printf("%c ", expr->operator);
  if (expr->left) {
    print_prefix(expr->left);
  }
  if (expr->right) {
    print_prefix(expr->right);
  }
}

// Free the memory allocated for an expression.
void free_expression(Expression *expr) {
  if (expr->left) {
    free_expression(expr->left);
  }
  if (expr->right) {
    free_expression(expr->right);
  }
  free(expr);
}

// Main function.
int main() {
  // Create an arithmetic expression tree.
  Expression *expr = new_expression('+',
    new_expression('*', new_expression('2', NULL, NULL), new_expression('3', NULL, NULL)),
    new_expression('-', new_expression('4', NULL, NULL), new_expression('5', NULL, NULL)));

  // Evaluate the expression.
  int result = evaluate(expr);

  // Print the expression in different notations.
  printf("Infix: ");
  print_infix(expr);
  printf("\n");
  printf("Postfix: ");
  print_postfix(expr);
  printf("\n");
  printf("Prefix: ");
  print_prefix(expr);
  printf("\n");

  // Free the memory allocated for the expression.
  free_expression(expr);

  return 0;
}