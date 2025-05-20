//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int index;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->index = 0;
  calculator->result = 0.0;
  return calculator;
}

void calculator_add(Calculator* calculator, double number) {
  sprintf(calculator->buffer + calculator->index, "%f", number);
  calculator->index += strlen(calculator->buffer + calculator->index) + 1;
  calculator->result += number;
}

void calculator_subtract(Calculator* calculator, double number) {
  sprintf(calculator->buffer + calculator->index, "%f", number);
  calculator->index += strlen(calculator->buffer + calculator->index) + 1;
  calculator->result -= number;
}

void calculator_multiply(Calculator* calculator, double number) {
  sprintf(calculator->buffer + calculator->index, "%f", number);
  calculator->index += strlen(calculator->buffer + calculator->index) + 1;
  calculator->result *= number;
}

void calculator_divide(Calculator* calculator, double number) {
  sprintf(calculator->buffer + calculator->index, "%f", number);
  calculator->index += strlen(calculator->buffer + calculator->index) + 1;
  calculator->result /= number;
}

double calculator_get_result(Calculator* calculator) {
  return calculator->result;
}

int main() {
  Calculator* calculator = calculator_init();

  // Perform calculations
  calculator_add(calculator, 10.0);
  calculator_multiply(calculator, 2.0);
  calculator_subtract(calculator, 5.0);
  calculator_divide(calculator, 2.0);

  // Get the result
  double result = calculator_get_result(calculator);

  // Print the result
  printf("The result is: %f", result);

  return 0;
}