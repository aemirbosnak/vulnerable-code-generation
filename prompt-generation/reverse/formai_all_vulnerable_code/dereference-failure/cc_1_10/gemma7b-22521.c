//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

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

void calculator_append(Calculator* calculator, char character) {
  if (calculator->position >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  calculator->buffer[calculator->position++] = character;
}

double calculator_evaluate(Calculator* calculator) {
  double value = 0.0;
  int i = 0;
  for (i = 0; i < calculator->position; i++) {
    switch (calculator->buffer[i]) {
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
        value = value * 10 + calculator->buffer[i] - '0';
        break;
      case '.':
        value = value + 0.1 * (calculator->buffer[i + 1] - '0');
        break;
      case '+':
        value = calculator->result + value;
        break;
      case '-':
        value = calculator->result - value;
        break;
      case '*':
        value = calculator->result * value;
        break;
      case '/':
        if (value == 0) {
          return 0;
        }
        value = calculator->result / value;
        break;
      default:
        return 0;
    }
  }

  calculator->result = value;
  return value;
}

int main() {
  Calculator* calculator = calculator_init();
  char input;

  printf("Enter an expression: ");
  while ((input = getchar()) != '\n') {
    calculator_append(calculator, input);
  }

  calculator_evaluate(calculator);

  printf("The result is: %.2lf\n", calculator->result);

  free(calculator);

  return 0;
}