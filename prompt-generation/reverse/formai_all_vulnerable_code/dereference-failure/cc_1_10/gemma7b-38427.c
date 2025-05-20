//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 255

typedef struct Calculator {
  double result;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
  int operatorStack[10];
  int operatorStackTop;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = malloc(sizeof(Calculator));
  calc->result = 0;
  calc->bufferIndex = 0;
  calc->operatorStackTop = -1;
  return calc;
}

void calculator_add(Calculator* calc, double number) {
  calc->buffer[calc->bufferIndex++] = number;
  calc->result += number;
}

void calculator_sub(Calculator* calc, double number) {
  calc->buffer[calc->bufferIndex++] = number;
  calc->result -= number;
}

void calculator_multiply(Calculator* calc, double number) {
  calc->buffer[calc->bufferIndex++] = number;
  calc->result *= number;
}

void calculator_divide(Calculator* calc, double number) {
  calc->buffer[calc->bufferIndex++] = number;
  calc->result /= number;
}

void calculator_operator(Calculator* calc, char operator) {
  calc->operatorStack[++calc->operatorStackTop] = operator;
}

double calculator_calculate(Calculator* calc) {
  double result = 0;
  for (int i = 0; i < calc->bufferIndex; i++) {
    double number = calc->buffer[i] - '0';
    switch (calc->operatorStack[calc->operatorStackTop]) {
      case '+':
        result += number;
        break;
      case '-':
        result -= number;
        break;
      case '*':
        result *= number;
        break;
      case '/':
        result /= number;
        break;
    }
  }
  return result;
}

int main() {
  Calculator* calc = calculator_init();
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        calculator_add(calc, input[i] - '0');
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        calculator_operator(calc, input[i]);
        break;
    }
  }

  double result = calculator_calculate(calc);
  printf("The result is: %.2lf\n", result);

  free(calc);

  return 0;
}