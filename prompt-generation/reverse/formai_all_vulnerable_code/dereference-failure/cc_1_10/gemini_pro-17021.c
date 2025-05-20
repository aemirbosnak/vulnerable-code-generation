//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to perform a basic arithmetic operation
int arithmetic_operation(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return 0;
  }
}

// Function to generate a random arithmetic expression
char *rand_expression(int max_length) {
  int length = rand_int(1, max_length);
  char *expression = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int type = rand_int(0, 2);
    if (type == 0) {
      expression[i] = rand_int('0', '9');
    } else if (type == 1) {
      expression[i] = rand_int('a', 'z');
    } else {
      expression[i] = rand_int('+', '/');
    }
  }
  expression[length] = '\0';
  return expression;
}

// Function to evaluate a given arithmetic expression
int evaluate_expression(char *expression) {
  int stack[100];
  int top = -1;
  for (int i = 0; expression[i] != '\0'; i++) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      stack[++top] = expression[i] - '0';
    } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
      int op1 = stack[top--];
      int op2 = stack[top--];
      int result = arithmetic_operation(op1, op2, expression[i]);
      stack[++top] = result;
    }
  }
  return stack[top];
}

// Driver function
int main() {
  int max_length = 100;
  char *expression = rand_expression(max_length);
  printf("Generated Expression: %s\n", expression);
  int result = evaluate_expression(expression);
  printf("Result: %d\n", result);
  free(expression);
  return 0;
}