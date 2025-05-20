//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -1000
#define MAX_VALUE 1000

// Function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the value of a given expression
double evaluate(char *expression) {
  double result = 0;
  char op;
  int num1, num2;

  // Tokenize the expression into operands and operators
  char tokens[MAX_LENGTH];
  int token_count = 0;
  char *token = strtok(expression, " ");
  while (token != NULL && token_count < MAX_LENGTH) {
    tokens[token_count++] = *token;
    token = strtok(NULL, " ");
  }

  // Parse the operands and operators
  op = tokens[0];
  num1 = atoi(tokens[1]);
  num2 = atoi(tokens[2]);

  // Perform the operation
  switch (op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator: %c\n", op);
      return 0;
  }

  return result;
}

int main() {
  // Get the expression from the user
  char expression[MAX_LENGTH];
  printf("Enter an expression: ");
  fgets(expression, MAX_LENGTH, stdin);

  // Evaluate the expression
  double result = evaluate(expression);

  // Print the result
  printf("Result: %f\n", result);

  return 0;
}