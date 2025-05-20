//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double accumulator;
  double operand;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int index;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = malloc(sizeof(Calculator));
  calc->accumulator = 0.0;
  calc->operand = 0.0;
  calc->operator = '\0';
  calc->index = 0;

  return calc;
}

void calculator_add(Calculator* calc, double value) {
  calc->operand = value;
  calc->operator = '+';
}

void calculator_subtract(Calculator* calc, double value) {
  calc->operand = value;
  calc->operator = '-';
}

void calculator_multiply(Calculator* calc, double value) {
  calc->operand = value;
  calc->operator = '*';
}

void calculator_divide(Calculator* calc, double value) {
  calc->operand = value;
  calc->operator = '/';
}

double calculator_calculate(Calculator* calc) {
  switch (calc->operator) {
    case '+':
      return calc->accumulator + calc->operand;
    case '-':
      return calc->accumulator - calc->operand;
    case '*':
      return calc->accumulator * calc->operand;
    case '/':
      if (calc->operand == 0) {
        return -1;
      }
      return calc->accumulator / calc->operand;
    default:
      return -1;
  }
}

int main() {
  Calculator* calc = calculator_init();

  // Perform calculator operations
  calculator_add(calc, 10.0);
  calculator_multiply(calc, 2.0);
  calculator_divide(calc, 3.0);
  calculator_subtract(calc, 5.0);

  // Calculate the result
  double result = calculator_calculate(calc);

  // Print the result
  if (result != -1) {
    printf("The result is: %.2lf\n", result);
  } else {
    printf("Error: Invalid operation or division by zero.\n");
  }

  return 0;
}