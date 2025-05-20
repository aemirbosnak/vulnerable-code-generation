//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int num1, num2, sum;
  char op;

  printf("Welcome to the Retro Math Machine!\n");

  // Get the first number from the user
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Get the second number from the user
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Get the operation from the user
  printf("Enter the operation (+, -, *, /): ");
  scanf(" %c", &op);

  // Perform the operation
  if (op == '+') {
    sum = num1 + num2;
  } else if (op == '-') {
    sum = num1 - num2;
  } else if (op == '*') {
    sum = num1 * num2;
  } else if (op == '/') {
    sum = num1 / num2;
  } else {
    sum = -1;
  }

  // Print the result
  printf("The result of %d %s %d is %d\n", num1, op, num2, sum);

  // Add some retro flair
  printf("                    ____                   \n");
  printf("                   / ___|                   \n");
  printf("                / / _ |                   \n");
  printf("               /  | (_) |                   \n");
  printf("              /  |_____|                   \n");
  printf("             /____/                   \n");
  printf("                   %d", sum);

  return 0;
}