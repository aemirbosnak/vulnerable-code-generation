//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: mathematical
// Mathematical Expression Parser

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to represent mathematical expressions
typedef struct {
  char *op;      // Operator (e.g. +, -, *, /)
  double lhs, rhs; // Left-hand side and right-hand side values
} expression;

// Function to parse a mathematical expression
expression parse_expression(char *str) {
  // Initialize the expression struct with invalid values
  expression exp = {0, 0, 0};

  // Tokenize the input string
  char *token = strtok(str, " ");
  while (token != NULL) {
    // Check if the token is a number
    if (sscanf(token, "%lf", &exp.rhs) == 1) {
      // If it is a number, set the left-hand side value
      exp.lhs = exp.rhs;
      token = strtok(NULL, " ");
    } else if (strcasecmp(token, "+") == 0 ||
               strcasecmp(token, "-") == 0 ||
               strcasecmp(token, "*") == 0 ||
               strcasecmp(token, "/") == 0) {
      // If it is an operator, set the operator and proceed
      exp.op = token;
      token = strtok(NULL, " ");
    } else {
      // If it is not a number or an operator, report an error
      printf("Invalid token: %s\n", token);
      return exp;
    }
  }

  // If we reached the end of the input without finding an operator,
  // report an error
  if (token == NULL) {
    printf("Missing operator\n");
    return exp;
  }

  return exp;
}

int main() {
  // Test cases
  expression exp1 = parse_expression("3 + 4");
  printf("1 + 4 = %f\n", exp1.rhs);

  exp1 = parse_expression("2 * 3");
  printf("2 * 3 = %f\n", exp1.rhs);

  exp1 = parse_expression("4 / 2");
  printf("4 / 2 = %f\n", exp1.rhs);

  exp1 = parse_expression("-3 + 2");
  printf("-3 + 2 = %f\n", exp1.rhs);

  return 0;
}