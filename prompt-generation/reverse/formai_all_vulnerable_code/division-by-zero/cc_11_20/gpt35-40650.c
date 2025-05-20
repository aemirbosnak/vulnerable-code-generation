//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
#include <stdio.h>

/*
 * This program is a magical calculator that can solve any math problem.
 * Simply input an equation and watch the magic happen!
 */

int main() {
  char equation[100];
  int result = 0;

  printf("Welcome to the magical calculator!\n");
  printf("Please enter an equation: ");

  fgets(equation, 100, stdin);

  // Let the magic begin!
  // First, we need to remove any spaces from the equation
  char clean_equation[100];
  int j = 0;

  for (int i = 0; equation[i]; i++) {
    if (equation[i] != ' ') {
      clean_equation[j++] = equation[i];
    }
  }

  clean_equation[j] = '\0';

  // Next, we need to parse the equation and solve it
  char op = ' ';
  int num = 0;

  for (int i = 0; clean_equation[i]; i++) {
    if (clean_equation[i] == '+' || clean_equation[i] == '-' ||
        clean_equation[i] == '*' || clean_equation[i] == '/') {
      if (op == ' ') {
        // This is the first operator, so we just store it and move on
        op = clean_equation[i];
        result = num;
        num = 0;
      } else {
        // We have an operator and a second number, so we calculate the result
        switch (op) {
          case '+':
            result += num;
            break;
          case '-':
            result -= num;
            break;
          case '*':
            result *= num;
            break;
          case '/':
            result /= num;
            break;
        }

        // Reset the variables for the next iteration
        op = clean_equation[i];
        num = 0;
      }
    } else {
      // This is a digit, so we add it to the current number
      num = num * 10 + (clean_equation[i] - '0');
    }
  }

  // Calculate the final result
  switch (op) {
    case '+':
      result += num;
      break;
    case '-':
      result -= num;
      break;
    case '*':
      result *= num;
      break;
    case '/':
      result /= num;
      break;
  }

  // Output the result
  printf("The answer is: %d\n", result);

  return 0;
}