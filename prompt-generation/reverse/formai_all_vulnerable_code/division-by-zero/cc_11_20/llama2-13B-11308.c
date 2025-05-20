//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT 100
#define MAX_NUMBER 1000

int main() {
  int input, num1, num2, sum, diff, mult, div, mod;
  char operation[5];
  char answer[5];
  char repeat;

  // Retro-style splash screen
  printf("Welcome to the Retro Calculator!\n");
  printf("======================================\n");
  printf("Type 'h' for help, 'q' to quit\n");
  printf("======================================\n\n");

  // Get the first number
  printf("Enter the first number: ");
  scanf("%d", &num1);

  // Get the second number
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Get the operation
  printf("Enter the operation (+, -, *, /, %): ");
  scanf(" %c", &operation[0]);

  // Perform the operation
  switch (operation[0]) {
    case '+':
      sum = num1 + num2;
      break;
    case '-':
      diff = num1 - num2;
      break;
    case '*':
      mult = num1 * num2;
      break;
    case '/':
      div = num1 / num2;
      break;
    case '%':
      mod = num1 % num2;
      break;
    default:
      printf("Invalid operation. Please try again.\n");
      return 1;
  }

  // Print the result
  sprintf(answer, "%d", sum);
  printf("Result: %s\n", answer);

  // Repeat?
  printf("Do you want to repeat the calculation? (y/n): ");
  scanf(" %c", &repeat);

  // Repeat the calculation if necessary
  if (repeat == 'y') {
    // Ask for the next numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask for the operation again
    printf("Enter the operation (+, -, *, /, %): ");
    scanf(" %c", &operation[0]);

    // Perform the operation again
    switch (operation[0]) {
      case '+':
        sum = num1 + num2;
        break;
      case '-':
        diff = num1 - num2;
        break;
      case '*':
        mult = num1 * num2;
        break;
      case '/':
        div = num1 / num2;
        break;
      case '%':
        mod = num1 % num2;
        break;
      default:
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    sprintf(answer, "%d", sum);
    printf("Result: %s\n", answer);
  }

  return 0;
}