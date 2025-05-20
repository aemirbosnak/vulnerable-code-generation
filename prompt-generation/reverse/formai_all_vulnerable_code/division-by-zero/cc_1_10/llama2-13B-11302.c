//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;
  char operation;

  // Generate some random numbers and operations
  srand(time(NULL));
  num1 = rand() % 100;
  num2 = rand() % 100;
  operation = '+';

  // Ask the user for the operation
  printf("Welcome to the random arithmetic game! Please enter the operation (+, -, x, /): ");
  scanf(" %c", &operation);

  // Perform the operation
  switch (operation) {
    case '+':
      sum = num1 + num2;
      break;
    case '-':
      difference = num1 - num2;
      break;
    case '*':
      product = num1 * num2;
      break;
    case '/':
      quotient = num1 / num2;
      remainder = num1 % num2;
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the results
  printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);
  printf("The result of %d %c %d is %d\n", num1, operation, num2, difference);
  printf("The result of %d %c %d is %d\n", num1, operation, num2, product);
  printf("The result of %d %c %d is %d\n", num1, operation, num2, quotient);
  printf("The result of %d %c %d is %d\n", num1, operation, num2, remainder);

  return 0;
}