//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: modular
// Math exercise program in a modular style

#include <stdio.h>

// Function to perform a math exercise
void do_math_exercise(int num1, int num2, int num3, char op) {
  int result = 0;

  switch (op) {
    case '+':
      result = num1 + num2 + num3;
      break;
    case '-':
      result = num1 - num2 - num3;
      break;
    case '*':
      result = num1 * num2 * num3;
      break;
    case '/':
      result = num1 / num2 / num3;
      break;
  }

  printf("The result of the math exercise is: %d\n", result);
}

// Function to generate a random math exercise
void generate_math_exercise(int *num1, int *num2, int *num3, char *op) {
  *num1 = rand() % 100;
  *num2 = rand() % 100;
  *num3 = rand() % 100;

  *op = rand() % 4;

  switch (*op) {
    case 0:
      *op = '+';
      break;
    case 1:
      *op = '-';
      break;
    case 2:
      *op = '*';
      break;
    case 3:
      *op = '/';
      break;
  }
}

// Main function
int main() {
  int num1, num2, num3;
  char op;

  generate_math_exercise(&num1, &num2, &num3, &op);

  do_math_exercise(num1, num2, num3, op);

  return 0;
}