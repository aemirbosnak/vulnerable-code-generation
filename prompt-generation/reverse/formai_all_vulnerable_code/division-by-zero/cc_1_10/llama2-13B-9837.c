//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum, product, quotient, remainder;
  char operation;
  char magic_word[10];

  printf("Welcome to the Scalable Arithmetic Program!\n");

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
    product = num1 * num2;
  } else if (operation == '/') {
    quotient = num1 / num2;
    remainder = num1 % num2;
  } else {
    printf("Invalid operation! Please try again...\n");
    return 1;
  }

  // Print the result
  printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

  // Generate a magic word based on the result
  sprintf(magic_word, "%d%c%d", sum, operation, num2);
  if (strstr(magic_word, "42") != NULL) {
    printf("Congratulations! You have found the secret magic number %d!", MAGIC_NUMBER);
  } else {
    printf("Too bad, the magic number is not here...\n");
  }

  return 0;
}