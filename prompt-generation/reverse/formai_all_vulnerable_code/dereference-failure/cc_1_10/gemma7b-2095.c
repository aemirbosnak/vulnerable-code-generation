//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  char operator;
  double result;
} Calculator;

Calculator* calculator_new() {
  Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
  calc->position = 0;
  calc->operator = '\0';
  calc->result = 0.0;
  return calc;
}

void calculator_append(Calculator* calc, char character) {
  if (calc->position >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[calc->position++] = character;
}

void calculator_set_operator(Calculator* calc, char operator) {
  calc->operator = operator;
}

double calculator_get_result(Calculator* calc) {
  return calc->result;
}

void calculator_clear(Calculator* calc) {
  calc->position = 0;
  calc->operator = '\0';
  calc->result = 0.0;
}

int main() {
  Calculator* calc = calculator_new();

  // Example usage
  calculator_append(calc, '5');
  calculator_append(calc, '2');
  calculator_append(calc, '+');
  calculator_append(calc, '3');
  calculator_append(calc, '=');

  double result = calculator_get_result(calc);
  printf("The result is: %.2lf", result);

  calculator_clear(calc);

  return 0;
}