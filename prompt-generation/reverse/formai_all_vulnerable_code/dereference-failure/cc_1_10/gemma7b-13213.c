//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator_t {
  char buffer[MAX_BUFFER_SIZE];
  int index;
  char operator;
  double result;
} calculator_t;

calculator_t* calculator_init() {
  calculator_t* calculator = (calculator_t*)malloc(sizeof(calculator_t));
  calculator->index = 0;
  calculator->operator = '\0';
  calculator->result = 0.0;
  return calculator;
}

void calculator_add(calculator_t* calculator, double number) {
  calculator->buffer[calculator->index++] = number;
  calculator->operator = '+';
}

void calculator_subtract(calculator_t* calculator, double number) {
  calculator->buffer[calculator->index++] = number;
  calculator->operator = '-';
}

void calculator_multiply(calculator_t* calculator, double number) {
  calculator->buffer[calculator->index++] = number;
  calculator->operator = '*';
}

void calculator_divide(calculator_t* calculator, double number) {
  calculator->buffer[calculator->index++] = number;
  calculator->operator = '/';
}

double calculator_calculate(calculator_t* calculator) {
  double result = 0.0;
  switch (calculator->operator) {
    case '+':
      result = calculator->buffer[0] + calculator->buffer[1];
      break;
    case '-':
      result = calculator->buffer[0] - calculator->buffer[1];
      break;
    case '*':
      result = calculator->buffer[0] * calculator->buffer[1];
      break;
    case '/':
      if (calculator->buffer[1] == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return -1;
      }
      result = calculator->buffer[0] / calculator->buffer[1];
      break;
  }
  return result;
}

int main() {
  calculator_t* calculator = calculator_init();

  // Calculate the result of the expression "5 + 10 - 2 * 3 / 4"
  calculator_add(calculator, 5.0);
  calculator_add(calculator, 10.0);
  calculator_subtract(calculator, 2.0);
  calculator_multiply(calculator, 3.0);
  calculator_divide(calculator, 4.0);

  double result = calculator_calculate(calculator);

  if (result != -1) {
    printf("The result of the expression is: %.2lf\n", result);
  }

  free(calculator);

  return 0;
}