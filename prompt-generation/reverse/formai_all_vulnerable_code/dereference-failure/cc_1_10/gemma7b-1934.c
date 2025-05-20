//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = malloc(sizeof(Calculator));
  calc->pos = 0;
  calc->result = 0.0;
  return calc;
}

void calculator_add(Calculator* calc, double num) {
  calc->result += num;
  sprintf(calc->buffer + calc->pos, "%lf", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
}

void calculator_sub(Calculator* calc, double num) {
  calc->result -= num;
  sprintf(calc->buffer + calc->pos, "%lf", -num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
}

void calculator_mul(Calculator* calc, double num) {
  calc->result *= num;
  sprintf(calc->buffer + calc->pos, "%lf", num);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
}

void calculator_div(Calculator* calc, double num) {
  if (num == 0) {
    printf("Error: division by zero is not allowed.\n");
    return;
  }
  calc->result /= num;
  sprintf(calc->buffer + calc->pos, "%lf", calc->result);
  calc->pos += strlen(calc->buffer + calc->pos) + 1;
}

void calculator_clear(Calculator* calc) {
  calc->result = 0.0;
  calc->pos = 0;
  memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

int main() {
  Calculator* calc = calculator_init();

  // Perform calculations
  calculator_add(calc, 10.0);
  calculator_sub(calc, 5.0);
  calculator_mul(calc, 2.0);
  calculator_div(calc, 4.0);

  // Display the result
  printf("The result is: %lf\n", calc->result);

  // Clear the calculator
  calculator_clear(calc);

  return 0;
}