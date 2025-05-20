//LLAMA2-13B DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE 1
#define MAX_VALUE 1000

int main() {
  int num1, num2, sum, diff, mult, div, mod;
  char op;
  char str[MAX_LENGTH];
  char user_input[MAX_LENGTH];
  srand(time(NULL));

  printf("Welcome to the Dynamic C Programming Experiment! \n");

  while (1) {
    printf("Enter an operation (+, -, *, /, %): ");
    scanf(" %c", &op);

    if (op == '+') {
      printf("Enter two numbers: ");
      scanf(" %d%c%d", &num1, &op, &num2);
      sum = num1 + num2;
      printf("Sum: %d\n", sum);
    } else if (op == '-') {
      printf("Enter two numbers: ");
      scanf(" %d%c%d", &num1, &op, &num2);
      diff = num1 - num2;
      printf("Diff: %d\n", diff);
    } else if (op == '*') {
      printf("Enter two numbers: ");
      scanf(" %d%c%d", &num1, &op, &num2);
      mult = num1 * num2;
      printf("Product: %d\n", mult);
    } else if (op == '/') {
      printf("Enter two numbers: ");
      scanf(" %d%c%d", &num1, &op, &num2);
      if (num2 == 0) {
        printf("Error: cannot divide by zero!\n");
      } else {
        div = num1 / num2;
        printf("Division: %d\n", div);
      }
    } else if (op == '%') {
      printf("Enter two numbers: ");
      scanf(" %d%c%d", &num1, &op, &num2);
      mod = num1 % num2;
      printf("Modulus: %d\n", mod);
    } else {
      printf("Invalid operation. Please try again.\n");
    }
  }

  return 0;
}