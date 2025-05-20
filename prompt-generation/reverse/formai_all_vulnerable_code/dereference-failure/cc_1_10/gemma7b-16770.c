//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  float result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
  calc->top = -1;
  calc->result = 0.0f;
  return calc;
}

void calculator_push(Calculator* calc, char number) {
  if (calc->top >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calc->buffer[++calc->top] = number;
}

float calculator_pop(Calculator* calc) {
  if (calc->top < 0) {
    return -1.0f;
  }
  return (float)calc->buffer[calc->top--];
}

void calculator_operator(Calculator* calc, char operator) {
  float operand1 = calculator_pop(calc);
  float operand2 = calculator_pop(calc);
  switch (operator) {
    case '+':
      calc->result = operand1 + operand2;
      break;
    case '-':
      calc->result = operand1 - operand2;
      break;
    case '*':
      calc->result = operand1 * operand2;
      break;
    case '/':
      if (operand2 == 0) {
        return;
      }
      calc->result = operand1 / operand2;
      break;
  }
}

void calculator_clear(Calculator* calc) {
  calc->top = -1;
  calc->result = 0.0f;
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
        calculator_push(calc, input[i]);
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        calculator_operator(calc, input[i]);
        break;
      case 'C':
        calculator_clear(calc);
        break;
    }
  }

  printf("Result: %.2f\n", calc->result);

  return 0;
}