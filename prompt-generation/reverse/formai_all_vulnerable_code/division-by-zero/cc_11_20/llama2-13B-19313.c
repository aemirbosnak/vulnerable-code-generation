//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER 1

int main() {
  int num1, num2, sum;
  char operation;

  // Initialize variables
  num1 = 0;
  num2 = 0;
  sum = 0;
  operation = '+';

  // Get the first number from the user
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Get the second number from the user
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Get the operation from the user
  printf("Enter the operation (+, -, *, /): ");
  scanf(" %c", &operation);

  // Perform the operation
  if (operation == '+') {
    sum = num1 + num2;
  } else if (operation == '-') {
    sum = num1 - num2;
  } else if (operation == '*') {
    sum = num1 * num2;
  } else if (operation == '/') {
    sum = num1 / num2;
  }

  // Print the result
  printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

  // Get the result from the user again
  printf("Do you want to try again? (y/n): ");
  scanf(" %c", &operation);

  // Loop until the user says no
  while (operation == 'y' || operation == 'Y') {
    // Repeat the operation
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
      sum = num1 + num2;
    } else if (operation == '-') {
      sum = num1 - num2;
    } else if (operation == '*') {
      sum = num1 * num2;
    } else if (operation == '/') {
      sum = num1 / num2;
    }

    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);
  }

  return 0;
}