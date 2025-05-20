//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->position = 0;
  calculator->result = 0.0;
  return calculator;
}

void calculator_add(Calculator* calculator, double number) {
  calculator->buffer[calculator->position++] = '+';
  calculator->buffer[calculator->position++] = (char)number;
}

void calculator_subtract(Calculator* calculator, double number) {
  calculator->buffer[calculator->position++] = '-';
  calculator->buffer[calculator->position++] = (char)number;
}

void calculator_multiply(Calculator* calculator, double number) {
  calculator->buffer[calculator->position++] = '*';
  calculator->buffer[calculator->position++] = (char)number;
}

void calculator_divide(Calculator* calculator, double number) {
  calculator->buffer[calculator->position++] = '/';
  calculator->buffer[calculator->position++] = (char)number;
}

double calculator_calculate(Calculator* calculator) {
  double result = 0.0;
  char* expression = calculator->buffer;
  int i = 0;
  for (; expression[i] != '\0'; i++) {
    switch (expression[i]) {
      case '+':
        result += (double)atof(expression[i + 1]);
        break;
      case '-':
        result -= (double)atof(expression[i + 1]);
        break;
      case '*':
        result *= (double)atof(expression[i + 1]);
        break;
      case '/':
        result /= (double)atof(expression[i + 1]);
        break;
    }
  }
  return result;
}

int main() {
  Calculator* calculator = calculator_init();
  calculator_add(calculator, 10.0);
  calculator_multiply(calculator, 2.0);
  calculator_divide(calculator, 4.0);
  calculator_subtract(calculator, 3.0);
  double result = calculator_calculate(calculator);
  printf("The result is: %.2lf\n", result);
  free(calculator);
  return 0;
}