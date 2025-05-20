//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int index;
  char operator;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = malloc(sizeof(Calculator));
  calc->index = 0;
  calc->operator = '\0';
  calc->result = 0.0;
  return calc;
}

void calculator_add(Calculator* calc, char operator, double number) {
  calc->buffer[calc->index++] = operator;
  calc->buffer[calc->index++] = '\0';
  calc->result += number;
}

void calculator_subtract(Calculator* calc, char operator, double number) {
  calc->buffer[calc->index++] = operator;
  calc->buffer[calc->index++] = '\0';
  calc->result -= number;
}

void calculator_multiply(Calculator* calc, char operator, double number) {
  calc->buffer[calc->index++] = operator;
  calc->buffer[calc->index++] = '\0';
  calc->result *= number;
}

void calculator_divide(Calculator* calc, char operator, double number) {
  calc->buffer[calc->index++] = operator;
  calc->buffer[calc->index++] = '\0';
  calc->result /= number;
}

void calculator_equal(Calculator* calc) {
  calc->buffer[calc->index++] = '=';
  calc->buffer[calc->index++] = '\0';
  printf("%s = %.2lf\n", calc->buffer, calc->result);
}

int main() {
  Calculator* calc = calculator_init();

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  char* token = strtok(input, " ");

  while (token) {
    double number = atof(token);
    char operator = token[0];

    switch (operator) {
      case '+':
        calculator_add(calc, operator, number);
        break;
      case '-':
        calculator_subtract(calc, operator, number);
        break;
      case '*':
        calculator_multiply(calc, operator, number);
        break;
      case '/':
        calculator_divide(calc, operator, number);
        break;
      case '=':
        calculator_equal(calc);
        break;
    }

    token = strtok(NULL, " ");
  }

  return 0;
}